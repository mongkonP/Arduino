//////////////////////////////////////////////////////////////////////////
// Author: RSP @ Embedded System Lab (ESL), KMUTNB, Thailand
// File: ds3231.cpp
// Last Modified: 2014-10-05
// Note: This C++ class provides an API for communicating with
//       the DS3231-based RTC module via the I2C bus.
//////////////////////////////////////////////////////////////////////////

#include "DS3231.h"

using namespace esl;

////////////////////////////////////////////////////////////////////////
#define REG_SEC          (0x00)
#define REG_MIN          (0x01)
#define REG_HOUR         (0x02)
#define REG_DAY          (0x03)
#define REG_DATE         (0x04)
#define REG_MONTH        (0x05)
#define REG_YEAR         (0x06)
#define REG_ALM1_SEC     (0x07)
#define REG_ALM1_MIN     (0x08)
#define REG_ALM1_HOUR    (0x09)
#define REG_ALM1_DAYDATE (0x0A)
#define REG_ALM2_MIN     (0x0B)
#define REG_ALM2_HOUR    (0x0C)
#define REG_ALM2_DAYDATE (0x0D)
#define REG_CTRL         (0x0E)
#define REG_STATUS       (0x0F)
#define REG_AGING_OFFSET (0x10)
#define REG_TEMP_MSB     (0x11)
#define REG_TEMP_LSB     (0x12)
#define SRAM_START_ADDR  (0x14)  

const uint8_t DS3231::I2C_ADDR_DEFAULT = 0x68;

DS3231::DS3231( uint8_t addr ) : i2c_addr( addr ) {
  digitalWrite( SDA, 0 ); // disable pull-up on SDA
  digitalWrite( SCL, 0 ); // disable pull-up on SCL
}

void DS3231::setDeviceAddress( uint8_t addr ) {
  i2c_addr = addr;
}

uint8_t DS3231::getDeviceAddress() {
  return i2c_addr;
}

void DS3231::init( boolean fast_speed ) {
  uint16_t value;
  digitalWrite( SDA, 0 ); // disable pull-up on SDA
  digitalWrite( SCL, 0 ); // dsiable pull-up on SCL
  if ( fast_speed ) {
     // f_CPU / ((16 + (2*TWBR)) * TWSR) = f_SCL
     TWBR = 12; // use 400kHz instead of 100kHz
  }
  delay(1);
}

// convert BCD to Decimal 
uint8_t DS3231::bcd2dec( uint8_t bcd ) {
  return 10*((bcd >> 4) & 0x0f) + (bcd & 0x0f);
}

// convert Decimal to BCD
uint8_t DS3231::dec2bcd( uint8_t dec ) {
  return ((dec/10) << 4) | (dec%10);
}

// convert Datetime to array of bytes
void DS3231::dt2arr( const Datetime& dt, uint8_t *buf ) {
  buf[0] = dec2bcd(dt.sec);
  buf[1] = dec2bcd(dt.min); 
  buf[2] = dec2bcd(dt.hour); 
  buf[3] = dec2bcd(dt.wday); 
  buf[4] = dec2bcd(dt.mday); 
  buf[5] = dec2bcd(dt.mon); 
  buf[6] = dec2bcd(dt.year-2000); 
}

// convert array of bytes to Datetime
void DS3231::arr2dt( const uint8_t *buf, Datetime& dt ) {
  uint8_t data;
  dt.sec = bcd2dec( buf[0] );
  dt.min = bcd2dec( buf[1] );
  data = buf[2];
  if ( data & 0x40 ) { // 12-format
    dt.hour = bcd2dec( data & 0x1f );
    if ( data & 0x20 ) {
      dt.hour += 12;
    }
  } else { // 24-format
    dt.hour = bcd2dec( data & 0x3f );
  }
  dt.wday = bcd2dec( buf[3] );
  dt.mday = bcd2dec( buf[4] );
  dt.mon  = bcd2dec( buf[5] & 0x1f );
  dt.year = 2000 + bcd2dec(buf[6]) + 100*((buf[5] >> 7) & 1) /* century overflow */;
}

void DS3231::i2c_write_bytes( const uint8_t *buf, uint8_t reg_addr, uint8_t len ) {
  Wire.beginTransmission( i2c_addr );
  Wire.write( reg_addr );
  for (int i=0; i < len; i++ ) {
     Wire.write( buf[i] );
  } 
  Wire.endTransmission();
}

void DS3231::i2c_read_bytes( uint8_t *buf, uint8_t reg_addr, uint8_t len ) {
  Wire.beginTransmission( i2c_addr );
  Wire.write( reg_addr ); 
  Wire.endTransmission();
  //delayMicroseconds(10);
  //Wire.beginTransmission( DS3231_ADDR );
  Wire.requestFrom( (uint16_t)i2c_addr, len ); 
  while ( Wire.available() < len ) ; // waiting 
  uint8_t index=0;
  for ( int i=0; i < len; i++ ) {
     buf[index++] = Wire.read();
  }
  Wire.endTransmission();  
}

void DS3231::readDatetime( Datetime& dt ) {
  uint8_t buf[7];
  i2c_read_bytes( buf, REG_SEC, 7 );
  arr2dt( buf, dt );
}

void DS3231::writeDatetime( const Datetime& dt ) {
  uint8_t buf[7];
  dt2arr( dt, buf );
  i2c_write_bytes( buf, REG_SEC, 7 );
}

#define SQW_1HZ     (0 << 3)
#define SQW_1024HZ  (1 << 3)
#define SQW_4096HZ  (2 << 3)
#define SQW_8192HZ  (3 << 3)

void DS3231::squareware( OutputFrequency freq ) {
  uint8_t value;
  i2c_read_bytes( &value, REG_CTRL, 1 );
  if ( freq != SQW_NONE ) {
     value &= ~(1 << 2); // clear INTCN bit (disable interrupt)
     value &= ~(3 << 3); // clear RS2 and RS1 bits -> 1Hz
     value |= freq;
  } else {
     value |= (1 << 2); // set INTCN bit 
  }
  i2c_write_bytes( &value, REG_CTRL, 1 );
}

float DS3231::readTemperature( ) {
  uint8_t data[2];
  i2c_read_bytes( data, REG_TEMP_MSB, 2 );
  uint16_t t = data[0];
  t = (t << 8) | data[1];
  return (((int16_t)t) >> 6)*0.25;
}

void DS3231::disableAlarms() {
   uint8_t value;
   i2c_read_bytes( &value, REG_CTRL, 1 );
   value &= 0b11111000; // clear A2IE and A1IE bits (disable both Alarm2 and Alarm1)
                        // and clear INTCN bit (disable interrupt)
   i2c_write_bytes( &value, REG_CTRL, 1 );
   i2c_read_bytes( &value, REG_STATUS, 1 );
   value &= 0b11111100; // clear both A2F and A1F flags
   i2c_write_bytes( &value, REG_STATUS, 1 ); 
}

void DS3231::clearAlarmFlags() {
   uint8_t value;
   i2c_read_bytes( &value, REG_STATUS, 1 );
   value &= 0b11111100; // clear both A2F and A1F flags
   i2c_write_bytes( &value, REG_STATUS, 1 ); 
}

void DS3231::enableAlarm( uint8_t alarm_type, const Datetime& dt ) {
   uint8_t value, buf[4];
   clearAlarmFlags();
   buf[0] = dec2bcd( dt.sec )  | ((alarm_type & 0x01) ? (1<<7) : 0);
   buf[1] = dec2bcd( dt.min )  | ((alarm_type & 0x02) ? (1<<7) : 0); 
   buf[2] = dec2bcd( dt.hour ) | ((alarm_type & 0x04) ? (1<<7) : 0); 
   if ( alarm_type & 0x10 ) {
     buf[3] = dec2bcd( dt.wday ) | (1<<6) // use day of week 
            | ((alarm_type & 0x08) ? (1<<7) : 0);
   } else {
     buf[3] = dec2bcd( dt.mday ) // use date of month 
            | ((alarm_type & 0x08) ? (1<<7) : 0);
   }
   i2c_read_bytes( &value, REG_CTRL, 1 );
   if ( alarm_type & 0x80 ) { // alarm 2
     i2c_write_bytes( &buf[1], REG_ALM2_MIN, 3 );
     value |= (1 << 1); // set A2IE bit (enable Alarm2 interrupt)
   } else { // alarm 1
     i2c_write_bytes( &buf[0], REG_ALM1_SEC, 4 );
     value |= (1 << 0); // set A1IE bit (enable Alarm1 interrupt)
   }
   value |= (1 << 2); // set INTCN bit 
   i2c_write_bytes( &value, REG_CTRL, 1 );
}
//////////////////////////////////////////////////////////////////////////


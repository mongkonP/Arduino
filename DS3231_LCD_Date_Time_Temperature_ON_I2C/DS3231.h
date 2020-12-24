//////////////////////////////////////////////////////////////////////////
// Author: RSP @ Embedded System Lab (ESL), KMUTNB, Thailand
// File: ds3231.h
// Last Modified: 2014-10-05
// Note: This C++ class provides an API for communicating with
//       the DS3231-based RTC module via the I2C bus.
//////////////////////////////////////////////////////////////////////////

#ifndef __DS3231_H
#define __DS3231_H

#include <Arduino.h>
#include <Wire.h>

namespace esl {

  typedef struct datetime_t {
    uint8_t sec;     // the number of seconds: 0..59
    uint8_t min;     // the number of minutes: 0..59
    uint8_t hour;    // the number of hours past midnight: 0..23
    uint8_t wday;    // the day of week: 1..7 (1=Sunday, 2=Monday..., 7=Saturday)
    uint8_t mday;    // the day of month: 1..31
    uint8_t mon;     // the number of months: 1..12 
    uint16_t year;   // the number of years (>= 2000) e.g. 2014
  } Datetime;
  
  class DS3231 {
     public:

       typedef enum {
          ALARM_ONCE_PER_SEC               = 0b00001111,
          ALARM_SEC_MATCH                  = 0b00001110,
          ALARM_MIN_SEC_MATCH              = 0b00001100,
          ALARM_DATE_HOUR_MINUTE_SEC_MATCH = 0b00001000,
          ALARM_DAY_HOUR_MINUTE_SEC_MATCH  = 0b00010000,
          ALARM_ONCE_PER_MINUTE            = 0b10001110,
          ALARM_MINUTE_MATCH               = 0b10001100,
          ALARM_HOUR_MINUTE_MATCH          = 0b10001000,
          ALARM_DATE_HOUR_MINUTE_MATCH     = 0b10000000,
          ALARM_DAY_HOUR_MINUTE_MATCH      = 0b10010000
       } AlarmType;
       
       typedef enum {
          SQW_NONE   = 0xff,
          SQW_1HZ    = (0 << 3),
          SQW_1024HZ = (1 << 3),
          SQW_4096HZ = (2 << 3),
          SQW_8192HZ = (3 << 3)
       } OutputFrequency;

       DS3231( uint8_t addr = I2C_ADDR_DEFAULT );
       void init( boolean fast_speed=true );
       void setDeviceAddress( uint8_t addr );
       uint8_t getDeviceAddress();
       void readDatetime( Datetime& dt );
       void writeDatetime( const Datetime& dt );
       void squareware( OutputFrequency freq );
       float readTemperature();
       void enableAlarm( uint8_t alarm_type, const Datetime& dt );
       void disableAlarms();
       void clearAlarmFlags();
       
     private:
       static const uint8_t I2C_ADDR_DEFAULT;
       uint8_t i2c_addr;
       void i2c_write_bytes( const uint8_t *buf, uint8_t reg_addr, uint8_t len );
       void i2c_read_bytes( uint8_t *buf, uint8_t reg_addr, uint8_t len );
       uint8_t bcd2dec( uint8_t bcd );
       uint8_t dec2bcd( uint8_t dec );
       void dt2arr( const Datetime& dt, uint8_t *buf );
       void arr2dt( const uint8_t *buf, Datetime& dt );
  }; // end class
} // end namespace

#endif // __DS3231_H

//////////////////////////////////////////////////////////////////////////



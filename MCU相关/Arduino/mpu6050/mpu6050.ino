#include <EEPROM.h>
#include <Wire.h>
/***************MPU6050变量定义**********************/
double accX, accY, accZ;
double gyroY, gyroZ;
double compAngleY, gyroYangle;
int16_t tempRaw;
uint32_t timer;
uint8_t i2cData[14];

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

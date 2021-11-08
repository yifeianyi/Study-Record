/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // 存储伺服电机角度信息

void setup() {
  myservo.attach(9);  // Servo对象链接的引脚号，这里是9
}

void loop() {
  for (pos = 0; pos <= 180; pos += 45) { // 0到180度
    // 每一步增加一步
    myservo.write(pos);              // 令伺服电机达到pos指定的角度
    delay(1500);                       // waits 15ms for the servo to reach the position
  }
  //逆时针旋转
  for (pos = 180; pos >= 0; pos -= 45) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1500);                       // waits 15ms for the servo to reach the position
  }
}

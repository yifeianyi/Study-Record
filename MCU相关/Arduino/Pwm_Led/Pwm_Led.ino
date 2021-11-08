int Led = 6;
int Button = 3;
int LedState = 1;
int LedPwm = 0;
void setup() {
  // put your setup code here, to run once:
    pinMode(Button,INPUT);
    Serial.begin(9600);//设置串口波特率
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(LedPwm);
  int ButtonState = digitalRead(Button);
  
  if(!ButtonState){
    LedPwm++;
    LedPwm%=256;
   }
   analogWrite(Led,LedPwm);
   delay(30);
  
}

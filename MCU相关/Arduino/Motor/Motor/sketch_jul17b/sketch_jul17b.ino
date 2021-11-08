/********************************************
 *  AIN1 = 9
 *  AIN2 = 10
 *********************************************/
 int AIN1 = 9;
 int AIN2 = 10;
 int ENA = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(AIN2,HIGH);
  digitalWrite(AIN1,LOW);
  analogWrite(ENA,255);
    
}

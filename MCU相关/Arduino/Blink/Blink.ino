int Led = 6;
int Button = 3;
int LedState = 1;
void setup() {
  // put your setup code here, to run once:
//  pinMode(Led, OUTPUT);
  pinMode(Button,INPUT);
  Serial.begin(9600);//设置串口波特率
}

void loop() {
//  // put your main code here, to run repeatedly:
  int ButtonState = digitalRead(Button);
  
  Serial.println(ButtonState);
//  delay(300);
  if(!ButtonState){
    LedState = !LedState;   
   }
   digitalWrite(Led,LedState);
//   else digitalWrite(Led,LOW); 
//  
//  
//  delay(1000);                       
//  digitalWrite(Led,LOW);    
//  delay(1000);
}

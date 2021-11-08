int IN1 = 9;
int IN2 = 10;
int ctrlVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ctrlVal = Serial.parseInt();
  analogWrite(pinNum, ctrlVal);
  Serial.print("Set Value ");
  Serial.print(ctrlVal);
  Serial.println(".");          
   
}

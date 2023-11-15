void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(PA5,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int a=analogRead(PA5);
//delay(200);
Serial.println(a);
}

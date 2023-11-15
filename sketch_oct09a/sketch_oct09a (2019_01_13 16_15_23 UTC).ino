void setup() {
for (int i=3 ;i<10;i++)  // put your setup code here, to run once:
pinMode(i,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=3 ;i<10;i++)
digitalWrite(i,HIGH);
}

#define trig PB13
#define mdl_echo PB10


#include<NewPing.h>

NewPing sonar(trig,mdl_echo);


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {

  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
  // put your main code here, to run repeatedly:

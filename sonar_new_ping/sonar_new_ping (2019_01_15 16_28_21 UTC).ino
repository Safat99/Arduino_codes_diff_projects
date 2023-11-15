#define trig PB13
#define echo PB10


#include<NewPing.h>
NewPing sonar(trig,echo);
int dist;

 
void setup() {
//   afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
delay(100);
dist=sonar.ping_cm();
Serial.println(dist);

//digitalWrite(echo,1);
}

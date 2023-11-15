#define trig PB13
#define mdl_echo PB10
#define lft_echo PB11
#define rht_echo PA15


#include<NewPing.h>
NewPing mdl_sonar(trig,mdl_echo);
NewPing lft_sonar(trig,lft_echo);
NewPing rht_sonar(trig,rht_echo);
int dist1,dist2,dist3;

 
void setup() {
//   afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(mdl_echo,INPUT);
pinMode(lft_echo,INPUT);
pinMode(rht_echo,INPUT);

}

void loop() {
delay(100);
dist1=mdl_sonar.ping_cm();
dist2=lft_sonar.ping_cm();
dist3=rht_sonar.ping_cm();
Serial.print(dist1);
Serial.print("\t\t");
Serial.print(dist2);
Serial.print("\t\t");
Serial.print(dist3);
Serial.println();

//digitalWrite(echo,1);
}

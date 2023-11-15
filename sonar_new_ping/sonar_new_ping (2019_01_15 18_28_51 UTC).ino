#define trig PB13
#define mdl_echo PB10
#define lft_echo PB11
#define rht_echo PA15


#include<NewPing.h>

NewPing sonar[3]={ NewPing(trig,mdl_echo), NewPing(trig,lft_echo), NewPing(trig,rht_echo)};
//NewPing mdl_sonar(trig,mdl_echo);
//NewPing lft_sonar(trig,lft_echo);
//NewPing rht_sonar(trig,rht_echo);
int dist[3];

void setup() {
//   afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  // put your setup code here, to run once:
Serial.begin(115200);
//pinMode(trig,OUTPUT);
//pinMode(mdl_echo,INPUT);
//pinMode(lft_echo,INPUT);
//pinMode(rht_echo,INPUT);

}


void sonar_activate(){
delay(100);
for (int i=0;i<3;i++){
dist[i]=sonar[i].ping_cm();
delay(50);

Serial.print(dist[i]);
Serial.print("\t\t");
}

Serial.println();
}

void loop() {
//delay(100);
//for (int i=0;i<3;i++){
//dist=sonar[i].ping_cm();
//delay(50);
////dist1=mdl_sonar.ping_cm();
////dist2=lft_sonar.ping_cm();
////dist3=rht_sonar.ping_cm();
//
//Serial.print(dist);
//Serial.print("\t\t");
//}

//Serial.println();
//Serial.print(Sonar[1]);
//Serial.print("\t\t");
//Serial.print(Sonar[2]);

//digitalWrite(echo,1);
sonar_activate();
}

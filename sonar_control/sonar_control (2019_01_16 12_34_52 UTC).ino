#define trig PB13
#define mdl_echo PB10
#define lft_echo PB11
#define rht_echo PA15


#define LM1 PB4     //here>>portion A is left....portion B is right
#define LM2 PB3
#define RM1 PB7
#define RM2 PB6
#define LMPWM PB9
#define RMPWM PB8
#define STBY PB5

//LED pin
#define lft_led PB15
#define rht_led PA8



#include<NewPing.h>

NewPing sonar[3]={ NewPing(trig,mdl_echo), NewPing(trig,lft_echo), NewPing(trig,rht_echo)};
\
int dist[3];
int diff;

void setup() {
//   afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  // put your setup code here, to run once:

 afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  Serial.begin(9600);
  pin_declare();
  digitalWrite(STBY, HIGH);

//Serial.begin(115200);
//pinMode(trig,OUTPUT);
//pinMode(mdl_echo,INPUT);
//pinMode(lft_echo,INPUT);
//pinMode(rht_echo,INPUT);

}


void sonar_activate(){
//delay(100);
for (int i=0;i<3;i++){
dist[i]=sonar[i].ping_cm();
delay(20);

Serial.print(dist[i]);
Serial.print("\t\t");
}

  diff = dist[1] - dist [2];
Serial.println();
}

void pin_declare(){
//Motor Pin
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LMPWM,OUTPUT);
  pinMode(RMPWM,OUTPUT);
  pinMode(STBY,OUTPUT);
//LED Pin
  pinMode(lft_led,OUTPUT);
  pinMode(rht_led,OUTPUT);
}


void motor_control(int lft_speed, int rht_speed){
  if(lft_speed>=0){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(LMPWM, lft_speed);  
  }
  else{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  analogWrite(LMPWM, -1*lft_speed);    
  }

  if(rht_speed>=0){
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(RMPWM, rht_speed);  
  }
  else{
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  analogWrite(RMPWM, -1*rht_speed);    
  }  
}

void loop() {
  sonar_activate();
  while(1){
    sonar_activate();
    sonar_track();
    if(dist[0]>=3 && dist[0]<=15){
      break;
    }
  }
//  else{
    motor_control(0, 0);
    delay( 3000);
//  }

}

void sonar_track(){
  if (diff == 0)
     motor_control(100,100);
 else if (diff>= 1 &&  diff <= 3 )
     motor_control(70,100);
 else if (diff>= 4 &&  diff <= 5 )
     motor_control(50,100);
 else if(diff>= 6 &&  diff <= 7 )
     motor_control(30,100);
 else if(diff >=8 )
     motor_control(0,100);

 else if (diff<= -1 &&  diff >= -3 )
     motor_control(100,70);
 else if (diff<= -4 &&  diff >= -5 )
     motor_control(100,50);
 else if(diff<= -6 &&  diff >= -7 )
     motor_control(100,30);
 else if(diff <=-8 )
     motor_control(100,0);
}

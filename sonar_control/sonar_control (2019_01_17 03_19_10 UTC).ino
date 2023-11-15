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

NewPing sonar[3]={ NewPing(trig,mdl_echo, 150), NewPing(trig,lft_echo, 150), NewPing(trig,rht_echo, 150)};

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
  boolean obs=0;
  sonar_activate();
  while(1){
    sonar_activate();
    sonar_track();
    if(dist[0]>=3 && dist[0]<=15){
      break;
    }
  }
  
    motor_control(0, 0);
    delay( 300);
    sonar_activate();
  while(1){
    sonar_activate();
    motor_control(-100, 100);
    if(dist[2]>=3 && dist[2]<=15){
      break;
    }
  }
  
    motor_control(0, 0);
    delay( 300);
    sonar_activate();
  while(1){
    sonar_activate();
    right_track();////////////////////////////////////
     digitalWrite(rht_led,HIGH);
  
     
    if(dist[1]>=3 && dist[1]<=15){ ////////[1]>>[0]
      digitalWrite(rht_led,LOW);
   

      break;
    }
  }
  
  while(1){
    if(dist[2]>=3 && dist[2]<=45){
    sonar_activate();
    sonar_track();
    }
    else{
      break;
    }
  }
    motor_control(0, 0);
    delay( 100);
    sonar_activate();
  while(1){
    sonar_activate();
    left_track();
    if(dist[0]>=3 && dist[0]<=15){
      break;
    }
  }
  
    motor_control(0, 0);
    delay( 100);
    sonar_activate();
  while(1){
    sonar_activate();
    motor_control(100, -100);
     digitalWrite(lft_led,HIGH);
     // delay(200);
    
    
    if(dist[1]>=3 && dist[1]<=15){
      digitalWrite(lft_led,0);
      break;
    }
  }
  
    motor_control(0, 0);
    delay( 100);
    sonar_activate();
  while(1){
    sonar_activate();
    left_track();
    if(dist[0]>=3 && dist[0]<=15){
      break;
    }
  }
  
    motor_control(0, 0);
    delay( 300);
    sonar_activate();
  while(1){
    sonar_activate();
    motor_control(100, -100);
    if(dist[1]>=3 && dist[1]<=45){
      break;
    }
  }
//  else{
    motor_control(0, 0);
  //  delay( 10000);
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
 else if(diff >=8 &&  diff <=10)
     motor_control(0,100);

 else if (diff<= -1 &&  diff >= -3 )
     motor_control(100,70);
 else if (diff<= -4 &&  diff >= -5 )
     motor_control(100,50);
 else if(diff<= -6 &&  diff >= -7 )
     motor_control(100,30);
 else if(diff <=-8 && diff >=-10 )
     motor_control(100,0);
else if(diff>=11 || diff<=-11)
  motor_control(100,100);
}



void right_track(){
  if(dist[2]==15){
    motor_control(100, 100);
  }
  else if(dist[2]>=12 && dist[2]<=14){
    motor_control(70, 100);
  }
  else if(dist[2]>=9 && dist[2]<=11){
    motor_control(50, 100);
  }
  else if(dist[2]>=6 && dist[2]<=8){
    motor_control(0, 100);
  }
  else if(dist[2]>=16 && dist[2]<=18){
    motor_control(100, 70);
  }
  else if(dist[2]>=19 && dist[2]<=21){
    motor_control(100, 50);
  }
  else if(dist[2]>=22 && dist[2]<=24){
    motor_control(100, 0);
  }
}




void left_track(){
  if(dist[1]==15){
    motor_control(100, 100);
  }
  else if(dist[1]>=12 && dist[1]<=14){
    motor_control(100, 70);
  }
  else if(dist[1]>=9 && dist[1]<=11){
    motor_control(100, 50);
  }
  else if(dist[1]>=6 && dist[1]<=8){
    motor_control(100, 0);
  }
  else if(dist[1]>=16 && dist[1]<=18){
    motor_control(70, 100);
  }
  else if(dist[1]>=19 && dist[1]<=21){
    motor_control(50, 100);
  }
  else if(dist[1]>=22 && dist[1]<=24){
    motor_control(0, 100);
  }
}

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

#define Kp 35
#define Kd 15

int sensor_pin[10]= {PA6, PB1, PB0, PA7, PA4, PA3, PA2, PA0, PA1, PA5};
int sensor[10];
int sum;
boolean d_sensor[10];


#include<NewPing.h>

NewPing sonar[3]={ NewPing(trig,mdl_echo, 150), NewPing(trig,lft_echo, 150), NewPing(trig,rht_echo, 150)};

int dist[3];
int diff;

boolean lft_flag, b_lft, rht_flag, b_rht;
boolean plus, T, LT, RT, U;


void setup() {
  afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  Serial.begin(9600);
  pin_declare();
  digitalWrite(STBY, HIGH);
 delay(1000); 
}


void loop() {
// sensor_read();
 d_sensor_read();
  detect_node();
//  turn();
  if(d_sensor[0]==1 || d_sensor[1]==1 || d_sensor[7]==1 || d_sensor[8]==1){
    motor_control(90, 90);
  }
  else{
    PD();
  }
}

void cave(){
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




  

int sensor_pin[7] = { PB1,PB0,PA7,PA4,PA3,PA2,PA0 };
int sensor[7];
int b_lft=sensor[0];

int b_rgt=sensor[6];

int a,b,c;
int t_lft,t_mdl,t_rgt;
bool h_t_lft,h_t_rgt,h_b_lft,h_b_rgt;
#define a PA6 //top_left
#define b PA5 // top_middle
#define c PA1 //top_right
#define LM2 PB4//here>>portion A is left....portion B is right
#define LM1 PB3
#define RM2 PB7
#define RM1 PB6
#define LMPWM PB9
#define RMPWM PB8
#define STBY PB5

#define Kp 33.33//45
#define Kd 100

#define lft_led PB15
#define rgt_led PA8

void  analogSerialRead();
void dS_Read();
void SensorRead();
int koyta_kalo();
float  PD();
void  motor_control();

unsigned long prevMillis = 0;


void analogSerialRead()
{
//  int t_lft,t_mdl,t_rgt ;
    t_lft=analogRead(a);
  t_mdl=analogRead(b);
  t_rgt=analogRead(c);
  Serial.print(t_lft);
  Serial.print("\t\t\t");
  Serial.print(t_mdl);
  Serial.print("\t\t\t");
  Serial.print(t_rgt);
  Serial.println();
  for(int i=0;i<7;i++)
     {
     sensor[i]=analogRead(sensor_pin[i]);
    Serial.print(sensor[i]);
    Serial.print("\t");    
  
  }
  Serial.println(" ");
}

void SensorRead()
{
//     int t_lft,t_mdl,t_rgt ;
    t_lft=analogRead(a);
  t_mdl=analogRead(b);
  t_rgt=analogRead(c);
 if ( t_lft<3300 ) t_lft=0; else t_lft=1;
  if ( t_rgt<3300 ) t_rgt=0; else t_rgt=1;
  if ( t_mdl<2800 ) t_mdl=0; else t_mdl=1;
   
   for(int i=0;i<7;i++)
   {
    sensor[i]=analogRead(sensor_pin[i]);

   if (sensor[i]<= 3300)  sensor[i]=0;
  else sensor[i]=1;
 
  }
  b_lft=sensor[0];
 b_rgt=sensor[6];
} 

int koyta_kalo()
{
  int count = 0; 
   for( int i=1; i<6; i++)
   {
    sensor[i]= analogRead(sensor_pin[i]);
  
    if (sensor[i]<= 3300)  
      sensor[i]=0;
    else 
      sensor[i]=1;
     if (sensor[i]==1) count++;   
      Serial.print(sensor[i]);
   }
    
   Serial.print("\t");
 
      Serial.print(count);
    Serial.println(" ");
   
  return count;
}

  float PD() 
{ 
// int t_lft,t_mdl,t_rgt ;
   t_lft=analogRead(a);
  t_mdl=analogRead(b);
  t_rgt=analogRead(c);
  sensor[0]=analogRead(sensor_pin[0]);
  sensor[6]=analogRead(sensor_pin[6]);
  
  if ( t_lft<3200 )
    {
      t_lft=0;
      //digitalWrite(lft_led,LOW);
     }
  else 
    {
      t_lft=1;
    //  digitalWrite(lft_led,HIGH);
      }      
 if ( t_rgt<3200 ) 
    {
      t_rgt=0;
     // digitalWrite(rgt_led,LOW);
      }
 else 
      {
      t_rgt=1;
    //  digitalWrite(rgt_led,HIGH);     
     }
  if ( t_mdl<2800 ) t_mdl=0; else t_mdl=1;
 
  if ( sensor[0]<3200 )
    {
      b_lft=0;
     // digitalWrite(lft_led,1);
      }
  else
      {
        b_lft=1;
       // digitalWrite(lft_led,0);
        }
  if ( sensor[6]<3200 )
      {
        b_rgt=0;
       // digitalWrite(rgt_led,1);
        }
   else{
        b_rgt=1;
      //  digitalWrite(rgt_led,0);
        }


     if (t_lft==1) h_t_lft=1;
     if (t_rgt==1) h_t_rgt=1;
     if (b_lft==1) h_b_lft=1;
     if (b_rgt==1) h_b_rgt=1;
  
  float m = koyta_kalo();
  if (m==0) return 99;
//  if (a==1 && b==1 && c==1) return 111;
//  if (m==7) return 100;
  float positions = ( sensor[1] * (-2) + sensor[2] * (-1) + sensor[3] * 0 + sensor[4] * 1 + sensor[5] *2 ) / m;
  float error = positions - 0;
  Serial.println(error);
  return error;
}

void motor_control()
{
 
  float error = PD();
     int m= koyta_kalo();
  if (error == 99) 
  {
   int x= koyta_kalo();

    while(x==0)
         { stopp();
            x=koyta_kalo();           
//         digitalWrite(lft_led,HIGH);
//     digitalWrite(rgt_led,HIGH);
         }
  } 
//  else 
//  {
//     digitalWrite(lft_led,LOW);
//     digitalWrite(rgt_led,LOW); 
//   }

if (( (h_t_lft==1 && h_b_lft == 1)  || (h_t_rgt==1 && h_b_rgt==1)) && ( t_lft==0 && b_lft == 0  && t_rgt==0 && b_rgt==0 ) ) 
   {
      stopp();
//    digitalWrite(lft_led,1);
//    digitalWrite(rgt_led,1); 
    delay(100);
    SensorRead();
    if (h_t_lft==1 && h_b_lft==1 && h_t_rgt==1 && h_b_rgt==1)
    {
      if (t_mdl==1 || sensor[2]==1 || sensor[3]==1 || sensor[4]==1)
      { 
        Serial.println("Plus");
      }
      else{
        Serial.println("TTTTT");
      }
    }
  else if (h_t_lft==1 && h_b_lft==1 && h_t_rgt==0 && h_b_rgt==0)
        {
          if (t_mdl==1 ||sensor[2]==1 || sensor[3]==1 || sensor[4]==1)
              {
              Serial.println("LT LT LT LT LT LT LT LT LT LT LT");
              }
          else{
            Serial.println("L90 L90");
          }
      }
      
 else if (h_t_lft==0 && h_b_lft==0 && h_t_rgt==1 && h_b_rgt==1)
        {
          if (t_mdl==1 ||sensor[2]==1 || sensor[3]==1 || sensor[4]==1)
              {
              Serial.println("RT RT RT RT RT RT RT RT RT RT RT");
//        digitalWrite(rgt_led,1);
//              delay(3000);digitalWrite(rgt_led,1);
              }
          else{
            Serial.println("R90 R90");
          }
         }
      delay(3000);
//    h_t_lft=0; h_b_lft =0; h_t_rgt=0; 
//    h_b_rgt=0;
    
    }

  int left_speed, right_speed;
  int prev_error;
  left_speed = 70 + (Kp * error +Kd*(error-prev_error)) ;
  right_speed = 70 - (Kp * error +Kd*(error-prev_error)) ;
  prev_error=error;
  // Kd*(error-prev_error)
  if (left_speed > 255)left_speed = 250;
  if (right_speed > 255 )right_speed = 250;
  if (left_speed < -255)left_speed = -250;
  if (right_speed < -255)right_speed = -250;
  speed_control(left_speed, right_speed);

  Serial.print(left_speed);
  Serial.print("\t");
  Serial.println(right_speed);
}

void motor_control_2()
{
  float error = PD();
     int m= koyta_kalo();
  if (error == 99) 
  {
   int x= koyta_kalo();

    while(x==0)
         { stopp();
            x=koyta_kalo();           
//         digitalWrite(lft_led,HIGH);
//     digitalWrite(rgt_led,HIGH);
         }
  }

 int left_speed, right_speed;
  int prev_error;
  left_speed = 70 + (Kp * error +Kd*(error-prev_error)) ;
  right_speed = 70 - (Kp * error +Kd*(error-prev_error)) ;
  prev_error=error;
  // Kd*(error-prev_error)
  if (left_speed > 255)left_speed = 250;
  if (right_speed > 255 )right_speed = 250;
  if (left_speed < -255)left_speed = -250;
  if (right_speed < -255)right_speed = -250;
  speed_control(left_speed, right_speed);

  Serial.print(left_speed);
  Serial.print("\t");
  Serial.println(right_speed);
 
 }
 
void setup()
{afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  Serial.begin(115200);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LMPWM,OUTPUT);
  pinMode(RMPWM,OUTPUT);
  pinMode(STBY,OUTPUT);
  pinMode(lft_led,OUTPUT);
  pinMode(rgt_led,OUTPUT);
}

void speed_control(int lft, int right)
{
  if (lft >= 0)
        {
        digitalWrite(LM1, HIGH);
        digitalWrite(LM2, LOW);
        analogWrite(LMPWM, lft);
        }
  else 
      {     
        digitalWrite(LM2, HIGH);
        digitalWrite(LM1, LOW);
        analogWrite(LMPWM, -1*lft);  
        }
  if (right >= 0)
           {
             digitalWrite(RM1, HIGH);
             digitalWrite(RM2, LOW);
             analogWrite(RMPWM, right);
            }
                
  else {
          digitalWrite(RM2, HIGH);
          digitalWrite(RM1, LOW);
          analogWrite(RMPWM, -1*right);
        }
}

void stopp()
{
  analogWrite(LMPWM, 0);
analogWrite(RMPWM, 0);
}

void dS_Read()
{
// t_lft,t_mdl,t_rgt ;
    t_lft=analogRead(a);
  t_mdl=analogRead(b);
  t_rgt=analogRead(c);
 if ( t_lft<3200 ) t_lft=0; else t_lft=1;
  if ( t_rgt<3200 ) t_rgt=0; else t_rgt=1;
  if ( t_mdl<2800 ) t_mdl=0; else t_mdl=1;
  Serial.print(t_lft);
  Serial.print("  ");
  Serial.print(t_mdl);
  Serial.print("  ");
  Serial.print(t_rgt);
  Serial.println();
      
 for(int i=0;i<7;i++)
   {
    sensor[i]=analogRead(sensor_pin[i]);

   if (sensor[i]<= 3200)  sensor[i]=0;
  else sensor[i]=1;
 
//  Serial.print("Sensor[");
//  Serial.print(i);
//  Serial.print("]=");
  Serial.print(sensor[i]);
  //Serial.print("\t");
  }
  Serial.println();
}
  float PD_aager() 
{
  float b = koyta_kalo();
  if (b==0) return 99;
 // if ((b==7) && top_middle==1) return 100;
  float positions = ( sensor[0] * (-3) + sensor[1] * (-2) + sensor[2] * (-1) + sensor[3] * 0 + sensor[4] * 1 + sensor[5] *2  + sensor[6] * 3 ) / b;
  float error = positions - 0;
  int P = error;
  Serial.println(error);
  return error;
}
void motor_control_3()
{
 
  float error = PD_aager();
  if (error == 99) 
  {
   int x= koyta_kalo();
    while(x==0)
         { stopp();
            x=koyta_kalo();
         }
  }  
  
  int left_speed, right_speed;
  int prev_error;
  left_speed = 130 + (Kp * error +Kd*(error-prev_error)) ;
  right_speed = 130 - (Kp * error +Kd*(error-prev_error)) ;
  prev_error=error;
  // Kd*(error-prev_error)
  if (left_speed > 255)left_speed = 250;
  if (right_speed > 255 )right_speed = 250;
  if (left_speed < -255)left_speed = -250;
  if (right_speed < -255)right_speed = -250;
  speed_control(left_speed, right_speed);

  Serial.print(left_speed);
  Serial.print("\t");
  Serial.println(right_speed);
}

void loop()
{
//  speed_control(100,100);
  motor_control_3();
   // analogSerialRead();
 // dS_Read();
//   SensorRead();
//   Serial.print("b_lft=");
//   Serial.print(t_lft);
//   Serial.print("      b_rgt=");
//  Serial.println(t_rgt);
  digitalWrite(PB5,HIGH);
 //int p=analogRead(sensor_pin[0]);
 // Serial.println(p);
  // koyta_kalo();
 //PD();
   delay(50);
}

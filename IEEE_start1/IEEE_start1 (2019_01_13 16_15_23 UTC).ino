int sensor[8] = {
  A0, A1, A2, A3, A4, A5,A6,A7 };
int i;


#define LM1  8
#define LM2 7
#define RM1 5
#define RM2 4
#define LMPWM 9
#define RMPWM 3
#define STBY 6
void left_motor_f(int speeds)
{
  int speeds1 = speeds;
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(LMPWM, speeds1);
}

void right_motor_b(int speeds)
{
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(RMPWM, speeds);
}

void left_motor_b(int speeds)
{

  digitalWrite(LM2, HIGH);
  digitalWrite(LM1, LOW);
  analogWrite(LMPWM, speeds);
}

void right_motor_f(int speeds)
{

  digitalWrite(RM2, HIGH);
  digitalWrite(RM1, LOW);
  analogWrite(RMPWM, speeds);
}

void left_motor_stop()
{

  digitalWrite(LM2, LOW);
  digitalWrite(LM1, LOW);
}

void right_motor_stop()
{
  digitalWrite(RM2, LOW);
  digitalWrite(RM1, LOW);
}

void forward(int  fast_speeds)
{
  int zero1 = fast_speeds;
  left_motor_f(zero1);
  right_motor_b(zero1);
}
//right motor b maane samne
//left motor f maane samne
void right(int right_speeds)
{
  int speeds = right_speeds;
  left_motor_f(speeds);
  right_motor_stop();

}
void speed_control(int lft, int right)
{
  //  int lft,right;
  if (lft >= 0)left_motor_f(lft); else left_motor_b(-lft);;
  if (right >= 0)right_motor_b(right); else right_motor_f(-right);
}
void left(int left_speeds) {
  int speeds = left_speeds;
  right_motor_b(speeds);
  left_motor_stop();
}
void sharp_left(int fast_left_speeds)
{
  int speeds = fast_left_speeds;
  right_motor_b(speeds);
  left_motor_b(speeds);
}

void sharp_right(int fast_right_speeds)
{
  int speeds = fast_right_speeds;
  left_motor_f(speeds);
  right_motor_f(speeds);
}

void stopp()
{
  left_motor_stop();
  right_motor_stop();
}



void setup()
{
Serial.begin(9600);
//for(int i=0;i<8;i++)
//pinMode(A0,INPUT);  
     }

void analogSerialRead()
{
  for(int i=0;i<8;i++)
   {
   int p= analogRead(sensor[i]);
  Serial.print(p);
  Serial.print("\t");    
   }
Serial.println(" ");
}

void dS_Read()
{
for (i=0;i<8;i++)
{
  sensor[i]=analogRead(i);
  if ( sensor[i]>500 )
  sensor[i]=0;else sensor[i]=1;
  Serial.print(sensor[i]);
  Serial.print("\t");
  }
  Serial.println();
}
 
  
void SensorRead()
{
   for(int i=0;i<8;i++)
   {
    sensor[i]= analogRead(i);

 if (sensor[i]>510)
 sensor[i]=0;
else sensor[i]=1;
   }
}
int koyta_kalo()
{
  SensorRead();
  int m, count = 0;
  for (int i = 0; i <8 ; i++)
  {
    if ( sensor[i] == 1)
      count++;
  }
  return count;
}
int PD() {
  int b = koyta_kalo();
  int positions = ( sensor[0] * 100 + sensor[1] * 200 + sensor[2] * 300 + sensor[3] * 400 + sensor[4] * 500 + sensor[5] * 600 + sensor[6] * 700 + sensor[7] * 800  ) / b;
  int error = positions - 450;
  int P = error;
  Serial.println(error);
  return error;
}

#define Kp .30
#define Kd 1.13

void motor_control()
{
  SensorRead();
//  if ( (sensor[7]==1 || sensor[6]==1) && (sensor[0]=0 || sensor[1]==0) && (sensor[3]==1 || sensor[4]==1)  ) 
//  {
//    stopp();
//    delay(20);
//    while((sensor[3]==1 || sensor[4]==1) && (sensor[7]==0 || sensor[6]==0) )
//    {
//    sharp_right(120);
//    delay(20);
//    SensorRead();
//     Serial.print("Sharp_right");
//    } 
//  }
//  if((sensor[7]==0 || sensor[6]==0) && (sensor[0]=1 || sensor[1]==1) && (sensor[3]==1 || sensor[4]==1)  )
//    {
//      stopp();
//      delay(20);
//      while ((sensor[3]==1 || sensor[4]==1) && (sensor[0]==1 || sensor[6]==0) )
//      {
//        sharp_left(120);
//        delay(20);
//        SensorRead();
//        Serial.print("Sharp_left");
//        }
//      }
  
  int error = PD();
  
  int left_speed, right_speed;
 int prev_error;
  left_speed = 150 + (Kp * error + Kd*(error-prev_error)) ;
  right_speed = 150 - (Kp * error +Kd*(error-prev_error)) ;
   prev_error=error;
if (error==-451) stopp();  if (left_speed > 250)left_speed = 250;
  if (right_speed > 250)right_speed = 250;
  if (left_speed < -255)left_speed = -255;
  if (right_speed < -255)right_speed = -255;
//  if (abs(left_speed - right_speed) > 240)
//  {
//    if (left_speed > right_speed)speed_control(120, 50);
//  
//    else if (left_speed < right_speed) speed_control(50, 120);
//  }
   speed_control(left_speed, right_speed);

  Serial.print(left_speed);
  Serial.print("\t");
  Serial.println(right_speed);
}


void loop()
 {
  digitalWrite(STBY,HIGH); 
  //sharp_left(120);
  //speed_control(-144,250);
  //analogSerialRead();
  //dS_Read();
 //right_motor_b(right);
//int error= PD();
 //if (error==-451) stopp();
 motor_control();
 }
   

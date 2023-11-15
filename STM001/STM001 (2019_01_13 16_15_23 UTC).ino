int sensor[7] = { PB1,PB0,PA7,PA4,PA3,PA2,PA0 };
int i;

#define top_left PA6
#define top_middle PA5
#define top_right PA1
#define LM1 PB4//here>>portion A is left....portion B is right
#define LM2 PB3
#define RM1 PB7
#define RM2 PB6
#define LMPWM PB9
#define RMPWM PB8
#define STBY PB5

void setup()
{
   //afio_cfg_debug_ports(AFIO_DEBUG_NONE);
  Serial.begin(115200);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LMPWM,OUTPUT);
  pinMode(RMPWM,OUTPUT);
  pinMode(STBY,OUTPUT);
  //pinMode(PC13,OUTPUT);
  }
  
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

void analogSerialRead()
{
  int a,b,c;
  a=analogRead(top_left);
  b=analogRead(top_middle);
  c=analogRead(top_right);
  Serial.print(a);
  Serial.print("\t\t\t");
  Serial.print(b);
  Serial.print("\t\t\t");
  Serial.print(c);
  Serial.println();
for(int i=0;i<7;i++)
   {
   int p= analogRead(sensor[i]);
  Serial.print(p);
  Serial.print("\t");    
  
}
Serial.println(" ");
}

void dS_Read()
{
int a,b,c;
  a=analogRead(top_left);
  b=analogRead(top_middle);
  c=analogRead(top_right);
    if ( a<4000 ) a=0; else a=1;
  if ( b<4000 ) b=0; else b=1;
  if ( c<4000 ) c=0; else c=1;
  Serial.print(a);
  Serial.print("\t\t\t");
  Serial.print(b);
  Serial.print("\t\t\t");
  Serial.print(c);
  Serial.println();
for(int i=0;i<7;i++)
   {
   int p= analogRead(sensor[i]);
   if (p<4000) p=0;
   else p=1;
  Serial.print(p);
  Serial.print("\t");      
}
Serial.println(" ");
 
}
 
  
void SensorRead()
{

  int a,b,c;
  a=analogRead(top_left);
  b=analogRead(top_middle);
  c=analogRead(top_right);
  if ( a<4000 ) a=0; else a=1;
  if ( b<4000 ) b=0; else b=1;
  if ( c<4000 ) c=0; else c=1;
   
   for(int i=0;i<7;i++)
   {
    sensor[i]= analogRead(sensor[i]);

 if (sensor[i]<4200)
 sensor[i]=0;
else sensor[i]=1;
   }
}

void loop()
{
//  int a,b,c;
//  a=analogRead(top_left);
//   if (a>=4000) a=1;
//   else a= 0 ;
//    Serial.println(a);
  //digitalWrite(STBY,HIGH);
 analogSerialRead();
// dS_Read();
// digitalWrite(PC13,HIGH);
// delay(1000);
// digitalWrite(PC13,LOW);
// delay(1000);
// digitalWrite(STBY,HIGH);
// left_motor_b(200);
// right_motor_f(200);
//// Serial.println(analogRead(PA2));
  }


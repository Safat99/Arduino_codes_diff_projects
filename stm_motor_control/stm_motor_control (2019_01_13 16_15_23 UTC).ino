#define top_left PA6
#define top_middle PA5
#define top_right PA1
#define LM2 PB4//here>>portion A is left....portion B is right
#define LM1 PB3
#define RM2 PB7
#define RM1 PB6
#define LMPWM PB9
#define RMPWM PB8
#define STBY PB5

void setup()
{
   afio_cfg_debug_ports(AFIO_DEBUG_NONE);
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
void stopp()
{
  analogWrite(LMPWM, 0);
analogWrite(RMPWM, 0);
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
void loop()
{
  //digitalWrite(STBY,HIGH);
//  forward(200);delay(2000);
//  stopp();delay(2000);
//  right(200);delay(2000);
//  stopp();delay(2000);
//  left(200);delay(2000); 
//  stopp();delay(2000);
    speed_control(-255,200);
}

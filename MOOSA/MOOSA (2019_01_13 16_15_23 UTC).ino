#define LM2 4
#define LM1 5
#define LMPWM 3
#define RM2 7
#define RM1 8
#define RMPWM 9
#define STBY 6
#define x 150
#define trig 11
#define echo 12

int duration;
void setup() {
  // put your setup code here, to run once:
for (int i=3;i<=9;i++)
pinMode(i,OUTPUT);

 pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(STBY,HIGH);  
int m;
    m=sonar_activate();
    if (m<7 && m>0)
     {
      stopp();Serial.print("LEFT");
      left();delay(1000);
      }
    else forward();  
    
}

void forward()
{
  digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
analogWrite(LMPWM,x);
analogWrite(RMPWM,x);
  }
void backward()
{
  digitalWrite(LM2,HIGH);
digitalWrite(LM1,LOW);
digitalWrite(RM2,HIGH);
digitalWrite(RM1,LOW);
analogWrite(LMPWM,x);
analogWrite(RMPWM,x);
  }
void left()
{
  digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM1,LOW);
digitalWrite(RM2,HIGH);
analogWrite(LMPWM,x);
analogWrite(RMPWM,x);
  }
void right()
{
   digitalWrite(LM1,LOW);
digitalWrite(LM2,HIGH);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
analogWrite(LMPWM,x);
analogWrite(RMPWM,x);
  }
void stopp()
{
  analogWrite(LMPWM,0);
analogWrite(RMPWM,0);
  } 
float sonar_activate()
{
  delay(100);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);

  duration = pulseIn(echo,HIGH);
  float distance=(duration*.035)/2;
  Serial.println(distance);
  return distance;
  }
   

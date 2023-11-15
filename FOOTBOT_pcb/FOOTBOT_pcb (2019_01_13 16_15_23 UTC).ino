#define LMPWM 3   
#define RMPWM 9
#define LM1 4
#define LM2 5
#define RM1 8
#define RM2 7
#define STBY 6

void setup() {
  
pinMode(LM1,     OUTPUT);
pinMode(LM2,     OUTPUT);
pinMode(LMPWM,  OUTPUT);
pinMode(RM1,     OUTPUT);
pinMode(RM2,     OUTPUT);
pinMode(RMPWM, OUTPUT);
pinMode(STBY,  OUTPUT);
pinMode(12,OUTPUT);

Serial.begin(9600);

for (int i=0;i<4;i++)
{
digitalWrite(12,HIGH);
delay(200);
digitalWrite(12,LOW);
delay(200);
}
} 
void left_motor_f(int speeds)
 {
    int speeds1=speeds;  
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
  int zero1=fast_speeds;
  left_motor_f(zero1);
  right_motor_b(zero1);
 }
 
 void backward(int fast_speeds)
 {
  int zero=fast_speeds;
  left_motor_b(zero);
  right_motor_f(zero);
 }
                                         //right motor b maane samne
                                         //left motor f maane samne
void right(int right_speeds)
{
 int speeds=right_speeds;
  left_motor_f(speeds);
  right_motor_stop();
  
}

void left(int left_speeds){ 
                          int speeds=left_speeds;
                          right_motor_b(speeds);
                          left_motor_stop();
                          }
void pisone_right(int pisone_speeds){
                                    int speeds=pisone_speeds;
                                    left_motor_b(speeds);
                                    right_motor_stop();                           
                                    }


  
void pisone_left(int pisone_speeds){
                                int speeds=pisone_speeds;
                                    right_motor_f(speeds);
                                    left_motor_stop();
                                      }
 void sharp_left(int fast_left_speeds)
 {
  int speeds=fast_left_speeds;
  right_motor_b(speeds);
  left_motor_b(speeds);
 }

 void sharp_right(int fast_right_speeds)
 {
  int speeds=fast_right_speeds; 
  left_motor_f(speeds);
  right_motor_f(speeds);
 }

 void stopp()
 {
  left_motor_stop();
  right_motor_stop();
 }

void loop() 
{
  digitalWrite(STBY,HIGH);
   while(Serial.available())
  {
    char a = Serial.read();
    
//    Serial.print(data);
    
    
    Serial.print(a);
   if(a=='F')
    {    
      forward(230);
    }
    
    if(a=='B')
    {
      backward(230);
    }
     
    if(a=='R')
    {
      sharp_right(230);
    }
    
    if(a=='L')
    {
      sharp_left(230);
    }
    if(a=='S'){
      stopp();
      }
    if(a=='I'){
      right(180);
      }
   if(a=='G'){
     left(180);
    }     
   if(a=='H'){
     pisone_left(180);    
    }
   if(a=='J'){
     pisone_right(180MN  );
     } 
   if(a=='S'){
    stopp();   
    }
            
  }

}

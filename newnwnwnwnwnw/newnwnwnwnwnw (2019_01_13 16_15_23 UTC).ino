#define LM1 4
#define LM2 5
#define LMPWM 3
#define RM1 8
#define RM2 7
#define RMPWM 9
#define STBY 6
void setup() {
  // put your setup code here, to run once:
for (int i=3;i<=9;i++)
pinMode(i,OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(STBY,HIGH);  
  // put your main code here, to run repeatedly:
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
analogWrite(LMPWM,255);
analogWrite(RMPWM,255);


}



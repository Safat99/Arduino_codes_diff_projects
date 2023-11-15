#include <SoftwareSerial.h>
int x=240;
int y=240;

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() 
{
  
//  if(Serial.available())
//  {
//    char a=Serial.read();
//    Serial.println(a);
//
//
//if (a == 'L') {
//      analogWrite(6, x);
//      analogWrite(3, y);
//       
//      digitalWrite(11, HIGH);
//      digitalWrite(10, LOW);
//      digitalWrite(9, HIGH);
//      digitalWrite(8, LOW);
//    }
//
//    if (a == 'G') {
//      analogWrite(6, 100);
//      analogWrite(3, y);
//       
//      digitalWrite(11, HIGH);
//      digitalWrite(10, LOW);
//      digitalWrite(9, HIGH);
//      digitalWrite(8, LOW);
//    }
//    
//    if (a == 'B') {
//      analogWrite(6, x);
//      analogWrite(3, y);
//      digitalWrite(11, LOW);
//      digitalWrite(10, HIGH);
//      digitalWrite(9, HIGH);
//      digitalWrite(8, LOW);
//    } 
//   
//    if (a == 'F') {
//      analogWrite(6, x);
//      analogWrite(3, y);
//      digitalWrite(11, HIGH);
//      digitalWrite(10, LOW);
//      digitalWrite(9, LOW);
//      digitalWrite(8, HIGH);
//    }
//    if (a == 'R') {
      analogWrite(6, x);
      analogWrite(3, y);
       
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
//    }
//    
//        if (a == 'I') {
//      analogWrite(6, x);
//      analogWrite(3, 100);
//       
//      digitalWrite(11, LOW);
//      digitalWrite(10, HIGH);
//      digitalWrite(9, LOW);
//      digitalWrite(8, HIGH);
//    }
//    if (a == 'S') {
//      analogWrite(6, x);
//      analogWrite(3, y);
//      digitalWrite(11, LOW);
//      digitalWrite(10, LOW);
//      digitalWrite(9, LOW);
//      digitalWrite(8, LOW);
//    }
//      
//  }
    }
  





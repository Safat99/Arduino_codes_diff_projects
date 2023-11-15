#define Q1 A0   // Attach DTMF Module Q1  Pin to Arduino Pin A0
 #define Q2 A1   // Attach DTMF Module Q2  Pin to Arduino Pin A1
 #define Q3 A2   // Attach DTMF Module Q3  Pin to Arduino Pin A2
 #define Q4 A3   // Attach DTMF Module Q4  Pin to Arduino Pin A3
 #define STD A4  // Attach DTMF Module STD Pin to Arduino Pin A4

 #define Relay_1 8  // Attach Relay_1 Control Pin to Arduino Pin 8
 

 int DTMFdata; // The DTMFdata variable will be used to interpret the output of the DTMF module.


void setup() 
{
  Serial.begin(9600); 
  
  //Setup the INPUT pins on the Arduino for "MT8870 DTMF Module" 
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(STD, INPUT);

  //Setup the OUTPUT pins on the Arduino for Relay 
  pinMode(Relay_1, OUTPUT);
}


void loop() 
{
 digitalWrite(Relay_1,HIGH);
 delay(1000);
 digitalWrite(Relay_1,LOW);
 delay(1000);

}

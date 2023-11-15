#define lft_led PB15
#define rgt_led PA8
void setup() {
  // put your setup code here, to run once:
pinMode(lft_led,OUTPUT);
pinMode(rgt_led,OUTPUT);

Serial.begin(115200);
}
//Unsigned long time_start, time_stop, diff;
//time_start= millis();
//time_stop=millis();
//diff=time_stop - time_start;
 unsigned long prevMillis = 0;
 int led_blink_millis(int x)
 {
 // unsigned long prevMillis = 0;
  unsigned long currentMillis=millis();
  while (currentMillis-prevMillis < x )
     {
      digitalWrite(lft_led,1);
      digitalWrite(rgt_led,1); 
      delay(100);
      digitalWrite(lft_led,0);
      digitalWrite(rgt_led,0); 
      delay(100);
      currentMillis=millis();
      Serial.println(currentMillis);
      }
  prevMillis = currentMillis;    
  Serial.print("\t");
  Serial.print("Prev_MIllis=");
  Serial.print(prevMillis);
  
    Serial.print("\t");
  Serial.print("currentMillis=");
  Serial.println(currentMillis);
  
  }
void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(lft_led,1);
led_blink_millis(5000);
delay(1000);
}

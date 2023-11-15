#include <EEPROM.h>
#include <flash_stm32.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  Serial.write(EEPROM.read(0));
  int i=1;
  while(i<20){
    char c= EEPROM.read(i);
    i++;
      Serial.write(c);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char c=Serial.read();
    if(c=='a'){
      Serial.write((char) EEPROM.read(0));
      Serial.println();
    }
    else{
      EEPROM.write(0, c);
    }
  }

  
}

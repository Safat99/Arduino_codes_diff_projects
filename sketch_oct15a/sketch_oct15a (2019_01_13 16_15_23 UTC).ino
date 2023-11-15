#include <LiquidCrystal.h>

LiquidCrystal lcd(4,11,6,7,8,12);

void setup() {
    lcd.begin(8, 2);
   lcd.print("HELLO");
lcd.setCursor(0,1);
lcd.print("WORLD");
    
}
void loop() {

}

#include <LiquidCrystal.h>
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);
byte user1[8] = {B10000, B00000, B00111, B01000, B01000, B01000, B00111, B00000};
void setup()
{
    Serial.begin(9600);
    lcd.createChar(0, user1);
    while (1)
    {
        lcd.begin(16, 2);
        int reading = analogRead(55);
        float voltage = reading * 5.0 / 1024.0;
        float temp_C = voltage * 100;
        lcd.print("Temp: ");
        lcd.print(temp_C);
        lcd.write(byte(0));
        lcd.setCursor(0, 1);
        int reading2 = analogRead(56);
        float light = reading2 / 1024.0;
        lcd.print("Light: ");
        lcd.print(light);
        delay(1000);
    }
}
void loop() {}
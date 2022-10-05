int pin_LED2 = 2;
int pin_LED3 = 3;
unsigned long time_previous2, time_previous3, time_current2, time_current3;
unsigned long interval2 = 1000, interval3 = 1000;
boolean LED_state2 = false;
boolean LED_state3 = false;
void setup()
{
    pinMode(A0, INPUT);
    pinMode(pin_LED2, OUTPUT);
    digitalWrite(pin_LED2, LED_state2);
    pinMode(pin_LED3, OUTPUT);
    digitalWrite(pin_LED3, LED_state3);
    Serial.begin(9600);
    time_previous2 = millis();
    time_previous3 = millis();
}
void loop()
{
    time_current2 = millis();
    if (time_current2 - time_previous2 >= 2000 - interval2)
    {
        time_previous2 = time_current2;
        LED_state2 = !LED_state2;
        Serial.println(interval2);
        digitalWrite(pin_LED2, LED_state2);
    }
    time_current3 = millis();
    if (time_current3 - time_previous3 >= 2000 - interval3)
    {
        time_previous3 = time_current3;
        LED_state3 = !LED_state3;
        digitalWrite(pin_LED3, LED_state3);
    }
    int adf = analogRead(A0);
    interval2 = map(adf, 0, 1023, 500, 1500);
    interval3 = map(adf, 0, 1023, 1500, 500);
}
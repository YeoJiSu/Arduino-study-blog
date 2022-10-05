void setup()
{
    Serial.begin(9600);
    for (int j = 0; j < 4; j++)
    {
        pinMode(j + 2, OUTPUT);
        digitalWrite(j + 2, LOW);
    }
}
void loop()
{
    int reading = analogRead(55);
    Serial.println(reading);
    for (int i = 0; i < 4; i++)
    {
        if (reading >= 1023 * (i / 4.0) && reading <= 1023 * (i + 1) / 4.0)
        {
            for (int k = 0; k <= i; k++)
            {
                digitalWrite(k + 2, HIGH);
            }
        }
        else
            digitalWrite(i + 2, LOW);
    }
}
#include "pitches.h"
int speakerPin = 57;
int vResister = 56;
int melody[] = {0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int noteDuration = 4;
void setup()
{
    Serial.begin(9600);
    pinMode(vResister, INPUT);
}
void loop()
{
    int adc = analogRead(56);
    float voltage = adc * 5.0 / 1024.0;
    Serial.println(voltage);
    for (int i = 0; i < 9; i++)
    {
        if (voltage >= 5.0 * (i / 9.0) && voltage < 5.0 * (i + 1) / 9.0)
            tone(speakerPin, melody[i], noteDuration);
    }
}

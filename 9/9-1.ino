#include <Servo.h>

Servo myServo;
int servoPin = 11;
int btn1 = 14, btn2 = 15;
int angle = 0;
int plus = 10;
int firstState1 = 0;
int firstState2 = 0;
int secondState1 = 0;
int secondState2 = 0;
void setup()
{
    myServo.attach(servoPin);
    myServo.write(angle);
    pinMode(btn1, INPUT);
    pinMode(btn2, INPUT);
    Serial.begin(9600);
}
void loop()
{
    firstState1 = digitalRead(btn1);
    firstState2 = digitalRead(btn2);
    if (firstState1 != secondState1)
    {
        if (firstState1 == HIGH)
        {
            angle = angle + plus;
            if (angle > 180)
                angle = 180;
            myServo.write(angle);
        }
        delay(50);
        secondState1 = firstState1;
    }
    if (firstState2 != secondState2)
    {
        if (firstState2 == HIGH)
        {
            angle = angle - plus;
            if (angle < 0)
                angle = 0;
            myServo.write(angle);
        }
        delay(50);
        secondState2 = firstState2;
    }
}

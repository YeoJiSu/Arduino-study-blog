#include <SoftwareSerial.h>
// SoftwareSerial(RX,TX) 형식으로 메가2560(2번)의 핀과 교차하여 연결한다.
SoftwareSerial mySerial(4, 5);
void setup()
{
    mySerial.begin(9600); // 메가2560(2번)과의 시리얼 연결
    Serial.begin(9600);   // 컴퓨터와의 시리얼 연결
}
void loop()
{
    int reading = analogRead(A1);
    float voltage = reading * 5.0 / 1024.0;
    float temp_C = voltage * 100;
    String p = String(temp_C);
    mySerial.print(p);
    mySerial.write('\n');
    Serial.println(String(voltage) + " V : " + String(temp_C));
    delay(500);
}
HW10_slave void setup()
{
    Serial.begin(9600);
    Serial1.begin(9600);
}
char temp = '\n';
void loop()
{
    if (Serial1.available())
    {
        char data = Serial1.read();
        if (temp == '\n')
            Serial.print("Current temperature : ");
        Serial.print(data);
        temp = data;
    }
}
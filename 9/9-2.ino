int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;
int pin_button = 14;            // 버튼 연결 핀
boolean state_previous = false; // 버튼의 이전 상태
boolean state_current;          // 버튼의 현재 상태
int count = 0;                  // 버튼을 누른 횟수
int pwm_value;
void setup()
{
    pinMode(Enable1, OUTPUT);
    pinMode(PWM1, OUTPUT);
    pinMode(DIR1, OUTPUT);
    digitalWrite(Enable1, HIGH);
    pinMode(pin_button, INPUT);
    digitalWrite(DIR1, HIGH);
    digitalWrite(PWM1, HIGH);
    Serial.begin(9600);
}
void loop()
{
    state_current = digitalRead(pin_button);
    if (state_current)
    { // 버튼을 누른 경우
        if (state_previous == false)
        {            // 이전 상태와 비교
            count++; // 상태가 바뀐 경우에만 횟수 증가
            state_previous = true;
            Serial.println(count);
        }
    }
    else
    {
        state_previous = false;
    }
    if (count % 3 == 0)
    {
        pwm_value = 0;
    }
    else if (count % 3 == 1)
    {
        pwm_value = 127;
    }
    else if (count % 3 == 2)
    {
        pwm_value = 255;
    }
    analogWrite(PWM1, pwm_value);
}
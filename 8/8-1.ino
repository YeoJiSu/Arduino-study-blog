//공통음극방식입니다.
int pin_button = 14;            // 버튼 연결 핀
boolean state_previous = false; // 버튼의 이전 상태
boolean state_current;          // 버튼의 현재 상태
int count = 0;                  // 버튼을 누른 횟수
byte patterns[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
int digit_select_pin[] = {66, 67, 68};
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};
int SEGMENT_DELAY = 5;
unsigned long time_previous, time_current, time_current2;
int seconds;
void setup()
{
    Serial.begin(9600);         // 시리얼 통신 초기화
    pinMode(pin_button, INPUT); // 버튼 연결 핀을 입력으로 설정
    for (int i = 0; i < 3; i++)
    {
        pinMode(digit_select_pin[i], OUTPUT);
    }
    for (int i = 0; i < 8; i++)
    {
        pinMode(segment_pin[i], OUTPUT);
    }
    time_previous = millis();
}
void show_digit(int pos, int number)
{
    for (int i = 0; i < 3; i++)
    {
        if (i + 1 == pos)
            digitalWrite(digit_select_pin[i], LOW);
        else
            digitalWrite(digit_select_pin[i], HIGH);
    }
    for (int i = 0; i < 8; i++)
    {
        boolean on_off = bitRead(patterns[number], 7 - i);
        digitalWrite(segment_pin[i], on_off);
    }
}
void show_3_digit(int number)
{
    if (number < 0)
    {
        number = 1000 + number;
    }
    number = number % 1000;
    int hundreads = number / 100; // 백 자리
    number = number % 100;
    int tens = number / 10; // 십 자리
    int ones = number % 10; // 일 자리
    show_digit(1, hundreads);
    delay(SEGMENT_DELAY);
    show_digit(2, tens);
    delay(SEGMENT_DELAY);
    show_digit(3, ones);
    delay(SEGMENT_DELAY);
}
void loop()
{
    time_current = millis();
    if (time_current - time_previous >= 1000)
    {
        time_previous = time_current;
        seconds++; // 초 증가
    }
    show_3_digit(seconds);                   // 시간 표시를 위해 3자리 숫자로 만듦
    state_current = digitalRead(pin_button); // 버튼 상태 읽기
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
    if (count % 2 == 1)
    {
        time_current2 = millis();
        if (time_current2 - time_previous >= 1000)
        {
            time_previous = time_current;
            seconds--;
            show_3_digit(seconds);
        }
    }
}
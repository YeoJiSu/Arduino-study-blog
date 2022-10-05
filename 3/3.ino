void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  int pattern = 1, shift;
  for (int index = 1; index < 7; index++)
  {
    if (index < 4)
    {
      shift = index;
      pattern = (pattern << 1) | 0 * 01;
      digitalWrite(2, pattern);
      delay(500);
      digitalWrite(shift + 2, pattern);
    }
    else
    {
      shift = 6 - index;
      pattern = (pattern << 1) & 0 * 00;
      delay(500);
      digitalWrite(shift + 3, pattern);
    }
  }
}
int pin_button = 14;
boolean state_previous = false;
boolean state_current;
int count = 0;
int state = 0;
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
  {
    pinMode(pins_LED[i], OUTPUT);
    digitalWrite(pins_LED[i], LOW);
  }
  pinMode(pin_button, INPUT);
}
void loop()
{
  state_current = digitalRead(pin_button);
  if (state_current)
  {
    if (state_previous == false)
      count++;
    state_previous = true;
  }
  else
    state_previous = false;
  if (count % 2 == 0)
  {
    for (int i = 0; i < 4; i++)
    {
      if (i == state)
      {
        digitalWrite(pins_LED[i], HIGH);
      }
      else
      {
        digitalWrite(pins_LED[i], LOW);
      }
    }
    delay(500);
    state = (state + 1) % 4;
  }
  else
  {
    for (int i = 0; i < 4; i++)
    {
      if (i == (5 - state) % 4)
      {
        digitalWrite(pins_LED[3 - i], HIGH);
      }
      else
      {
        digitalWrite(pins_LED[3 - i], LOW);
      }
    }
    delay(500);
    state = state - 1;
    if (state < 0)
    {
      state = state + 4;
    }
    (5 - state) % 4 == ((5 - state) % 4 + 1) % 4;
  }
}
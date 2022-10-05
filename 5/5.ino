int pins_LED[]={2,3,4,5};

void setup() {

  Serial.begin(9600);

  for (int i=0; i<4 ; i++) {

    pinMode(pins_LED[i], OUTPUT);

  }

}



void loop() {

  for (int i=0; i<=255; i++){

    analogWrite(2,i);

    delay(3);

      analogWrite(3,(i+63)%255);

    delay(3);

      analogWrite(4,(i+127)%255);

    delay(3);

       analogWrite(5,(i+191)%255);

    delay(3);

    }

  

}
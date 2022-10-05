void setup() {
  Serial.begin(9600); 
}
void loop() {
  int state=1, len=0, i=0;
  char buffer[128];
  String str[5];
  while (i<5) {
    if (state==1) {
      Serial.print("Enter the "+String(i+1)+"th Word -->");
      state=2;
    }
    while (Serial.available()) {
  char data= Serial.read();
  if (data=='\n'){
    buffer[len]= '\0';
    String in_str = buffer;
    str[i]=in_str;
    Serial.println(in_str);
    state=1;
    len=0;
    i=i+1;
    break;
  }
  buffer[len++]= data;
  }
  if (i==5) {
    Serial.println("After Sorting");
    for (int i = 0; i<4; i++) {
    for (int j=i+1; j<5; j++) {
      int compare = str[i].compareTo(str[j]);
      if (compare > 0){
        String temp = str[i];
        str[i]= str[j];
        str[j]= temp;
      }
    }
   }
    for (int i=0; i<5; i++){
    Serial.println(str[i]);
    }
    break;
  }
 }
}

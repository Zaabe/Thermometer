void setup() {

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.000 / 1023.000);

  Serial.println(voltage);
  //0.038 V = 131.5 KOhm --> 21° C & 0.046 V = 108.88 KOhm --> 27° C
  if(voltage >= 0.038 && voltage <= 0.046) {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
  }

  else if(voltage < 0.038) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
   
  else if(voltage > 0.046) {
    //0.137 V = 36.42 KOhm --> 50° C
    if(voltage > 0.137){
      for(int i = 0; i < 10; i++){
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      delay(300);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      i++;
      delay(300);
      }
    }
    digitalWrite(11, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
 
  else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
  delay(30000);
}

int buzzer = 10;
int green = 12;
int red = 11;
int blue = 13;

void setup() {

  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

float getVoltage(){
  float voltage = analogRead(A0) * (5.000 / 1023.000);
  return voltage;
}

void turnPDWOn(char led){
  if (led == 'r'){
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
  else if (led == 'g'){
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  else if (led == 'b'){
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  }
  else if (led == 'f'){
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);

    for(int i = 0; i < 10; i++){
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }
  }
  else{
    exit(1);
  }
}

void loop() {
  float voltage = (float)getVoltage();
  Serial.println(voltage);
  if(voltage > 0.038) {
    if (voltage < 0.046){
      turnPDWOn('g');
    }
    else if (voltage < 0.137){
      turnPDWOn('r');
    }
    else if(voltage >= 0.137){
      turnPDWOn('f');
    }
  }

  else{
    turnPDWOn('b');
  }
  delay(500);
}

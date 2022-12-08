int ledPin = 10;
int potPin = A2;
int ledPin2 = 9;
int potPin2 = A1;
int potVal;
int potVal2;
int dt = 200;
int light;
int light2;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(potVal, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  Serial.println(light);
  light = map(potVal,0,1023,0,255);
  analogWrite(ledPin, light);
  potVal2 = analogRead(potPin2);
  Serial.println(potVal2);
  Serial.println(light2);
  light2 = map(potVal2,0,1023,0,255);
  analogWrite(ledPin2, light2);
  delay(dt);
}

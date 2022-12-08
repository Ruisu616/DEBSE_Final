int led = 13;
void setup() {
  // put your setup code here, to run once:
 pinMode(led,OUTPUT);
 Serial.begin(9600);
 Serial.setTimeout(1000); //ms por defeecto = 1000
}

String v;
int estado_led;
void loop() {
  // put your main code here, to run repeatedly:

 if(Serial.available()>0){
    v = Serial.readString();
    estado_led = v.toInt();
    Serial.println(v);
    digitalWrite(led, estado_led);
  }
}

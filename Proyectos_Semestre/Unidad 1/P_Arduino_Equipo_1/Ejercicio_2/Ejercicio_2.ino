void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial.setTimeout(1000); //ms por defeecto = 1000
}

String v;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    v = Serial.readString();
    Serial.println(v);
  }
  
}

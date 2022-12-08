int led = 13;
void setup(){

pinMode(led, OUTPUT); 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,1);
delay(1000);
digitalWrite(led,0);
delay(1000);
}

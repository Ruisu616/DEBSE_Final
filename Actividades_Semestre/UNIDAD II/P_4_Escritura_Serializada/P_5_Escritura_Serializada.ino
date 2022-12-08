int leds[] = {10,11,12};
int actuadores[] = {A0, A1, A2};
String cad_aux = "E";
int valorTemporal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  valorTemporal = analogRead(actuadores[0]);
  cad_aux += String(valorTemporal) + 'A';

    valorTemporal = analogRead(actuadores[1]);
  cad_aux += String(valorTemporal) + 'A';

    valorTemporal = analogRead(actuadores[2]);
  cad_aux += String(valorTemporal) + 'F';

  Serial.println(cad_aux);
  cad_aux = "E";
 delay(1000);

}

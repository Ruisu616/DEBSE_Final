int potenciometros[] = {A0,A1,A2,A3,A4,A5};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

String cad_aux = "E";
int valorTemporal;
String aux;
void loop() {
     for(int i = 0; i < 6; i++)
     {
      valorTemporal = analogRead(potenciometros[i]);
      cad_aux += String(valorTemporal) + "G";
     }
     cad_aux += "F";
     Serial.println(cad_aux);
     delay(1000);
     cad_aux = "E";
  // put your main code here, to run repeatedly:

}

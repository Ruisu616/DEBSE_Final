int leds[] = {10,11,12};
int actuadores[] = {A0, A1, A2};
String cad_aux = "E";
int valorTemporal;
String aux;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  valorTemporal = analogRead(actuadores[0]);
  aux = agregarCeros(valorTemporal);
  cad_aux += String(valorTemporal) + 'A';

    valorTemporal = analogRead(actuadores[1]);
    aux = agregarCeros(valorTemporal);
  cad_aux += String(valorTemporal) + 'A';

    valorTemporal = analogRead(actuadores[2]);
    aux = agregarCeros(valorTemporal);
  cad_aux += String(valorTemporal) + 'F';

  Serial.println(cad_aux);
  cad_aux = "E";
 delay(1000);

}

String agregarCeros(int numero)
{
  String numConCeros;

  if (numero.length() == 1){

    numConCeros +=  "000" + String(numero);
    
    }
    
  if (numero.length() == 2){

    numConCeros +=  "00" + String(numero);
    
    }
  if (numero.length() == 3){

    numConCeros +=  "0" + String(numero);
    
    }
    else{
      numConCeros += String(numero);
      }

    

  return numConCeros;
}

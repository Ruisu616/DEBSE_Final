int leds[] = {10,11,12};
String cadena = "E0095A0240A0000F";
String cad_aux = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop() {
  // put your main code here, to run repeatedly:
 delay(1000);
  if(Serial.available()>0)
  {
    cadena = Serial.readString();
  }
  

  if(cadena.charAt(0) == 'E' && cadena.charAt(15) == 'F'){
    Serial.println("Cadena completa");
    {
  for(int i = 1; i<cadena.length()-1; i++)
  {
    if(cadena[i] != 'A'){
    cad_aux += cadena[i];
  }else //caracter leido sea 'A'
  {
    Serial.println(cad_aux);
    cad_aux = "";
  }
  
  }
  Serial.println(cad_aux); //E0080A0150A0010F
    }
  while(true){}
 
}
}

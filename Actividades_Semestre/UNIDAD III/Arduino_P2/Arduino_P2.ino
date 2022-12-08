int potenciometro = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


int valor = 0;
int contador = 0;
void loop() {
  // put your main code here, to run repeatedly:
  valor += analogRead(potenciometro);
  contador++;

  if(conttador == 10)
  {
    valor /= contador;
    Serial.println(valor);

    valor = 0;
    contador = 0;
  }

  delay(10);
}

int pulsador = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pulsador,INPUT_PULLUP);
}
int valor;
void loop() {
  // put your main code here, to run repeatedly:
  valor = digitalRead(pulsador);
  Serial.print(valor);
  delay(1000);
}

int potenciometro = A1;
int led1 = 9, brillo1,vled1 = 0;
int valor, mapeado;
String cadena,cad1,cad2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int promSensor1 = 0;
int promSensor2 = 0;

#define separador '-'
String campo;
int inicio, fin;
int auxiliar[2];
int pos;

void loop() {
  // put your main code here, to run repeatedly:
  valor = analogRead(potenciometro);
  promSensor1 = valor;
  promSensor2 = valor;
  //Serial.println(String(valor));
  //map(value,fromLOW,fromHIGH,toLOW,toHIGH);
  //mapeado = map(valor, 0, 1023, 0, 3);
 //Serial.println(String(valor)+" = "+String(mapeado));
  Serial.println(String(1)+"-"+String(promSensor1)+"-"+String(promSensor2));
  delay(100);
  if(Serial.available()){
    cadena = Serial.readString();
    pos = cadena.indexOf(",");
    cad1 = cadena.substring(0,pos);
    cad2 = cadena.substring(pos+1);
    if (vled1 != cad1.toInt()){
      vled1 = cad1.toInt();
      analogWrite(led1, vled1);
    }
  }
  delay(100);
}

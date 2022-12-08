int potenciometro = A1;
int potenciometro2 =  A2;
int led1 = 9, brillo1,vled1 = 0;
int led2 = 10, brillo2,vled2 = 0;
int valor,valor2, mapeado;
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
  valor2 = analogRead(potenciometro2);
  promSensor1 = valor;
  promSensor2 = valor2;
  //Serial.println(String(valor));
  //map(value,fromLOW,fromHIGH,toLOW,toHIGH);
  //mapeado = map(valor, 0, 1023, 0, 3);
  //Serial.println(String(valor)+" = "+String(mapeado));
  Serial.println(String("P1")+" = "+String(promSensor1)+" | "+String("P2")+" = "+String(promSensor2)+".");
  delay(10);
  if(Serial.available()){
    cadena = Serial.readString();
    pos = cadena.indexOf(",");
    cad1 = cadena.substring(0,pos);
    cad2 = cadena.substring(pos+1);
    if (vled1 != cad1.toInt()){
      vled1 = cad1.toInt();
      analogWrite(led1, vled1);
    }
    if (vled2 != cad2.toInt()){
      vled2 = cad2.toInt();
      analogWrite(led2, vled2);
    }
  }
  delay(10);
}
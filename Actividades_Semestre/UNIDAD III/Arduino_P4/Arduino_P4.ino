int sensor1 = A1;
int sensor2 = A2;
int led1 = 9;
int led2 = 10;
int vled1;
int vled2;
int vectorLecturas[11];


void setup() {
  // put your setup code here, to
  Serial.begin(9600);
}

int contador = 0;
int promSensor1 = 0;
int promSensor2 = 0;
String cad;
int pos;

void loop() {

    promSensor1 += analogRead(sensor1);
    promSensor2 += analogRead(sensor2);
    contador++;
 
  if(contador == 10)
  {
    promSensor1 /= contador;
    promSensor2 /= contador;


    
    Serial.println(String(promSensor1)+"-"+String(promSensor2)); //mediana

    if(Serial.available())
    {
      cad = Serial.readString();
      int pos = cad.indexOf('-');

      vled1 = cad.substring(0, pos).toInt();
      vled2 = cad.substring(pos+1).toInt();
      }
    
    //se reinicia los auxiliares
    analogWrite(led1, vled1);
    analogWrite(led2, vled2);
    contador = 0;
    promSensor1 = 0;
    promSensor2 = 0;
  }

  delay(10);
}

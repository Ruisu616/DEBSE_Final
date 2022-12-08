int potenciometro = A0;

int vectorLecturas[11];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


int contador = 0;
void loop() {
  // put your main code here, to run repeatedly:
  vectorLecturas [contador]= analogRead(potenciometro);
  contador++;

  if(conttador == 10)
  {
    //ordenar de mayor a menor o vizceversa

    for(int i = 0; i<11-1; i++)
    {
      for(int j = i+1; i<11; j++)
      {
        if vectorLecturas[i]<vectorLecturas[j]
        {
          int aux = vectorLecturas[i];
          vectorLecturas[i] = vectorLecturas[j];
          vectorLecturs[j] = aux;
        }
      }
    }
    Serial.println(5);
    contador = 0;
  }

  delay(10);
}

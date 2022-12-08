int leds[] = {10, 11, 12, 13};

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);

  for(int i = 0; i<4; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

String v;
int estado_led;
void loop(){

  if(Serial.available()>0)
  {
    v = Serial.readString();
    for(int i = 0; i<4; i++)
    {
      if(v == i)
      {
        digitalWrite(leds[i], HIGH);
      }
      else
      {
        digitalWrite(leds[i], LOW);
      }
    }
  }
}



//que es un entorno
//que es ambiente
//que es sistema inteligente
//que es un entorno inteligente
//en que consiste el proceso de toma de desiciones en un sistema
//que es la interacción centrada en el usuario
//que es el internet de la cosas
//que es una tecnica de computacion avanzada
//en que consiste el concepto de domótica
// en que consiste el concepto de inmótica
//en que consiste el concepto de ciudades inteligentes
//que es un microcontrolador
//cuales son las caracteristicas del atmega 328p
//cual es la diferencia entre un microntrolador y un microprocesador
//5 trabajos en lo que se solicite conocimiento de programación de sistemas embebidos
//***sistemas embebebidos, caracteristicas y aplicaciones practicas en la actualidad

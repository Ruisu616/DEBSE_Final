int n, media, prom;
float res;


void setup() {
  Serial.begin(9600);
}


void loop() {
  media = 0;
  Serial.println ("Ingrese el número de elementos");
  while (!Serial.available()); // Esperamos a que entre algo por el serial.
  n = (Serial.readString()).toInt(); //recoge el numero de datos
  Serial.print ("Ingrese los valores ");
  Serial.println (n);
  int numeros [n]; //creamos una matriz de n variables
  // lectura de n datos
  for (int x = 0; x <= n - 1; x++) {
    Serial.print ("Dato ");
    Serial.print (x + 1);
    Serial.print (" = ");
    while (!Serial.available()); // Esperamos a que entre algo por el serial.
    
    numeros [x] = (Serial.readString()).toInt(); //Memoriza los datos
    Serial.println (numeros [x]);
  }
  for (int x = 0; x <= n - 1; x++) { //suma todos los datos
    prom = prom + numeros[x];
  }
  Serial.print ("Promedio: ");
  res = prom/n;
  Serial.println (res);
  Serial.println ();
  Serial.println ();
}

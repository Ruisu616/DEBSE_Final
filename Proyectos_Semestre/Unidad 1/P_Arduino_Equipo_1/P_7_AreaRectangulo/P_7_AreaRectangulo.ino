int b, h;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
}

int estado = 0;
int v;
void loop() {
  // put your main code here, to run repeatedly:
    if(estado==0)
    {
     Serial.println("Ingrese la base");  
     estado = 1;
    }
     if(estado==2)
    {
     Serial.println("Ingrese la altura");  
     estado = 3;
    }
  if(Serial.available()>0)//Si hay informacion
  {
    
          v = Serial.readString().toInt();
              
     if(estado==1)
    {
          b = v;
         estado = 2;
    }
   else if(estado==3)
    
    {
      delay(3000);    
      h = v;
      estado = 4;
    }

  }
      if(estado == 4)
  {
    
    Serial.println("La area es igual: " + String(b*h));
    estado = 0;
  }
}

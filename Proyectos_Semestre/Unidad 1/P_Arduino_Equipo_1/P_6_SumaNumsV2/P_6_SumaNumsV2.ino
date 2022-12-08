int num1, num2;

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
     Serial.println("Ingrese v1");  
     estado = 1;
    }
     if(estado==2)
    {
     Serial.println("Ingrese v2");  
     estado = 3;
    }
  if(Serial.available()>0)//Si hay informacion
  {
    
          v = Serial.readString().toInt();
              
     if(estado==1)
    {
          num1 = v;
         estado = 2;
    }
   else if(estado==3)
    
    {
      delay(3000);    
      num2 = v;
      estado = 4;
    }

  }
      if(estado == 4)
  {
    
    Serial.println("La suma es igual: " + String(num1+num2));
    estado = 0;
  }
}



//hacer un programa que calcule el are de un rectangulo 
//programa que calcule el promedio de 4 numeros

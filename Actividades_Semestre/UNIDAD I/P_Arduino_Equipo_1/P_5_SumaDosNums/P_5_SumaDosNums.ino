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

  if(Serial.available()>0)//Si hay informacion
  {
    v = Serial.readString().toInt();
    
    if(estado==0)
    {
      num1 = v;
      estado = 1;
    }else if(estado==1)
    {
      num2 = v;
      estado = 2;
    }
  }
  if(estado == 2)
  {
    Serial.println(String(num1+num2));
    estado = 0;
  }

}

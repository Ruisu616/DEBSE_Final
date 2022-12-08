int pulsadores[] = {10,11}; //n-1
int n;
void setup() {
  // put your setup code here, to run once:
   for(int i = 0; i<n; i++)
  {
    pinMode(pulsadores[i],INPUT_PULLUP);
  }
  Serial.begin(9600);
}


String vals = "";

void loop() {
  // put your main code here, to run repeatedly:
  vals = "";
  for(int i = 0; i<n; i++)
  {
    vals += String(digitalRead(pulsadores[i]));
  }
  Serial.println(vals);
  delay(10);
}

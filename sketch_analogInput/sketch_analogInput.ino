int value=0;
void setup()
{
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0){
    value=Serial.parseInt();
    Serial.print("received: ");
    Serial.println(value,DEC);
      analogWrite(9,value*26);
      delay(20);
  }
}


int buzzerPin =9;

void setup()  
{
  pinMode(buzzerPin, OUTPUT);
  delay(1000);
  Serial.println("Buzzer Ready");
} 

void loop()  
{ 
  analogWrite(buzzerPin, 25);      // value between 0 and 255
  delay(200);
  analogWrite(buzzerPin, 0);       // turn off
  delay(250);
}

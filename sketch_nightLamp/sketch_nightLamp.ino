int lightPin = 0;  //define a pin for Photo resistor
int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=6;
int led6=7;
int voltage;

void setup()
{
  Serial.println("Calibrating");  
  delay(1000);   //Calibrate to ambient environment
  Serial.begin(9600);  //Begin serial communcation
  Serial.println("Sensor Active");  
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);  
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);  
  pinMode(led6, OUTPUT); 
}

void loop()
{  
    voltage=analogRead(lightPin);
    Serial.println(voltage); //Write the value of the photoresistor to the serial monitor.
    if(voltage>600)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
    }
    else
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
    }
    delay(1000);
}



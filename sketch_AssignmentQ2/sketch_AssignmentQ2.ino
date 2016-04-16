int ldrPin = A0;  //define a pin for Photo resistor
int voltage;

void setup()
{
  Serial.begin(9600);  
  Serial.println("Sensor Active");  
}

void loop()
{  
    voltage=analogRead(ldrPin);
    Serial.println(voltage); //Write the value of the photoresistor to the serial monitor.    
    delay(150);
    
}



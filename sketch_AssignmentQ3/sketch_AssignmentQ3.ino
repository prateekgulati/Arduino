int tempPin = A0;  //define a pin for Photo resistor
float voltage;
float variable;

void setup()
{
  Serial.println("Calibrating");  
  delay(500);   //Calibrate to ambient environment
  Serial.begin(9600);  //Begin serial communcation
  Serial.println("Sensor Active");  }

void loop()
{  
    voltage=analogRead(tempPin);
    variable=voltage*(5000/1024);
    Serial.println(variable/10);
    delay(1000*60);   // delay of 60 seconds
}

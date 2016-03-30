int tempPin = 0;  //define a pin for Photo resistor
float voltage;
float variable;

void setup()
{
  Serial.println("Calibrating");  
  delay(1000);   //Calibrate to ambient environment
  Serial.begin(9600);  //Begin serial communcation
  Serial.println("Sensor Active");  }

void loop()
{  
    voltage=analogRead(tempPin);
    variable=voltage*(5000/1024);   //voltage in mv (analog_reading)*500/1024)
    Serial.println(variable/10);    //centigradeTemp=analog_in_MV/10
    delay(100);
}


/*
 * To store data from sensor 
 * use coolTerm software
 */

int lightPin = 0;  //define a pin for Photo resistor
int led1=3;
int led2=5;
int led3=6;
int led4=9;
int led5=10;
int led6=11;
float voltage;
float variable;

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
    variable=((voltage-90)/800)*1000;
      analogWrite(led1, variable/5);
      analogWrite(led2, variable/5);
      analogWrite(led3, variable/5);
      analogWrite(led4, variable/5);
      analogWrite(led5, variable/5);
      analogWrite(led6, variable/5);
    delay(10);
}



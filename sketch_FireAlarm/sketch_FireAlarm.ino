int tempPin = 0;  //define a pin for LM35
int led =8;       //define a pin for Led
int buzzer =9;    //define a pin for Buzzer
float voltage, temp, variable;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);  //Begin serial communcation
  Serial.println("Calibrating");  
  delay(1000);         //Calibrate to ambient environment
  Serial.println("Sensor Active");  
}

void loop()
{  
    voltage=analogRead(tempPin);
    variable=voltage*(5000/1024);
    temp=variable/10;
    Serial.println(temp);
    if(temp>50)        //Temperature threshold
    {
      digitalWrite(led,HIGH);    //LED blink
      analogWrite(buzzer, 50);   //Buzzer beeps
      delay(1000);
      analogWrite(buzzer, 0);
      digitalWrite(led,LOW);
      delay(1000);
    }
}

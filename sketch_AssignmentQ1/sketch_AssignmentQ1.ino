int ledPin1 = 9; 
int ledPin2 = 10; 
int inPin = 7;   
int counter=0;
unsigned long currTime;
unsigned long initialTime=0;
int buttonState = 0;
int lastButtonState = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);  
  pinMode(inPin, INPUT);    
}

void loop(){

  buttonState = digitalRead(inPin); 
  currTime = millis()-initialTime;  //to avoid reset each time
  Serial.println(currTime);
  Serial.println(counter);

  if (buttonState != lastButtonState) 
  {
    if (buttonState == HIGH && currTime<5000) 
    {
      counter++;
      delay(20);    
    }
    lastButtonState = buttonState;
  }
  if(currTime>5000)
  {
    if(counter%2==0)
    {
      while(counter)
      {
        digitalWrite(ledPin1, HIGH);
        delay(250) ;
        digitalWrite(ledPin1, LOW);
        delay(250);
        counter=counter-1;
      }
    }
   if(counter%2!=0)
   {
     while(counter){
     digitalWrite(ledPin2, HIGH);
     delay(250) ;
     digitalWrite(ledPin2, LOW);
     delay(250);
     counter=counter-1;
   }
  }
  if(currTime>5000)
  {
    initialTime=millis();
    counter=0;
  }
  delay(100);
  }
}


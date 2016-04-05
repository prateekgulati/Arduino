const int  buttonPin = 2;   
const int ledPin1 = 10;  
const int ledPin2 = 11;
const int ledPin3 = 12;
int ldrPin = A0;    
float voltage=0.0;
float variable=0.0;


int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;     

void setup() {
  // initialize
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);   //serial communication:
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) 
  {
    if (buttonState == HIGH) 
    {
      buttonPushCounter++;    //Increment button counter
      Serial.println("on");
      Serial.print("number of times button pushed:");
      Serial.println(buttonPushCounter);
      attachInterrupt(0,blink_Led,CHANGE);  
    }
    else
    {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;
  
}

void blink_Led()
{
  Serial.println("interrupt");
  voltage=analogRead(ldrPin);
  voltage=voltage/5;
  if (buttonPushCounter % 3 == 0) 
  {
    analogWrite(ledPin1, voltage);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
  }
  else if (buttonPushCounter % 3 == 1) 
  {
    analogWrite(ledPin2, voltage);
    analogWrite(ledPin1, 0);
    analogWrite(ledPin3, 0);
  }
  else if (buttonPushCounter % 3 == 2) 
  {
    analogWrite(ledPin3, voltage);
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
  }
  delay(1000);
}

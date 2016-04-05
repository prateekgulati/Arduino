int  buttonPin = 7;    // pin for push button
int ledPin1 = 10;       // pin for LED
int ledPin2 = 11;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);  //Initialise pin mode
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
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
    }
    else
    {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0)   //both LEDs toggle states on pressing button
  {
    digitalWrite(ledPin1, HIGH);   
    digitalWrite(ledPin2, LOW); 
  }
  else
  {
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, HIGH); 
  }
}

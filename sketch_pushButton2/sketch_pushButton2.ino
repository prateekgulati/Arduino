int  buttonPin = 7;    // pin for push button
int ledPin = 10;       // pin for LED

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);  //Initialise pin mode
  pinMode(ledPin, OUTPUT);
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

  if (buttonPushCounter % 2 == 0)   //LED toggles state on every button pressed
  {
    digitalWrite(ledPin, HIGH);   
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

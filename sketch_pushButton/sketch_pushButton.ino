int ledPin = 12; 
int inPin = 7;   
int val = 0;     

void setup() {
  pinMode(inPin, INPUT);    
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inPin); 
  if (val == LOW) 
  {
    Serial.println("Pushbutton not pressed");
  } 
  else 
  {
    Serial.println("Pushbutton pressed");
  }
  delay(300);
}

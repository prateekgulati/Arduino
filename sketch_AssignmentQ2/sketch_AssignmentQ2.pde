import processing.serial.*;
Serial myPort;
String val;

void setup()
{
  size(500,500);
  myPort=new Serial(this,Serial.list()[0],9600);
  background(255,255,255);
}

void draw()
{  
  if ( myPort.available() > 0) 
  {
    val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
   
  if(val==null)
    val="0";
    
  val = trim(val);
  println(val);
  
  try
  {
    int valInt=Integer.parseInt(val);
    float bgcolor=map(valInt,0,1000,0,255);
    print(bgcolor);
    background(255-bgcolor,0,0);
  }
  
  catch (NumberFormatException e) {
    println("can't be converted to a number!");
  }
  
}
PFont font;
float xPos = 0;   // horizontal position of the graph
float yPos = 0;   // vertical position of the graph
import processing.serial.*;
Serial myPort;
String val;
float tempCelsius,prevTempCelsius=0.0;
float tempFahrenheit,prevTempFahrenheit=0.0;

void setup () {
  size(750,600); 
  myPort=new Serial(this,Serial.list()[0],9600);  
  background(255);
  graph();
}

void graph(){
  strokeWeight(2);
  stroke(0,0,0);
  line(xPos+200-2, 200, xPos+200-2, height-50);
  line(xPos+200-2, 200, xPos+200-2-10, 200+20);
  line(xPos+200-2, 200, xPos+200-2+10, 200+20);
  line(width/2+200, height-50, xPos+200-2, height-50);
  line(width/2+200, height-50, width/2+200-20, height-50+10);
  line(width/2+200, height-50, width/2+200-20, height-50-10);
  fill(0);
  pushMatrix();
  translate(500,500);
  rotate(-HALF_PI);
  font = createFont ("Serif",30);
  textFont(font);
  text("Temperature (°C)",0,-320);
  popMatrix();
  text("Time (mins)",width/3+50,height-15);
  font = createFont ("Serif",40);
  textFont (font);
  textAlign(CENTER,CENTER);
  text("Celsius",width/3-100,height/6);
  text("Fahrenheit",2*width/3,height/6);
}


void draw () {  
  if ( myPort.available() > 0) 
  {
    val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
   
  if(val==null)
    val="0";
  val = trim(val);
  
  try
  {
    fill(255);
    text(prevTempCelsius,width/3+50,height/6);
    text(prevTempFahrenheit,2*width/3+150,height/6);
    fill(0);
    float valFloat=Float.parseFloat(val);
    tempCelsius=valFloat;
    tempFahrenheit=tempCelsius*9/5 + 32;
    text(tempCelsius,width/3+50,height/6);
    text(tempFahrenheit,2*width/3+150,height/6);

    println(valFloat);
    stroke(tempCelsius*5,tempCelsius*10,tempCelsius*2);
    if(xPos!=0&&yPos!=0)
      line(xPos+200, height-50, xPos+200, yPos-50); // (x1,y1,x2,y2) Origin located at top left corner
  
    // at the edge of the screen, go back to the beginning:
    if (xPos >= width/2-50) {
      fill(0);
      textAlign(CENTER,CENTER);
      text("Celsius",width/3,height/6);
      text("Fahrenheit",2*width/3,height/6);
      xPos = 0;
      // clear the screen by resetting the background:
      background(255);
      graph();
    }
    else if (tempCelsius>0){
    // increment the horizontal position for the next reading:
      xPos=xPos+5;
    }
    yPos = height - tempCelsius*10 +100;
    
  }
  
  catch (NumberFormatException e) {
    println("can't be converted to a number!");
  }
  prevTempCelsius=tempCelsius;
  prevTempFahrenheit=tempFahrenheit;
  delay(1000*60);  // delay of 60 seconds
}
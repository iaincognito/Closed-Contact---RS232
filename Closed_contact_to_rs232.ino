/*A wee bit of code that detects 6 different closed contact circuits
 * and issues 8-bit commands via rs-232(linksprite rs232 shield using Max3232 chip.) The specific application is to
 * allow operation of the preview function on a Sony RCP-1500 with a Sierra 
 * Video Systems Lassen HD 32x32 SDI router. E.g. When the preview button
 * on camera 6 is pressed, the router switches the Engineer's monitor to 
 * camera 6's signal. When preview on camera 6 is pressed again, PGM is switched to the Engineer's Monitor
 * 
 * written March 29, 2016
 * updated April 4, 2016
 * updated June 9,2016 to switch to different crosspoint on router on double press
 * by Iain Donham 
 * iain.donham@gmail.com
 * www.i-need-video.com
 * 
 * Copyright 2016, Iain Donham, All Rights Reserved
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
int c1In = 4; //orange
int c2In = 5; //green
int c3In = 6; //blue
int c4In = 7; //brown
int c5In = 8; //blue 2
int c6In = 9; //brown 2


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("USB Ready");
  
   // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("**!!");
  

  pinMode(c1In, INPUT_PULLUP); //sets the digital pin 4 as input pullup
  pinMode(c2In, INPUT_PULLUP); //sets the digital pin 5 as input pullup
  pinMode(c3In, INPUT_PULLUP); //sets the digital pin 6 as input pullup
  pinMode(c4In, INPUT_PULLUP); //sets the digital pin 7 as input pullup
  pinMode(c5In, INPUT_PULLUP); //sets the digital pin 8 as input pullup
  pinMode(c6In, INPUT_PULLUP); //sets the digital pin 9 as input pullup
}

  boolean c1Live = false;
  boolean c2Live = false;
  boolean c3Live = false;
  boolean c4Live = false;
  boolean c5Live = false;
  boolean c6Live = false;
  
void loop() { // run over and over
  

  if(Serial.available()){
    mySerial.write(Serial.read());
  };
  if(mySerial.available()){
    Serial.write(mySerial.read());
  }
 
  int c1Val = digitalRead(c1In);//read pin 4 digital input
  int c2Val = digitalRead(c2In);//read pin 5 digital input
  int c3Val = digitalRead(c3In);//read pin 6 digital input
  int c4Val = digitalRead(c4In);//read pin 7 digital input
  int c5Val = digitalRead(c5In);//read pin 8 digital input
  int c6Val = digitalRead(c6In);//read pin 9 digital input

   if(c1Val == LOW) {
      if(c1Live == false){
      mySerial.println("**y32,1!!");
      c1Live = true;
      c2Live = false;
      c3Live = false;
      c4Live = false;
      c5Live = false;
      c6Live = false;
      }else if(c1Live == true) {
        mySerial.println("**y32,30!!");
        c1Live = false;
        c2Live = false;
        c3Live = false;
        c4Live = false;
        c5Live = false;
        c6Live = false;
      }
      delay(250);
      
  } else if (c2Val == LOW) {
     if(c2Live == false){
      mySerial.println("**y32,2!!");
      c1Live = false;
      c2Live = true;
      c3Live = false;
      c4Live = false;
      c5Live = false;
      c6Live = false;
      }else if(c2Live == true) {
        mySerial.println("**y32,30!!");
        c1Live = false;
        c2Live = false;
        c3Live = false;
        c4Live = false;
        c5Live = false;
        c6Live = false;
      }
      delay(250);
    
  } else if (c3Val == LOW) {
    if(c3Live == false){
      mySerial.println("**y32,3!!");
      c1Live = false;
      c2Live = false;
      c3Live = true;
      c4Live = false;
      c5Live = false;
      c6Live = false;
      }else if(c3Live == true) {
        mySerial.println("**y32,30!!");
        c1Live = false;
        c2Live = false;
        c3Live = false;
        c4Live = false;
        c5Live = false;
        c6Live = false;
      }
      delay(250);
    
  } else if (c4Val == LOW) {
    if(c4Live == false){
      mySerial.println("**y32,4!!");
      c1Live = false;
      c2Live = false;
      c3Live = false;
      c4Live = true;
      c5Live = false;
      c6Live = false;
      }else if(c4Live == true) {
        mySerial.println("**y32,30!!");
        c1Live = false;
        c2Live = false;
        c3Live = false;
        c4Live = false;
        c5Live = false;
        c6Live = false;
      }
      delay(250);
    
  } else if (c5Val == LOW) {
    if(c5Live == false){
      mySerial.println("**y32,5!!");
      c1Live = false;
      c2Live = false;
      c3Live = false;
      c4Live = false;
      c5Live = true;
      c6Live = false;
      }else if(c5Live == true) {
        mySerial.println("**y32,30!!");
        c1Live = false;
        c2Live = false;
        c3Live = false;
        c4Live = false;
        c5Live = false;
        c6Live = false;
      }
      delay(250);;
    
   }else if (c6Val == LOW) {
    if(c6Live == false){
      mySerial.println("**y32,6!!");
      c1Live = false;
      c2Live = false;
      c3Live = false;
      c4Live = false;
      c5Live = false;
      c6Live = true;
      }else if(c6Live == true) {
        mySerial.println("**y32,30!!");
        c1Live = false;
        c2Live = false;
        c3Live = false;
        c4Live = false;
        c5Live = false;
        c6Live = false;
      }
      delay(250);
    
  }
 
 
}


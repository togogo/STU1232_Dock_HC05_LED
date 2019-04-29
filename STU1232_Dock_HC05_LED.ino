#include <SoftwareSerial.h>

#define MONDAY 2
#define TUESDAY 3
#define WEDNESDAY 4
#define THURSDAY 5
#define FRIDAY 6
#define SATURDAY 7
#define SUNDAY 8

int monBrightness = 0;
int tueBrightness = 0;
int wedBrightness = 0;
int thuBrightness = 0;
int friBrightness = 0;
int satBrightness = 0;
int sunBrightness = 0;

bool mon = false;
bool tue = false;
bool wed = false;
bool thu = false;
bool fri = false;
bool sat = false;
bool sun = false;
 
SoftwareSerial BTS(10, 11); // RX | TX
char c;//for incoming signal
 
void setup()
{
  Serial.begin(9600);
  BTS.begin(9600);  // HC-05 FC-114 default speed in AT command more

  //LED part
  pinMode(MONDAY, OUTPUT);
  pinMode(TUESDAY, OUTPUT);
  pinMode(WEDNESDAY, OUTPUT);
  pinMode(THURSDAY, OUTPUT);
  pinMode(FRIDAY, OUTPUT);
  pinMode(SATURDAY, OUTPUT);
  pinMode(SUNDAY, OUTPUT);
}
 
void loop()
{

 analogWrite(MONDAY, monBrightness);
 analogWrite(TUESDAY, tueBrightness);
 analogWrite(WEDNESDAY, wedBrightness);
 analogWrite(THURSDAY, thuBrightness);
 analogWrite(FRIDAY, friBrightness);
 analogWrite(SATURDAY, satBrightness);
 analogWrite(SUNDAY, sunBrightness);
 
  // Read from HC-05 and send it to Arduino Serial Monitor
  //this sends serial signal from PC -> Arduino
  //Going to use this to turn on the LED Lamp
  if (BTS.available()) {
    c = BTS.read();
    //Serial.println(c);
    //Bluetooth.println(c);

    if (c == '0') {
      if(mon == true){
        mon = false;
        monBrightness = 0;
        BTS.println("MONDAY is OFF");
      }else if(mon == false){
        mon = true;
        monBrightness = 255;
        BTS.println("MONDAY is ON");
      }
      
    }
    if (c == '1') {
      if(tue == true){
        tue = false;
        tueBrightness = 0;
        BTS.println("TUESDAY is OFF");
      }else if(tue == false){
        tue = true;
        tueBrightness = 255;
        BTS.println("TUESDAY is ON");
      }
    }
    if (c == '2') {
      if(wed == true){
        wed = false;
        wedBrightness = 0;
        BTS.println("WEDNESDAY is OFF");
      }else if(wed == false){
        wed = true;
        wedBrightness = 255;
        BTS.println("WEDNESDAY is ON");
      }
    }
    if (c == '3') {
      if(thu== true){
        thu = false;
        thuBrightness = 0;
        BTS.println("THURSDAY is OFF");
      }else if(thu == false){
        thu = true;
        thuBrightness = 255;
        BTS.println("THURSDAY is ON");
      }
    }
    if (c == '4') {
      if(fri== true){
        fri = false;
        friBrightness = 0;
        BTS.println("FRIDAY is OFF");
      }else if(fri == false){
        fri = true;
        friBrightness = 255;
        BTS.println("FRIDAY is ON");
      }
    }
    if (c == '5') {
      if(sat== true){
        sat = false;
        satBrightness = 0;
        BTS.println("SATURDAY is OFF");
      }else if(sat == false){
        sat = true;
        satBrightness = 255;
        BTS.println("SATURDAY is ON");
      }
    }
    if (c == '6') {
      if(sun== true){
        sun = false;
        sunBrightness = 0;
        BTS.println("SUNDAY is OFF");
      }else if(sun == false){
        sun = true;
        sunBrightness = 255;
        BTS.println("SUNDAY is ON");
      }
    }
  }
  /*
  if (BTS.available())
  {
    Serial.write(BTS.read());
  }
 
  // Read from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTS.write(Serial.read());
    */
    
}

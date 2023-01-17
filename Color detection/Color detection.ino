#include <Pixy2.h>
#include <stdio.h>
#include <Servo.h> 

Pixy2 pixy;


Servo sg90;
int pozisyon=0;
int pos=0;



void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  
  pixy.init();
  
  pixy.changeProg("video");
  sg90.attach(9);
  
}

void loop()
{ 
  uint8_t r, g, b; 
  
  
  
  if (pixy.video.getRGB(pixy.frameWidth/2, pixy.frameHeight/2, &r, &g, &b)==0){
    Serial.println(r);
    Serial.println(g);
    Serial.println(b);
    if (r>=150& g>=150& b>=150){
      Serial.println("beyaz");
      sg90.write(0);
      delay(15);
    }
    else if(r<=0& g<=0& b<=0) {
      Serial.println("siyah");       
      sg90.write(180);
      delay(15);      

    }
    
    
  }
      
 

    

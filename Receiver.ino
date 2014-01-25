//include Servo Library
#include <Servo.h>

//Define pins
int servoPinT = 5;
int servoPinI = 6;
int servoPinM = 9;
int servoPinR = 10;
int servoPinP = 11;

Servo Servo1;
Servo ServoT;
Servo ServoI;
Servo ServoM;
Servo ServoR;
Servo ServoP;

void setup()
{
  //Create Serial Object (9600 Baud)
  Serial.begin(9600);
  ServoT.attach(servoPinT);
  ServoI.attach(servoPinI);
  ServoM.attach(servoPinM);
  ServoR.attach(servoPinR);
  ServoP.attach(servoPinP);
}

void loop(){
  
  int pos;
  
  while (Serial.available() <= 5){ delay(50); }
  char finger = Serial.read();
   // CHECK IF COMPLETE PACKET HAS ARRIVED IN ORDER
   while(1){ 
     //CHECK IF APPROPRIATE PACKET START
    while(finger != 'T' && finger != 'I' && finger != 'M' && finger != 'R' && finger != 'P'){
      finger = Serial.read(); //Keep popping off the stack
    }
    
    //Serial.println(finger);
    int data = Serial.read() - '0'; //Pop off the stack and convert to an int
    
    if(data < 10 && data > -1){
      Serial.print(finger);
      Serial.println(data);
      pos = map(data, 0, 9, 0, 180); //If valid int map to servo position
      char EOP = Serial.read();      //Pop next byte off the stack
      if(EOP == '.'){                //Check if valid packet end
        break;                       //If valid start the processing
      }
    }
   }
  
  //Set appropriate 
  if(finger == 'T'){
   Servo1 = ServoT;
  } 
  else if(finger == 'I'){
   Servo1 = ServoI; 
  }
  else if(finger == 'M'){
   Servo1 = ServoM; 
  }
  else if(finger == 'R'){
   Servo1 = ServoR; 
  }
  else if(finger == 'P'){
   Servo1 = ServoP; 
  }
 
  Servo1.write(pos);
}
  

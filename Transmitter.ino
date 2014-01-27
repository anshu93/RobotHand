//Define pins
int thumb = 12;
int index = 11;
int middle = 10;
int ring = 9;
int pinky = 8;

char arrThumb[4];
char arrIndex[4];
char arrMiddle[4];
char arrRing[4];
char arrPinky[4];

void setup()
{
  //Create Serial Object (9600 Baud)
  Serial.begin(9600);
}

void loop()
{
  
  int posThumb = map(analogRead(thumb), 520, 350, 0, 9);
  posThumb = constrain(posThumb, 0, 9);
  // Creating the character array for the thumb
  
  arrThumb[0] = 'T';
  arrThumb[1] = posThumb +'0';
  arrThumb[2] = '.';
 // Serial.println(thumb);
  //delay(500);
  
  
  int posIndex = map(analogRead(index), 550, 250, 0, 9);
  posIndex = constrain(posIndex, 0, 9);
  // Creating the character array for the index finger

  arrIndex[0] = 'I';
  arrIndex[1] = posIndex +'0';
  arrIndex[2] = '.';
 // Serial.println(index);
 // delay(500);
  
  int posMiddle = map(analogRead(middle), 560, 270, 0, 9);
  posMiddle = constrain(posMiddle, 0, 9);
  // Creating the character array for the middle finger

  arrMiddle[0] = 'M';
  arrMiddle[1] = posMiddle +'0';
  arrMiddle[2] = '.';
 // Serial.println(middle);
 // delay(500);
  
  
  int posRing = map(analogRead(ring), 640, 270, 0, 9);
  posRing = constrain(posRing, 0, 9);
  // Creating the character array for the ring finger

  arrRing[0] = 'R';
  arrRing[1] = posRing +'0';
  arrRing[2] = '.';
  //Serial.println(ring);
  //delay(500);
  
  int posPinky = map(analogRead(pinky), 570, 280, 0, 9);
  posPinky = constrain(posPinky, 0, 9);
  // Creating the character array for the pinky
 
  arrPinky[0] = 'P';
  arrPinky[1] = posPinky +'0';
  arrPinky[2] = '.';
  //Serial.println(pinky);
  
  delay(200);
  
  
 Serial.println(arrThumb);
 Serial.println(arrIndex);
 Serial.println(arrMiddle);
 Serial.println(arrRing);
 Serial.println(arrPinky);
}
  

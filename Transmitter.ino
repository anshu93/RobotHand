//Define pins
int thumb = A8;
int index = A9;
int middle = A10;
int ring = A11;
int pinky = A12;

void setup()
{
  //Create Serial Object (9600 Baud)
  Serial.begin(9600);
}

void loop()
{
  int valThumb = analogRead(thumb);
  int valIndex = analogRead(index);
  int valMiddle = analogRead(middle);
  int valRing = analogRead(ring);
  int valPinky = analogRead(pinky);
  
  int posThumb = map(analogRead(thumb), 700, 450, 0, 9);
  posThumb = constrain(posThumb, 0, 9);
  
  int posIndex = map(analogRead(index), 550, 250, 0, 9);
  posIndex = constrain(posIndex, 0, 9);
  
  int posMiddle = map(analogRead(middle), 560, 270, 0, 9);
  posMiddle = constrain(posMiddle, 0, 9);
 
  int posRing = map(analogRead(ring), 640, 270, 0, 9);
  posRing = constrain(posRing, 0, 9);
  
  int posPinky = map(analogRead(pinky), 570, 280, 0, 9);
  posPinky = constrain(posPinky, 0, 9);
  
  Serial.println(posThumb);
  Serial.println(posIndex);
  Serial.println(posMiddle);
  Serial.println(posRing);
  Serial.println(posPinky);
  
  delay(500);
}
  

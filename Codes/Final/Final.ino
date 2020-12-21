//In this code, the Arduino was programmed to receive and act on commands given by the infared remote
//Linear regression was used for distance and turn angles
#include <IRremote.h>
int infaredpin=12;
IRrecv IR(infaredpin);
decode_results results;
 
int enablea=5;
int enableb=6;
int int1=7;
int int2=8;
int int3=9;
int int4=11;
float distance;
int rotationangle=90;
int rotationangle1=45;
int rotationangle2=30;
int rotationangle3=120;
int rotationangle4=180;
int forbiddenangle1=66;
int forbiddenangle2=42;
int forbiddenangle3=111;
int left;
int right;
float velocity;
void setup() 
{
  Serial.begin(9600);
  IR.enableIRIn();
  IR.blink13(true);
   
  pinMode(enablea,OUTPUT);
  pinMode(enableb,OUTPUT);
  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  digitalWrite(enablea,HIGH);
  digitalWrite(enableb,HIGH);
}
 
void loop() 
{
  int writevelocity;
  velocity=2.2;
  distance=1;
  writevelocity=(velocity-.35)/.0075;
  left=writevelocity;
  right=writevelocity;
  setSpeed(left,right);
  while (IR.decode(&results)==0)
  {
    
  }
   
  Serial.println(results.value,HEX);
  if (results.value==0xFF629D)
  {
    Serial.println("Forward");
    forward(5*distance,velocity);  
  }
  if (results.value==0xFFA857)
  {
    Serial.println("Backward");
    backward(5*distance,velocity);  
  }
  if (results.value==0xFFC23D)
  {
    Serial.println("Right");
    turnRight(rotationangle,writevelocity);  
  }
  if (results.value==0xFF22DD)
  {
    Serial.println("Left");
    turnLeft(rotationangle,writevelocity);  
  }
  //--------------------------------------------------
  if (results.value==0xFF6897)
  {
    Serial.println("Action 1");
    forward(distance,velocity);
    turnRight(rotationangle,writevelocity);
    delay(1000);
    turnLeft(rotationangle,writevelocity);
    backward(distance,velocity);
  }
  if (results.value==0xFF9867)
  {
    Serial.println("Action 2");
    forward(distance,velocity);
    turnLeft(rotationangle,writevelocity);
    delay(1000);
    turnRight(rotationangle,writevelocity);
    backward(distance,velocity);
  }
  if (results.value==0xFFB04F)
  {
    Serial.println("Action 3");
    forward(distance,velocity);
    turnRight(rotationangle1,writevelocity);
    delay(1000);
    turnLeft(rotationangle1,writevelocity);
    backward(distance,velocity);
  }
  if (results.value==0xFF30CF)
  {
    Serial.println("Action 4");
    forward(distance,velocity);
    turnLeft(rotationangle1,writevelocity);
    delay(1000);
    turnRight(rotationangle1,writevelocity);
    backward(distance,velocity);
  }
  if (results.value==0xFF18E7)
  {
    Serial.println("Action 5");
    forward(distance,velocity);
    turnRight(rotationangle,writevelocity);
    forward(distance,velocity);
    turnLeft(rotationangle2,writevelocity);
    forward(distance,velocity);
    delay(1000);
    backward(distance,velocity);
    turnRight(rotationangle2,writevelocity);
    backward(distance,velocity);
    turnLeft(rotationangle,writevelocity);
    backward(distance,velocity);
  }
  if (results.value==0xFF7A85)
  {
    Serial.println("Action 6");
    forward(distance,velocity);
    turnLeft(rotationangle,writevelocity);
    forward(distance,velocity);
    turnRight(rotationangle2,writevelocity);
    forward(distance,velocity);
    delay(1000);
    backward(distance,velocity);
    turnLeft(rotationangle2,writevelocity);
    backward(distance,velocity);
    turnRight(rotationangle,writevelocity);
    backward(distance,velocity);
  }
  
  if (results.value==0xFF10EF)
  {
    Serial.println("Action 7");
    forward(2*distance,velocity);
    backward(distance,velocity);
    turnLeft(rotationangle4,writevelocity);
    backward(3*distance,velocity);
    turnLeft(rotationangle4,writevelocity);
    backward(4*distance,velocity);
  }

  //These are just all over the place
  if (results.value==0xFF38C7)
  {
    Serial.println("Action 8");
    forward(4*distance,velocity);
    turnRight(forbiddenangle1,writevelocity);
    forward(2*distance,velocity);
    turnLeft(forbiddenangle2,writevelocity);
    forward(1*distance,velocity);
    backward(6*distance,velocity);
    turnLeft(forbiddenangle2,writevelocity);
    backward(3*distance,velocity);
    turnRight(rotationangle2,writevelocity);
    backward(4*distance,velocity); 
  }

  if (results.value==0xFF5AA5)
  {
    Serial.println("Action 9");
    forward(6*distance,velocity);
    turnRight(forbiddenangle2,writevelocity);
    forward(4*distance,velocity);
    turnRight(forbiddenangle3,writevelocity);
    forward(9*distance,velocity);
    backward(6*distance,velocity);
    turnLeft(forbiddenangle1,writevelocity);
    backward(3*distance,velocity);
    forward(4*distance,velocity); 
  }

  if (results.value==0xFF5AA5)
  {
    Serial.println("Action 9");
    forward(2*distance,velocity);
    turnRight(rotationangle2,writevelocity);
    backward(8*distance,velocity);
    turnRight(forbiddenangle3,writevelocity);
    forward(9*distance,velocity);
    turnRight(forbiddenangle2,writevelocity);
    backward(6*distance,velocity);
    forward(4*distance,velocity); 
    turnLeft(rotationangle3,writevelocity);
    backward(3*distance,velocity);
  }

  if (results.value==0xFF42BD)
  {
    turnRight(36*rotationangle2,writevelocity);
  }

  if (results.value==0xFF52AD)
  {
    turnLeft(36*rotationangle2,writevelocity);
  }
  IR.resume();
   
}
void setSpeed(int leftVal,int rightVal)
{
  analogWrite(enablea,leftVal);
  analogWrite(enableb,rightVal);
}
void forward(float distance, float velocity)
{
  float t;
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,LOW);
  digitalWrite(int4,HIGH);
  t=distance/velocity*1000;
  delay(t);
  stopCar();
}
void backward(float distance, float velocity)
{
  float t;
  digitalWrite(int1,LOW);
  digitalWrite(int2,HIGH);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);
  t=distance/velocity*1000;
  delay(t);
  stopCar();
}
void turnRight(int deg, int writevelocity)
{
  float t;
  stopCar();
  delay(100);
  analogWrite(enablea,125);
  analogWrite(enableb,125);
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);
  t=(deg+6)/136.29*1000.;
  delay(t);
  stopCar();
  analogWrite(enablea,writevelocity);
  analogWrite(enableb,writevelocity);
}

void turnLeft(int deg, int writevelocity)
{
  float t;
  analogWrite(enablea,125);
  analogWrite(enableb,125);
  digitalWrite(int1,LOW);
  digitalWrite(int2,HIGH);
  digitalWrite(int3,LOW);
  digitalWrite(int4,HIGH);
  t=(deg+6)/136.29*1000.;
  delay(t);
  stopCar();
  analogWrite(enablea,writevelocity);
  analogWrite(enableb,writevelocity);
}
void stopCar()
{
  digitalWrite(int1,LOW);
  digitalWrite(int2,LOW);
  digitalWrite(int3,LOW);
  digitalWrite(int4,LOW);
}

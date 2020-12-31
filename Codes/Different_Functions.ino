int enablea=5; 
int enableb=6; 
int int1=7; 
int int2=8; 
int int3=9; 
int int4=11; 
float floater; //Distance float
int rotation; //Degree float
void setup() 
{ 
  //Setup all the varibales as OUTPUT, and set the enable pins to HIGH using digitalWrite. 
  Serial.begin(9600); 
  //Serial.begin is used to allow the Arduino to communicate with the serial monitor via the USB connector.
  //(9600) represents the baud rate which dictates how fast the data is sent. It is measured in bits per second. 
  pinMode(enablea,OUTPUT); 
  pinMode(enableb,OUTPUT); 
  pinMode(int1,OUTPUT); 
  pinMode(int2,OUTPUT); 
  pinMode(int3,OUTPUT); 
  pinMode(int4,OUTPUT); 
  digitalWrite(enablea,HIGH); 
  digitalWrite(enableb,HIGH); 
} 
void loop() //The values in the brackets (10)/(180) can be changed for any number, this was just to help me understand the car. 
{ 
  forward(10); //Forward 10 feet
  rightturn(180); //Turn right 180 degrees
  forward(10); //Forward 10 feet
  leftturn(180); //Turn left 180 degrees
  while(2==2){ } //Allows the program to run
} 
  
void forward(float floater)
{ 
  float floater2; 
  digitalWrite(int1,HIGH); 
  digitalWrite(int2,LOW); 
  digitalWrite(int3,LOW); 
  digitalWrite(int4,HIGH); 
  floater2=floater/2.45*1000; 
  //The 2.45 is an experimentally determined rate. I had determined that the car travelled 6.125 feet in 2.5 seconds (give or take)
  //I used this as a global rate for forward and backward travel.
  delay(floater2); //The "delay" is in a sense the time it takes for the car to stop in this case.
  stopCar(); 
} 

void backward(float floater)
{ 
  float floater2; 
  digitalWrite(int1,LOW); 
  digitalWrite(int2,HIGH); 
  digitalWrite(int3,HIGH); 
  digitalWrite(int4,LOW); 
  floater2=floater/2.45*1000; 
  delay(floater2); 
  stopCar(); 
} 

void rightturn(int degrees1)
{ 
  float floater2; 
  digitalWrite(int1,HIGH); 
  digitalWrite(int2,LOW); 
  digitalWrite(int3,HIGH); 
  digitalWrite(int4,LOW); 
  floater2=degrees1/345.*1000.; 
  //The 345 is an experimentally determined rate. I had determined that the car travelled turned 1990 degrees in five seconds (give or take)
  //I used this as a global rate for turning left and right
  Serial.println(degrees1); 
  delay(floater2); 
  stopCar(); 
} 

void leftturn(float degrees1)
{ 
  float floater2; 
  digitalWrite(int1,LOW); 
  digitalWrite(int2,HIGH); 
  digitalWrite(int3,LOW); 
  digitalWrite(int4,HIGH); 
  floater2=degrees1/345.*1000.; 
  Serial.println(degrees1); 
  delay(floater2); 
  stopCar(); 
} 

void stopCar()//Stops all motors
{ 
digitalWrite(int1,LOW); 
digitalWrite(int2,LOW); 
digitalWrite(int3,LOW); 
digitalWrite(int4,LOW); 
} 

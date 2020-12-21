//Global variables. We know from the shield, that these are the pins used.
int enablea=5;
int enableb=6;
int int1=7;
int int2=8;
int int3=9;
int int4=11;

void setup() 
{
  //Setup all the varibales as OUTPUT, and set the enable pins to HIGH using digitalWrite.
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
  //Car turns left indefinetely 
  digitalWrite(int1,LOW);
  digitalWrite(int2,HIGH);
  digitalWrite(int3,LOW);
  digitalWrite(int4,HIGH);
  delay(1000);
}

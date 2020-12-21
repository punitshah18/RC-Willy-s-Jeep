#include <IRremote.h> //including the library IRremote so that I can control the car with an IR remote.
int infaredpin=12; //We know from the shield that the IR sensor is connected to pin 12
IRrecv remote(infaredpin); //Creates a receiver object about pin 12(infaredpin)
decode_results results; //global varibale for the received data from the remote

void setup() 
{
  Serial.begin(9600); //Allows the IR remote to communicate with the computer and terminal via the USB cable. 
  remote.enableIRIn(); //Begins the receiving process.
  remote.blink13(true); //Used for troubleshooting. Since we can't see IR light, we send a command that lights up the LED on pin 13 when the remote is used. 

}

void loop() 
{
  while(remote.decode(&results)==0)//While loop to allow the program to run
  {
    
  }
  Serial.println(results.value,HEX); //Sends the hexadecimal value corresponding to each button pressed to the terminal
  delay(750);
  remote.resume(); //Restarts the process, so after a button is pressed another can be pressed
  
}

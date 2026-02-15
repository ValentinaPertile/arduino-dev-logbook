
/*
  This sketch implements the logic for a dual traffic light intersection using an Arduino Uno. 
  The system coordinates six digital outputs (Pins 8-13) to manage two sets of Red, Yellow, and Green LEDs. 
  The software follows a state-machine logic where each "State" ensures traffic safety by alternating 
  right-of-way access with timed delays of 5000ms and 2000ms.

  Connections Guide:
  -Traffic Light 1: Pins 13 (R), 12 (Y), 11 (G).
  -Traffic Light 2: Pins 10 (R), 9 (Y), 8 (G).
  -Common Ground: All cathodes are connected to the Arduino's GND rail.

  Each LED is connected in series with a 220Ω resistor to regulate current from the digital pins. 
  All LED cathodes are tied together to create a Common Ground path, which returns to the Arduino's GND pin 
  to complete the circuit. 
  This shared return path ensures a stable reference voltage for all six signaling states.
*/

void setup()
{
  pinMode(13, OUTPUT); //red1
  pinMode(12, OUTPUT); //yellow1
  pinMode(11, OUTPUT); //green1
  pinMode(10, OUTPUT); //red2
  pinMode(9, OUTPUT); //yellow2
  pinMode(8, OUTPUT); //green2
}

void loop()
{
  	//STATE 1 
	digitalWrite(13,1); //the second 1 acts as HIGH
  	digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,1);
  	 delay(5000); //For 5 seconds red1 and green2 will be ON
  	
 	//STATE 2
	digitalWrite(13,1); 
  	digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,1);
    digitalWrite(8,0);
  	 delay(2000); //For 2 seconds red1 will remain ON as well as yellow2
  
  	//STATE 3
	digitalWrite(13,0); 
  	digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(8,0);
  	 delay(5000); //For 5 seconds green1 and red2 will be ON
  
   	//STATE 4
	digitalWrite(13,0); 
  	digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(8,0);
  	 delay(2000); //For 2 seconds red2 will remain ON as well as yellow1
  
}
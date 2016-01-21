  /*
  Author: Andreas Langhammer
  Date: 2016-01-21
  
  This program writes a logic 1 to digital pin 10 to light up a LED when it is in a dark environment.
  In order to do this I use a fotosensor that gives analog values to the Arduino Leonardo. For the moment
  is it programed as a polling routine.
  */
  int sensor = A0; 
  int LED = 10; 
  int Vref = 11;
  int transitionVal = 800;
  int delayVal = 0;
  
  void setup(){
    pinMode(LED, OUTPUT);              // Define Pin 10 as OUTPUT
    pinMode(Vref, OUTPUT);             // Define Pin 11 as OUTPUT only used to set Vref (logic 1)
    delay(5000);                       // Delay-Time to start monitor  
}
  // Polling the value from Analog 0 and makes desicions
  void loop(){
     digitalWrite(Vref, HIGH);         // Set Vref
     int sensVal;                      // Used to store Analog value from sensor
     sensVal = analogRead(sensor);     // Stores the value in sensVal
     Serial.print("Sensor Value: ");   // The next two rows only prints the value in the console.
     Serial.print(sensVal);
     Serial.print("\n");               // New line
     delayVal = (sensVal / 10);        // Takes the value and multiplies it with 100 so the polling does not occur so often.
     Serial.print("delayVal : ");
     Serial.print(delayVal);
     Serial.print("\n");               // New line
     delay(1000);                      // Delay 1 s
     
     //The logic part
     if(sensVal < transitionVal){
       digitalWrite(LED, HIGH);        // LED on
     }else{
       digitalWrite(LED, LOW);         // LED off
     }
     longDelay(delayVal);              // Pause delayVal seconds
  }
  
 // A delay for handling greater periods of pauses.
  void longDelay(int delayVal){
     int i = 0;
     Serial.print("Delay values: ");
     for(i = 0; i != delayVal; i++){
        Serial.print(i);                // Printing out every second in monitor
        Serial.print(", ");
        delay(1000);
     }
     Serial.print("\n");                // New line
  }

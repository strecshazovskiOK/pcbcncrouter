//Step Motor Testing: 

//Test Code: 

// Define the pins connected to the M542-05 driver 

#define PUL_PIN 8      // Pulse pin connected to PUL+ 

#define DIR_PIN 9      // Direction pin connected to DIR+ 

#define ENA_PIN 10     // Enable pin connected to ENA+ 

  

void setup() { 

  // Initialize the pins as outputs 

  pinMode(PUL_PIN, OUTPUT); 

  pinMode(DIR_PIN, OUTPUT); 

  pinMode(ENA_PIN, OUTPUT); 

   

  // Enable the driver (active low) 

  digitalWrite(ENA_PIN, LOW); 

   

  // Set the initial direction (HIGH or LOW) 

  digitalWrite(DIR_PIN, HIGH);  // Set to LOW to reverse direction 

} 

  

void loop() { 

  // Generate a pulse to move the motor one step 

  digitalWrite(PUL_PIN, HIGH); 

  delayMicroseconds(500);  // Adjust the delay to control speed 

  digitalWrite(PUL_PIN, LOW); 

  delayMicroseconds(500);  // Adjust the delay to control speed 

  

  // Repeat the process to continue moving the motor 

} 
/*
Notes: 

X stepper working with delay of 100 microseconds for the loop which is responsible with generating pulse to move the motor one step. 100 microseconds HIGH 100 microseconds LOW 

While we are working on the Y stepper with delay of 100 microseconds, it was not enough fast. 

While we are working on the Z stepper with delay of 1000 microseconds, it couldn’t move with that pulse width and we tried with HIGH 100 microseconds and LOW 100 microseconds at it worked.*/ 

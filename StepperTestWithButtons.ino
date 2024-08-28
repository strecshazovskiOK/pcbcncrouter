// Define the pins connected to the M542-05 driver
#define PUL_PIN 8      // Pulse pin connected to PUL+
#define DIR_PIN 9      // Direction pin connected to DIR+
#define ENA_PIN 10     // Enable pin connected to ENA+
#define POT_Z_PIN A2     // Potentiometer for Motor Z connected to A2
#define BUTTON1_PIN 4 // Button 1
#define BUTTON2_PIN 5 // Button 2

void setup() {
  Serial.begin(1000000);
  // Initialize the pins as outputs
  
  pinMode(PUL_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
// Make button pins as input and make high pull-up resistors.
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  
  // Enable the driver (active low)
  digitalWrite(ENA_PIN, LOW);
 
  // Set the initial direction (HIGH or LOW)
  digitalWrite(DIR_PIN, LOW);  // Set to LOW to reverse direction
  
}

void loop() {
  // Generate a pulse to move the motor one step
  /*int potValue = analogRead(POT_Z_PIN);
  int motorSpeed = map(potValue, 0, 100, 1,110);*/
  int button1State = digitalRead(BUTTON1_PIN);  // Button 1
  int button2State = digitalRead(BUTTON2_PIN);  // Button 2
  if (button1State == LOW) {  // Button Pressed LOW
    Serial.println("Button 1: ON");
    digitalWrite(DIR_PIN, LOW);  // Set to LOW to reverse direction
    digitalWrite(PUL_PIN, HIGH);
    delayMicroseconds(0.0000000001);  // Adjust the delay to control speed
    digitalWrite(PUL_PIN, LOW);
    delayMicroseconds(0.0000000001);  // Adjust the delay to control speed
  } 
else {
    Serial.println("Button 1: OFF");
    
  }
  if (button2State == LOW) {  
    Serial.println("Button 2: ON");
    digitalWrite(DIR_PIN, HIGH);  // Set to LOW to reverse direction
    digitalWrite(PUL_PIN, HIGH);
    delayMicroseconds(0.00000000001);  // Adjust the delay to control speed
    
    digitalWrite(PUL_PIN, LOW);
    delayMicroseconds(0.00000000001);  // Adjust the delay to control speed
    
    
  } 
else {
    Serial.println("Button 2: OFF");
  }
}

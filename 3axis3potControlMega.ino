
// This code is designed for use with an Arduino Mega 2560 by Omercan Kahveci.

#include <Arduino.h>  // Include the Arduino core library, essential for all Arduino functions

// Global variables for each motor
int posX, posY, posZ;  // Variables to track the current position of the X, Y, and Z axes
int motorSpeedX, motorSpeedY, motorSpeedZ;  // Variables to store the motor speeds for each axis

// Pin definitions for Motor X (on Arduino Mega 2560)
#define X_STEP_PIN 2     // Pin 2 is defined as the step pin for Motor X (connect to PUL+ on Driver 1)
#define X_DIR_PIN 3      // Pin 3 is defined as the direction pin for Motor X (connect to DIR+ on Driver 1)
#define X_ENABLE_PIN 4   // Pin 4 is defined as the enable pin for Motor X (connect to ENA+ on Driver 1)
#define POT_X_PIN A0     // Potentiometer for Motor X is connected to Analog Pin A0

// Pin definitions for Motor Y (on Arduino Mega 2560)
#define Y_STEP_PIN 5     // Pin 5 is defined as the step pin for Motor Y (connect to PUL+ on Driver 2)
#define Y_DIR_PIN 6      // Pin 6 is defined as the direction pin for Motor Y (connect to DIR+ on Driver 2)
#define Y_ENABLE_PIN 7   // Pin 7 is defined as the enable pin for Motor Y (connect to ENA+ on Driver 2)
#define POT_Y_PIN A1     // Potentiometer for Motor Y is connected to Analog Pin A1

// Pin definitions for Motor Z (on Arduino Mega 2560)
#define Z_STEP_PIN 8     // Pin 8 is defined as the step pin for Motor Z (connect to PUL+ on Driver 3)
#define Z_DIR_PIN 9      // Pin 9 is defined as the direction pin for Motor Z (connect to DIR+ on Driver 3)
#define Z_ENABLE_PIN 10  // Pin 10 is defined as the enable pin for Motor Z (connect to ENA+ on Driver 3)
#define POT_Z_PIN A2     // Potentiometer for Motor Z is connected to Analog Pin A2

#define DEFAULT_SPEED 200   // Default speed (this is a placeholder value, not used directly)
#define MIN_SPEED 50        // Minimum motor speed (mapped from potentiometer input)
#define MAX_SPEED 1023       // Maximum motor speed (mapped from potentiometer input)

// Initialization setup
void initSetup() {
    Serial.begin(115200);  // Start serial communication at 115200 baud rate for debugging and communication

    // Initialize pins for Motor X
    pinMode(X_STEP_PIN, OUTPUT);       // Set the X_STEP_PIN as an output
    pinMode(X_DIR_PIN, OUTPUT);        // Set the X_DIR_PIN as an output
    pinMode(X_ENABLE_PIN, OUTPUT);     // Set the X_ENABLE_PIN as an output
    digitalWrite(X_ENABLE_PIN, LOW);   // Enable Driver 1 by setting ENA+ LOW (active LOW)

    // Initialize pins for Motor Y
    pinMode(Y_STEP_PIN, OUTPUT);       // Set the Y_STEP_PIN as an output
    pinMode(Y_DIR_PIN, OUTPUT);        // Set the Y_DIR_PIN as an output
    pinMode(Y_ENABLE_PIN, OUTPUT);     // Set the Y_ENABLE_PIN as an output
    digitalWrite(Y_ENABLE_PIN, LOW);   // Enable Driver 2 by setting ENA+ LOW (active LOW)

    // Initialize pins for Motor Z
    pinMode(Z_STEP_PIN, OUTPUT);       // Set the Z_STEP_PIN as an output
    pinMode(Z_DIR_PIN, OUTPUT);        // Set the Z_DIR_PIN as an output
    pinMode(Z_ENABLE_PIN, OUTPUT);     // Set the Z_ENABLE_PIN as an output
    digitalWrite(Z_ENABLE_PIN, LOW);   // Enable Driver 3 by setting ENA+ LOW (active LOW)

    Serial.println("Setup complete. Ready to operate.");  // Print a message to the serial monitor indicating setup completion
}

// Motor functions for Motor X
void moveMotorX(int steps) {
    digitalWrite(X_ENABLE_PIN, LOW);  // Enable Driver 1 by setting ENA+ LOW (active LOW)
    for (int i = 0; i < abs(steps); i++) {  // Loop through the number of steps, taking care of direction
        if (steps > 0) {
            digitalWrite(X_DIR_PIN, HIGH);  // Set the direction to HIGH if steps are positive
        } else {
            digitalWrite(X_DIR_PIN, LOW);   // Set the direction to LOW if steps are negative
        }
        digitalWrite(X_STEP_PIN, HIGH);   // Send a high pulse to the step pin to move the motor one step
        delayMicroseconds(1000000 / motorSpeedX);  // Wait based on the speed to control step timing
        digitalWrite(X_STEP_PIN, LOW);    // Set the step pin low to complete the pulse
        delayMicroseconds(1000000 / motorSpeedX);  // Wait before the next pulse
    }
    digitalWrite(X_ENABLE_PIN, HIGH);  // Disable Driver 1 by setting ENA+ HIGH (active LOW)
}

// Motor functions for Motor Y
void moveMotorY(int steps) {
    digitalWrite(Y_ENABLE_PIN, LOW);  // Enable Driver 2 by setting ENA+ LOW (active LOW)
    for (int i = 0; i < abs(steps); i++) {  // Loop through the number of steps, taking care of direction
        if (steps > 0) {
            digitalWrite(Y_DIR_PIN, HIGH);  // Set the direction to HIGH if steps are positive
        } else {
            digitalWrite(Y_DIR_PIN, LOW);   // Set the direction to LOW if steps are negative
        }
        digitalWrite(Y_STEP_PIN, HIGH);   // Send a high pulse to the step pin to move the motor one step
        delayMicroseconds(1000000 / motorSpeedY);  // Wait based on the speed to control step timing
        digitalWrite(Y_STEP_PIN, LOW);    // Set the step pin low to complete the pulse
        delayMicroseconds(1000000 / motorSpeedY);  // Wait before the next pulse
    }
    digitalWrite(Y_ENABLE_PIN, HIGH);  // Disable Driver 2 by setting ENA+ HIGH (active LOW)
}

// Motor functions for Motor Z
void moveMotorZ(int steps) {
    digitalWrite(Z_ENABLE_PIN, LOW);  // Enable Driver 3 by setting ENA+ LOW (active LOW)
    for (int i = 0; i < abs(steps); i++) {  // Loop through the number of steps, taking care of direction
        if (steps > 0) {
            digitalWrite(Z_DIR_PIN, HIGH);  // Set the direction to HIGH if steps are positive
        } else {
            digitalWrite(Z_DIR_PIN, LOW);   // Set the direction to LOW if steps are negative
        }
        digitalWrite(Z_STEP_PIN, HIGH);   // Send a high pulse to the step pin to move the motor one step
        delayMicroseconds(1000000 / motorSpeedZ);  // Wait based on the speed to control step timing
        digitalWrite(Z_STEP_PIN, LOW);    // Set the step pin low to complete the pulse
        delayMicroseconds(1000000 / motorSpeedZ);  // Wait before the next pulse
    }
    digitalWrite(Z_ENABLE_PIN, HIGH);  // Disable Driver 3 by setting ENA+ HIGH (active LOW)
}

// Execute move command for each axis
void executeMoveCommand(char axis, int steps) {
    switch (axis) {  // Determine which axis to move based on the command received
        case 'X':  // If the command is for the X-axis
            moveMotorX(steps);  // Move the X motor the specified number of steps
            break;
        case 'Y':  // If the command is for the Y-axis
            moveMotorY(steps);  // Move the Y motor the specified number of steps
            break;
        case 'Z':  // If the command is for the Z-axis
            moveMotorZ(steps);  // Move the Z motor the specified number of steps
            break;
        default:  // If an invalid axis is specified
            Serial.println("Invalid axis specified.");  // Print an error message to the serial monitor
            break;
    }
}

// Command parsing and execution
void parseCommand(String command) {
    if (command.startsWith("MOVE")) {  // Check if the command starts with "MOVE"
        char axis = command.charAt(5);  // Extract the axis character (X, Y, or Z) from the command
        int steps = command.substring(6).toInt();  // Convert the steps part of the command to an integer
        executeMoveCommand(axis, steps);  // Call the executeMoveCommand function with the extracted axis and steps
    } else {
        Serial.println("Unrecognized command received.");  // Print an error message for unrecognized commands
    }
}

// Process incoming serial data
void decodeSerialData() {
    if (Serial.available() > 0) {  // Check if there is any data available to read from the serial port
        String input = Serial.readStringUntil('\n');  // Read the incoming data until a newline character is received
        parseCommand(input);  // Pass the received command string to the parseCommand function
    }
}

// Main loop
void loop() {
    // Read potentiometers and set motor speeds
    int potXValue = analogRead(POT_X_PIN);  // Read the analog value from the potentiometer for Motor X
    motorSpeedX = map(potXValue, 0, 1023, MIN_SPEED, MAX_SPEED);  // Map the potentiometer value to the motor speed range
    Serial.print("Motor X Speed: ");  // Print the motor speed for Motor X
    Serial.println(motorSpeedX);  // Print the actual speed value
    delay(100);
    int potYValue = analogRead(POT_Y_PIN);  // Read the analog value from the potentiometer for Motor Y
    motorSpeedY = map(potYValue, 0, 1023, MIN_SPEED, MAX_SPEED);  // Map the potentiometer value to the motor speed range
    Serial.print("Motor Y Speed: ");  // Print the motor speed for Motor Y
    Serial.println(motorSpeedY);  // Print the actual speed value
    delay(100);
    int potZValue = analogRead(POT_Z_PIN);  // Read the analog value from the potentiometer for Motor Z
    motorSpeedZ = map(potZValue, 0, 1023, MIN_SPEED, MAX_SPEED);  // Map the potentiometer value to the motor speed range
    Serial.print("Motor Z Speed: ");  // Print the motor speed for Motor Z
    Serial.println(motorSpeedZ);  // Print the actual speed value
    delay(100);
    // Process serial commands
    decodeSerialData();  // Continuously check for and process incoming serial data
}
void setup() {
    initSetup();  // Call the initialization setup
}

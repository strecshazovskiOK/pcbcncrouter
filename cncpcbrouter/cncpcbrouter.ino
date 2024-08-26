// ömercan kahveci devimsel cnc project
#include <Arduino.h>

// Global variables
int posX, posY, posZ;
int motorSpeed, motorAcceleration;

// Pin definitions
#define X_STEP_PIN 2     // Connect to PUL+
#define X_DIR_PIN 3      // Connect to DIR+
#define X_ENABLE_PIN 4   // Connect to ENA+

#define DEFAULT_SPEED 200
#define DEFAULT_ACCELERATION 100
#define MIN_SPEED 50
#define MAX_SPEED 300

// Initialization setup
void initSetup() {
    Serial.begin(115200);
    pinMode(X_STEP_PIN, OUTPUT);
    pinMode(X_DIR_PIN, OUTPUT);
    pinMode(X_ENABLE_PIN, OUTPUT);
    
    // Set initial states for the pins
    digitalWrite(X_ENABLE_PIN, LOW);  // Enable the driver (ENA active LOW)
    digitalWrite(X_STEP_PIN, LOW);
    digitalWrite(X_DIR_PIN, LOW);

    Serial.println("Setup complete. Ready to operate.");
}

// Reset machine
void resetMachine() {
    posX = 0;
    posY = 0;
    posZ = 0;
    Serial.println("Machine parameters have been reset.");
}

// Motor functions
void initMotor() {
    motorSpeed = DEFAULT_SPEED;
    motorAcceleration = DEFAULT_ACCELERATION;
    Serial.println("Motor initialized with default settings.");
}

void setMotorSpeed(int speed) {
    if (speed >= MIN_SPEED && speed <= MAX_SPEED) {
        motorSpeed = speed;
        Serial.print("Motor speed set to: ");
        Serial.println(motorSpeed);
    } else {
        Serial.println("Speed out of range.");
    }
}

// Motion control
void moveXAxis(int steps) {
    digitalWrite(X_ENABLE_PIN, LOW);  // Enable the driver (ENA active LOW)
    
    for (int i = 0; i < abs(steps); i++) {
        digitalWrite(X_DIR_PIN, steps > 0 ? HIGH : LOW);
        digitalWrite(X_STEP_PIN, HIGH);
        delayMicroseconds(100);  // Adjust timing as needed for your driver and motor
        digitalWrite(X_STEP_PIN, LOW);
        delayMicroseconds(100);
    }
    
    digitalWrite(X_ENABLE_PIN, HIGH);  // Disable the driver after movement (ENA active LOW)
}

void executeMoveCommand(char axis, int steps) {
    switch (axis) {
        case 'X':
            move

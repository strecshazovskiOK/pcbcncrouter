3-Axis CNC Control with Arduino Mega 2560

Overview

This project provides the Arduino code to control a 3-axis CNC machine using potentiometers. The code is designed to work with an Arduino Mega 2560, and it interfaces with an M542-05 Leadshine microstep driver for precise stepper motor control. The system allows manual control of the X, Y, and Z axes through three potentiometers.
Features
3-Axis Control: Adjust the X, Y, and Z axes of the CNC machine using separate potentiometers.
Arduino Mega 2560: Utilizes the powerful and versatile Arduino Mega 2560 microcontroller for controlling the CNC machine.
Microstep Driver Interface: Compatible with M542-05 Leadshine microstep drivers, enabling smooth and precise control of stepper motors.
Manual Operation: Provides a simple interface for manually controlling the CNC machine without the need for complex software.

Components

Arduino Mega 2560: The main microcontroller board used in this project.
Potentiometers (x3): Used to manually control the movement of the CNC machine on the X, Y, and Z axes.
M542-05 Leadshine Microstep Driver: Used to control the stepper motors connected to each axis.
Stepper Motors: Motors that move the CNC machine's axes.

Wiring Diagram

Here’s how the components should be connected:
X-axis: Connect the first potentiometer to an analog input pin on the Arduino Mega 2560 and the corresponding stepper motor to the X-axis output on the M542-05 driver.
Y-axis: Connect the second potentiometer to another analog input pin and the corresponding stepper motor to the Y-axis output on the M542-05 driver.
Z-axis: Connect the third potentiometer similarly and connect the stepper motor to the Z-axis output on the M542-05 driver.
Please refer to the code comments for specific pin connections and settings.

Installation
Clone the Repository:  git clone https://github.com/yourusername/3axis-cnc-control.git
  
Upload the Code: Open the 3axis3potControlMega.ino file in the Arduino IDE and upload it to your Arduino Mega 2560.

Usage

Power on the CNC Machine: Ensure that the Arduino Mega 2560 and M542-05 drivers are powered.
Adjust the Potentiometers: Rotate the potentiometers to control the movement of the CNC machine on the X, Y, and Z axes.
Observe the Motion: The CNC machine should respond to the potentiometer adjustments, moving in the corresponding directions.
Contributing
If you would like to contribute to this project, feel free to fork the repository and submit a pull request.

Acknowledgments
Special thanks to the open-source community and the contributors to the Arduino platform for making projects like this possible.

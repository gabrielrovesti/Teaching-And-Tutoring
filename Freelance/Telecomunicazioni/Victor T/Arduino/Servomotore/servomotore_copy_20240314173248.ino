#include <Servo.h>

Servo servo1; 

// read X and Y values of joystick
int joyX = A0;
int joyY = A2;

int joystickValue; // read the values from the Analog pins

void setup() {
    servo1.attach(2);
}

void loop() {

    joystickValue = analogRead(joyX);
    joystickValue = map(joystickValue, 0, 1023, 0, 360);
    servo1.write(joystickValue);

    joystickValue = analogRead(joyY);
    joystickValue = map(joystickValue, 0, 1023, 0, 360);
    servo1.write(joystickValue);

    delay(10);
}


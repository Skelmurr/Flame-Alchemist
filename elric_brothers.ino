/* Elric Brothers Project
*  Ilan Olivo Buentello and Jahbari Allsop-Marsham
*  AET 313 - Code and Fabrication
*/

#include <Servo.h>

Servo servos[5]; // Pins are 10, 11, 12, 13, 9
int buttonPins[5] = {6, 2, 3, 4, 5}; // each corresponds to its respective servo
int active[5] = {false, false, false, false, false};

// Called once when ran
void setup() {
  servos[0].attach(10); // 180 servo, Roy investigating for the third scene
  servos[1].attach(11); // 360 servo, Envy for the second scene
  servos[2].attach(12); // 180 servo, the fire for the last scene
  servos[3].attach(13); // 360 servo, Envy for the second to last scene
  servos[4].attach(9); // 180 servo, Roy for the first scene
  pinMode(buttonPins, INPUT);
}

// Called repeatedly while running
void loop() {
  if (!active[4]) { roy(); }
  servo360();
  royInvestigate();
  if (!active[2]) { fire(); }
  //Serial.begin(9600);
}

// Determines which 360 servo is being used based on which button input is being detected
// and calls the function for the 360 servo
void servo360() {
  if (digitalRead(buttonPins[1]) == HIGH) { 
    if (!active[1]) { envyFlip(1); }
  } else { 
    servos[1].write(90); 
    active[1] = false;
  }
  if (digitalRead(buttonPins[3]) == HIGH) { 
    if (!active[3]) { envyFlip(3); }
  } else { 
    servos[3].write(90); 
    active[3] = false;
  }
}

// Makes the servo with Roy Mustang flip over
void roy() {
  if (digitalRead(buttonPins[4]) == HIGH) { 
    servos[4].write(0);
    active[4] = true;
  } else { servos[4].write(180); }
}

// Makes the servo with Roy Mustang rotate left and right repeatedly
void royInvestigate() {
  if (digitalRead(buttonPins[0]) == HIGH || active[0]) {
    active[0] = true;
    servos[0].write(135);
    delay(500);
    servos[0].write(45);
    delay(500);
  } else { servos[0].write(90); }
}

/*
* Makes the 360 servos with Envy on top flip 180 degrees, this function is used for multiple servos
* Takes an integer of the servo being used
*/
void envyFlip(int servoNum) {
  servos[servoNum].write(180);
  delay(400); // 425 might flip a little more than 180 degrees, keep checking
  servos[servoNum].write(90);
  active[servoNum] = true;
  delay(400);
}

// Makes the fire behind Envy in the last scene go up and down
void fire() {
  if (digitalRead(buttonPins[2]) == HIGH) { 
    servos[2].write(180); 
    delay(1000);
    servos[2].write(0);
    delay(1000);
  }
  else { servos[2].write(0); }
}
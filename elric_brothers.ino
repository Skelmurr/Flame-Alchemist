/* Elric Brothers Project
*  Ilan Olivo Buentello and Jahbari Allsop-Marsham
*  AET 313 - Code and Fabrication
*/

#include <Servo.h>

Servo servos[4]; // 1 & 3 are 180 servos, 2 & 4 are 360 servos
int buttonPins[4] = {2, 3, 4, 5}; // each corresponds to its respective servo

// Called once when ran
void setup() {
  servos[0].attach(10); // 180 servo, Roy's hand
  servos[1].attach(11); // 360 servo
  servos[2].attach(12); // 180 servo, fire
  servos[3].attach(13); // 360 servo
  pinMode(buttonPins, INPUT);
}

// Called repeatedly while running
void loop() {
  roy();
  servo360();
  fire();
}

// Determines which 360 servo is being used based on which button input is being detected
// and calls the function for the 360 servo
void servo360() {
  if (digitalRead(buttonPins[1]) == HIGH) { envyFlip(1);
  } else { servos[1].write(90); }
  if (digitalRead(buttonPins[3]) == HIGH) { envyFlip(3);
  } else { servos[3].write(90); }
}

// Makes the servo with Roy Mustang go left and right repeatedly
void roy() {
  if (digitalRead(buttonPins[0]) == HIGH) { 
    servos[0].write(115); 
    delay(500);
    servos[0].write(65);
    delay(500);
  }
  else { servos[0].write(90); }
}

/*
* Makes the 360 servos with Envy on top flip 180 degrees
*
* Parameters
* ----------
* servoNum : int
* The number of the servo being used, since this is function used for multiple servos
*/
void envyFlip(int servoNum) {
  servos[servoNum].write(180);
  delay(425); // 425 might still be a little too much and might flip a little more than 180 degrees, so make sure the keep checking that
  servos[servoNum].write(90);
  delay(425);
}

// Makes the fire behind Envy in the last scene go up and down
void fire() {
  if (digitalRead(buttonPins[2]) == HIGH) { 
    servos[2].write(90); 
    delay(1000);
    servos[2].write(0);
    delay(1000);
  }
  else { servos[2].write(0); }
}
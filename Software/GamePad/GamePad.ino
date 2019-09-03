/*
 * JDs GamePad
 */
//including a library
#include <Gamepad.h>

//Initializing a Gamepad
Gamepad gp;

byte mapAnalogStick(int in)
{
  return map(in, 0, 1024, -127, 127);
}

void setup() 
{
  //initializing inputs
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(2,  INPUT_PULLUP);
  pinMode(3,  INPUT_PULLUP);
  pinMode(4,  INPUT_PULLUP);
  pinMode(5,  INPUT_PULLUP);
  pinMode(6,  INPUT_PULLUP);
  pinMode(7,  INPUT_PULLUP);
  pinMode(8,  INPUT_PULLUP);
  pinMode(9,  INPUT_PULLUP);
  pinMode(10,  INPUT_PULLUP);
  
  pinMode(14,  INPUT_PULLUP);
  pinMode(15,  INPUT_PULLUP);
  pinMode(16,  INPUT_PULLUP);
}

void loop() 
{
  gp.setLeftXaxis(mapAnalogStick(analogRead(A3)));
  gp.setRightXaxis(mapAnalogStick(analogRead(A2)));
  gp.setLeftYaxis(mapAnalogStick(analogRead(A1)));
  gp.setRightYaxis(mapAnalogStick(analogRead(A0)));
  
  for(int i=0; i<9; i++)
  {
    gp.setButtonState(i, digitalRead(i+2) == LOW);
  }

  for(int i=9; i<12; i++)
  {
    gp.setButtonState(i, digitalRead(i+5) == LOW);
  }
  delay(20);
}

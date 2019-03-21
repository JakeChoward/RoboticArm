#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"
#include "RoboticArm.h"

int main()
{ 
 RoboticArm roboticarm;
 WiimoteBtns myWiimote;
 // Close Wiimote event file
 
 roboticarm.MoveServo(0, 90, 90);
 roboticarm.MoveServo(1, 90, 90);
 roboticarm.MoveServo(2, 90, 90);
 roboticarm.MoveServo(3, 90, 90);
 roboticarm.MoveServo(4, 90, 90);
 
 myWiimote.Listen();
 
 return 0;
}

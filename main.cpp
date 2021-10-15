/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Andrew Bordis                                             */
/*    Created:      10/15/2021                                                */
/*    Description:  X Drive                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

/*
    Left back motor: 4
    Left front motor: 1

    Right back motor: 6
    Right front motor: 10
*/
void init_motors()
{
    RBMotor.setVelocity(0, percent);
    RFMotor.setVelocity(0, percent);
    LBMotor.setVelocity(0, percent);
    LFMotor.setVelocity(0, percent);

    RBMotor.spin(forward);
    RFMotor.spin(forward);
    LBMotor.spin(forward);
    LFMotor.spin(forward);
}

int main() {

    init_motors(); 

    do {
        int axis3Pos = Controller1.Axis3.position(), axis1Pos = Controller1.Axis1.position(), axis4Pos = Controller1.Axis4.position();

        LFMotor.setVelocity(axis3Pos + axis1Pos + axis4Pos, percent);
        LBMotor.setVelocity(-axis3Pos - axis1Pos + axis4Pos, percent);

        RFMotor.setVelocity(axis3Pos + axis1Pos + axis4Pos, percent);
        RBMotor.setVelocity(-axis3Pos - axis1Pos + axis4Pos, percent);
    } while(true);
}

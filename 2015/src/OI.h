#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Utilities/Constants.h"

class OI {
private:

	Constants *constants;

	Joystick* operatorStick;
	Joystick* driverStick;

	JoystickButton* driveShifter;
	JoystickButton* driveEnhance;
	JoystickButton* driveSlow;

	JoystickButton *dollyToggle;

	JoystickButton *toteMoverLeft;
	JoystickButton *toteMoverRight;

	JoystickButton *upperClawGrab;
	JoystickButton *upperClawRelease;

	JoystickButton *lowerClawGrab;
	JoystickButton *lowerClawRelease;

	JoystickButton *sCurveLeft;
public:
	OI();
 
	Joystick* getDriverStick();
	Joystick* getOperatorStick();

	double getDriverStickLeftX();
	double getDriverStickLeftY();
	double getDriverStickRightX();
	double getDriverStickRightY();

	double getOperatorStickLeftX();
	double getOperatorStickLeftY();
	double getOperatorStickRightX();
	double getOperatorStickRightY();
};

#endif

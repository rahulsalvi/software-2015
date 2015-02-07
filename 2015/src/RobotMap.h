#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "Utilities/Constants.h"

class RobotMap {
public:
	static LiveWindow *liveWindow;

	static Constants *constants;

	static SendableChooser *autoChooser;

	static Talon *driveTalonLeft;
	static Talon *driveTalonRight;

	static Solenoid *driveShifter;

	static Encoder *driveEncoderLeft;
	static Encoder *driveEncoderRight;

	static PIDController *driveControllerLeft;
	static PIDController *driveControllerRight;

	static SendableChooser *driveChooser;

	static Solenoid *upperClawGrabber;
	static Solenoid *upperClawBrake;

	static Solenoid *lowerClawGrabber;
	static Solenoid *lowerClawBrake;

	static Solenoid *dollyCylinder;

	static Talon *toteMoverTalon;

	static Compressor *compressor;

	static void init();
};
#endif

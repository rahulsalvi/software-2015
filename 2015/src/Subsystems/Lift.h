#ifndef LIFT_H
#define LIFT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utilities/Constants.h"

class Lift: public Subsystem {
private:
	Constants *_constants;

	Talon *_lowerLeftTalon;
	Talon *_lowerRightTalon;
	Talon *_upperTalon;

	Encoder *_lowerLeftEncoder;
	Encoder *_lowerRightEncoder;
	Encoder *_upperEncoder;

	PIDController *_lowerLeftController;
	PIDController *_lowerRightController;
	PIDController *_upperController;

	PIDProfile _lowerProfile;
	PIDProfile _upperProfile;

public:
	Lift();
	void InitDefaultCommand();

	void enableLowerController();
	void disableLowerController();

	void enableUpperController();
	void disableUpperController();

	void setLowerHeight(double height);
	void setUpperHeight(double height);

	void setLowerRaw(double value);
	void setUpperRaw(double value);

	double getLowerHeight();
	double getUpperHeight();

	double getLowerRaw();
	double getUpperRaw();

	void updatePIDCoefficients();
	PIDProfile getLowerPIDCoefficients();
	PIDProfile getUpperPIDCoefficients();
};

#endif

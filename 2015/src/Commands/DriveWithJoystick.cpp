#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick()
{
	_drivetrain = Robot::drivetrain;
	_driverStick = Robot::oi->getDriverStick();
	_rightVelocity = 0;
	_leftVelocity = 0;
	Requires(_drivetrain);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	if (_drivetrain->enhanceEnabled()) {
		if (_drivetrain->tankEnabled()) {
			_leftVelocity = _driverStick->GetRawAxis(0) * MAX_VELOCITY;
			_rightVelocity = _driverStick->GetRawAxis(1) * MAX_VELOCITY;
		} else {
			double leftJoy =_driverStick->GetRawAxis(0) + _driverStick->GetRawAxis(2);
			double rightJoy = _driverStick->GetRawAxis(0) - _driverStick->GetRawAxis(2);

			if (leftJoy > 1.0) {
				leftJoy = 1.0;
			} else if (leftJoy < -1.0) {
				leftJoy = -1.0;
			}

			if (rightJoy > 1.0) {
				rightJoy = 1.0;
			} else if (rightJoy < -1.0) {
				rightJoy = -1.0;
			}

			_leftVelocity = leftJoy * ENHANCE_SCALAR * MAX_VELOCITY;
		}
		_drivetrain->set(_leftVelocity, _rightVelocity);
	} else {
		if (_drivetrain->tankEnabled()) {
			_drivetrain->setRaw(_driverStick->GetRawAxis(0), _driverStick->GetRawAxis(1));
		} else {
			double leftJoy =_driverStick->GetRawAxis(0) + _driverStick->GetRawAxis(2);
			double rightJoy = _driverStick->GetRawAxis(0) - _driverStick->GetRawAxis(2);

			if (leftJoy > 1.0) {
				leftJoy = 1.0;
			} else if (leftJoy < -1.0) {
				leftJoy = -1.0;
			}

			if (rightJoy > 1.0) {
				rightJoy = 1.0;
			} else if (rightJoy < -1.0) {
				rightJoy = -1.0;
			}

			_drivetrain->setRaw(leftJoy, rightJoy);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted()
{

}

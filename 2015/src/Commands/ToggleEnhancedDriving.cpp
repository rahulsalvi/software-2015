#include "ToggleEnhancedDriving.h"

ToggleEnhancedDriving::ToggleEnhancedDriving()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ToggleEnhancedDriving::Initialize()
{
	Robot::drivetrain->enableEnhancedDriving(!Robot::drivetrain->enhanceEnabled());
}

// Called repeatedly when this Command is scheduled to run
void ToggleEnhancedDriving::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleEnhancedDriving::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleEnhancedDriving::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleEnhancedDriving::Interrupted()
{

}

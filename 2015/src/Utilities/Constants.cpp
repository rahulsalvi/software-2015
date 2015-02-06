/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"
#include "../Commands/UpdatePIDProfiles.h"

Constants::Constants() {
	_preferences = Preferences::GetInstance();

	drivePorts.talonLeftPort = _preferences->GetInt("TalonLeftPort", 3);
	drivePorts.talonRightPort = _preferences->GetInt("TalonRightPort", 4);
	drivePorts.shifterModule = _preferences->GetInt("ShifterModule", 0);
	drivePorts.shifterPort = _preferences->GetInt("ShifterPort", 0);
	drivePorts.encoderLeftPortA = _preferences->GetInt("EncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("EncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("EncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("EncoderRightPortB", 3);

	clawPorts.upperGrabberModule = _preferences->GetInt("UpperGrabberModule, 0");
	clawPorts.upperGrabberPort = _preferences->GetInt("UpperGrabberPort", 1);
	clawPorts.upperBrakeModule = _preferences->GetInt("UpperBrakeModule", 0);
	clawPorts.upperBrakePort = _preferences->GetInt("UpperBrakePort", 2);
	clawPorts.lowerGrabberModule = _preferences->GetInt("LowerGrabberModule", 0);
	clawPorts.lowerGrabberPort = _preferences->GetInt("LowerGrabberPort", 3);
	clawPorts.lowerBrakeModule = _preferences->GetInt("LowerBrakeModule", 0);
	clawPorts.lowerBrakePort = _preferences->GetInt("LowerBrakePort", 4);

	dollyPorts.dollyModule = _preferences->GetInt("DollyModule", 0);
	dollyPorts.dollyPort = _preferences->GetInt("DollyPort", 5);

	toteMoverPorts.toteMoverPort = _preferences->GetInt("ToteMoverPort", 5);

	compressorPorts.compressorModule = _preferences->GetInt("CompressorModule", 0);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);
	oiPorts.shiftButton = _preferences->GetInt("ShiftButton", 6);
	oiPorts.slowButton = _preferences->GetInt("SlowButton", 5);
	oiPorts.toggleEnhanceDriveButton = _preferences->GetInt("ToggleEnhanceDriveButton", 8);
	oiPorts.toggleDollyButton = _preferences->GetInt("ToggleDollyButton", 3);
	oiPorts.toteMoverLeftButton = _preferences->GetInt("ToteMoverLeftButton", 2);
	oiPorts.toteMoverRightButton = _preferences->GetInt("ToteMoverRightButton", 1);

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	dollyStates.back = _preferences->GetBoolean("DollyBack", true);
	dollyStates.forward = _preferences->GetBoolean("DollyForward", false);

	toteMoverStates.moveTotesLeft = _preferences->GetDouble("MoveTotesLeft", -1);
	toteMoverStates.moveTotesRight = _preferences->GetDouble("MoveTotesRight", 1);
	toteMoverStates.stop = _preferences->GetDouble("ToteMoverStop", 0);

	driveConstants.maxVelocityHigh = _preferences->GetDouble("MaxVelocityHigh", 0);
	driveConstants.maxVelocityLow = _preferences->GetDouble("MaxVelocityLow", 0);
	driveConstants.enhanceScalar = _preferences->GetDouble("EnhanceScalar", 0.9);
	driveConstants.slowScalar = _preferences->GetDouble("SlowScalar", 0.75);
	driveConstants.distancePerPulse = _preferences->GetDouble("DistancePerPulse", 0.147262);

	updatePIDProfiles();
	SmartDashboard::PutData(new UpdatePIDProfiles());
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
}

PIDProfile Constants::getDriveProfile(bool highGear, bool encoderVelocityMode, int items) {
	if (encoderVelocityMode) {
		if (highGear == shifterStates.highGear) {
			return driveProfiles[0 + items];		//high gear velocity
		} else {
			return driveProfiles[5 + items];		//low gear velocity
		}
	} else {
		if (highGear == shifterStates.highGear) {
			return driveProfiles[10 + items];		//high gear position
		} else {
			return driveProfiles[15 + items];		//low gear position
		}
	}
}

void Constants::updatePIDProfiles() {
	driveProfiles[0].p = _preferences->GetDouble("DriveProfile0P", 0);
	driveProfiles[0].i = _preferences->GetDouble("DriveProfile0I", 0);
	driveProfiles[0].d = _preferences->GetDouble("DriveProfile0D", 0);
	driveProfiles[0].f = _preferences->GetDouble("DriveProfile0F", 0);

	driveProfiles[1].p = _preferences->GetDouble("DriveProfile1P", 0);
	driveProfiles[1].i = _preferences->GetDouble("DriveProfile1I", 0);
	driveProfiles[1].d = _preferences->GetDouble("DriveProfile1D", 0);
	driveProfiles[1].f = _preferences->GetDouble("DriveProfile1F", 0);

	driveProfiles[2].p = _preferences->GetDouble("DriveProfile2P", 0);
	driveProfiles[2].i = _preferences->GetDouble("DriveProfile2I", 0);
	driveProfiles[2].d = _preferences->GetDouble("DriveProfile2D", 0);
	driveProfiles[2].f = _preferences->GetDouble("DriveProfile2F", 0);

	driveProfiles[3].p = _preferences->GetDouble("DriveProfile3P", 0);
	driveProfiles[3].i = _preferences->GetDouble("DriveProfile3I", 0);
	driveProfiles[3].d = _preferences->GetDouble("DriveProfile3D", 0);
	driveProfiles[3].f = _preferences->GetDouble("DriveProfile3F", 0);

	driveProfiles[4].p = _preferences->GetDouble("DriveProfile4P", 0);
	driveProfiles[4].i = _preferences->GetDouble("DriveProfile4I", 0);
	driveProfiles[4].d = _preferences->GetDouble("DriveProfile4D", 0);
	driveProfiles[4].f = _preferences->GetDouble("DriveProfile4F", 0);

	driveProfiles[5].p = _preferences->GetDouble("DriveProfile5P", 0);
	driveProfiles[5].i = _preferences->GetDouble("DriveProfile5I", 0);
	driveProfiles[5].d = _preferences->GetDouble("DriveProfile5D", 0);
	driveProfiles[5].f = _preferences->GetDouble("DriveProfile5F", 0);

	driveProfiles[6].p = _preferences->GetDouble("DriveProfile6P", 0);
	driveProfiles[6].i = _preferences->GetDouble("DriveProfile6I", 0);
	driveProfiles[6].d = _preferences->GetDouble("DriveProfile6D", 0);
	driveProfiles[6].f = _preferences->GetDouble("DriveProfile6F", 0);

	driveProfiles[7].p = _preferences->GetDouble("DriveProfile7P", 0);
	driveProfiles[7].i = _preferences->GetDouble("DriveProfile7I", 0);
	driveProfiles[7].d = _preferences->GetDouble("DriveProfile7D", 0);
	driveProfiles[7].f = _preferences->GetDouble("DriveProfile7F", 0);

	driveProfiles[8].p = _preferences->GetDouble("DriveProfile8P", 0);
	driveProfiles[8].i = _preferences->GetDouble("DriveProfile8I", 0);
	driveProfiles[8].d = _preferences->GetDouble("DriveProfile8D", 0);
	driveProfiles[8].f = _preferences->GetDouble("DriveProfile8F", 0);

	driveProfiles[9].p = _preferences->GetDouble("DriveProfile9P", 0);
	driveProfiles[9].i = _preferences->GetDouble("DriveProfile9I", 0);
	driveProfiles[9].d = _preferences->GetDouble("DriveProfile9D", 0);
	driveProfiles[9].f = _preferences->GetDouble("DriveProfile9F", 0);
}

















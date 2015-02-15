/*
 * Constants.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: 2658
 */

#include "Constants.h"
#include "../Commands/Utilities/UpdatePIDProfiles.h"
#include "../Commands/Utilities/CompressorOn.h"
#include "../Commands/Utilities/CompressorOff.h"

Constants::Constants() {
	_preferences = Preferences::GetInstance();

	drivePorts.talonLeftPort = _preferences->GetInt("DriveTalonLeftPort", 3);
	drivePorts.talonRightPort = _preferences->GetInt("DriveTalonRightPort", 4);
	drivePorts.shifterModule = _preferences->GetInt("ShifterModule", 0);
	drivePorts.shifterPort = _preferences->GetInt("ShifterPort", 5);
	drivePorts.encoderLeftPortA = _preferences->GetInt("DriveEncoderLeftPortA", 0);
	drivePorts.encoderLeftPortB = _preferences->GetInt("DriveEncoderLeftPortB", 1);
	drivePorts.encoderRightPortA = _preferences->GetInt("DriveEncoderRightPortA", 2);
	drivePorts.encoderRightPortB = _preferences->GetInt("DriveEncoderRightPortB", 3);

	clawPorts.upperGrabberModule = _preferences->GetInt("UpperGrabberModule, 0");
	clawPorts.upperGrabberPort = _preferences->GetInt("UpperGrabberPort", 0);
	clawPorts.upperBrakeModule = _preferences->GetInt("UpperBrakeModule", 0);
	clawPorts.upperBrakePort = _preferences->GetInt("UpperBrakePort", 1);
	clawPorts.lowerGrabberModule = _preferences->GetInt("LowerGrabberModule", 0);
	clawPorts.lowerGrabberPort = _preferences->GetInt("LowerGrabberPort", 2);
	clawPorts.lowerBrakeModule = _preferences->GetInt("LowerBrakeModule", 0);
	clawPorts.lowerBrakePort = _preferences->GetInt("LowerBrakePort", 3);

	liftPorts.lowerTalonLeftPort = _preferences->GetInt("LiftLowerTalonLeftPort", 0);
	liftPorts.lowerTalonRightPort = _preferences->GetInt("LiftLowerTalonRightPort", 1);
	liftPorts.upperTalonPort = _preferences->GetInt("LiftUpperTalonPort", 2);
	liftPorts.lowerEncoderLeftPortA = _preferences->GetInt("LiftLowerEncoderLeftPortA", 4);
	liftPorts.lowerEncoderLeftPortB = _preferences->GetInt("LiftLowerEncoderLeftPortB", 5);
	liftPorts.lowerEncoderRightPortA = _preferences->GetInt("LiftLowerEncoderRightPortA", 6);
	liftPorts.lowerEncoderRightPortB = _preferences->GetInt("LiftLowerEncoderRightPortB", 7);
	liftPorts.upperEncoderPortA = _preferences->GetInt("LiftUpperEncoderPortA", 8);
	liftPorts.upperEncoderPortB = _preferences->GetInt("LiftUpperEncoderPortB", 9);

	dollyPorts.dollyModule = _preferences->GetInt("DollyModule", 0);
	dollyPorts.dollyPort = _preferences->GetInt("DollyPort", 4);

	toteMoverPorts.toteMoverPort = _preferences->GetInt("ToteMoverPort", 5);

	compressorPorts.compressorModule = _preferences->GetInt("CompressorModule", 0);

	oiPorts.driverPort = _preferences->GetInt("DriverPort", 0);
	oiPorts.operatorPort = _preferences->GetInt("OperatorPort", 1);

	driverButtons.shiftButton = _preferences->GetInt("ShiftButton", 6);
	driverButtons.slowButton = _preferences->GetInt("SlowButton", 5);
	driverButtons.toggleEnhancedDriveButton = _preferences->GetInt("ToggleEnhancedDriveButton", 8);

	operatorButtons.toggleDollyButton = _preferences->GetInt("ToggleDollyButton", 2);
	operatorButtons.toteMoverLeftPOV = _preferences->GetInt("ToteMoverLeftPOV", 270);
	operatorButtons.toteMoverRightPOV = _preferences->GetInt("ToteMoverRightPOV", 90);
	operatorButtons.upperClawGrabButton = _preferences->GetInt("UpperClawGrabButton", 6);
	operatorButtons.upperClawReleaseButton = _preferences->GetInt("UpperClawReleaseButton", 8);
	operatorButtons.lowerClawGrabButton = _preferences->GetInt("LowerClawGrabButton", 5);
	operatorButtons.lowerClawReleaseButton = _preferences->GetInt("LowerClawReleaseButton", 7);
	operatorButtons.lowerClawItemCountResetButton = _preferences->GetInt("LowerClawItemCountResetButton", 4);
	operatorButtons.lowerClawItemCountIncrementButton = _preferences->GetInt("LowerClawItemCountIncrementButton", 3);
	operatorButtons.lowerClawItemCountDecrementButton = _preferences->GetInt("LowerClawItemCountDecrementButton", 1);
	operatorButtons.lowerLiftAutomaticDisableButton = _preferences->GetInt("LowerLiftAutomaticDisableButton", 11);
	operatorButtons.upperLiftAutomaticDisableButton = _preferences->GetInt("UpperLiftAutomaticDisableButton", 12);

	driverAxes.leftX = _preferences->GetInt("DriverLeftX", 0);
	driverAxes.leftY = _preferences->GetInt("DriverLeftY", 1);
	driverAxes.rightX = _preferences->GetInt("DriverRightX", 4);
	driverAxes.rightY = _preferences->GetInt("DriverRightY", 5);

	operatorAxes.leftX = _preferences->GetInt("OperatorLeftX", 0);
	operatorAxes.leftY = _preferences->GetInt("OperatorLeftY", 1);
	operatorAxes.rightX = _preferences->GetInt("OperatorRightX", 2);
	operatorAxes.rightY = _preferences->GetInt("OperatorRightY", 3);

	shifterStates.highGear = _preferences->GetBoolean("HighGear", true);
	shifterStates.lowGear = _preferences->GetBoolean("LowGear", false);

	clawStates.upperClawGrab = _preferences->GetBoolean("UpperClawGrab", true);
	clawStates.upperClawBrakeOn = _preferences->GetBoolean("UpperClawBrakeOn", true);
	clawStates.lowerClawGrab = _preferences->GetBoolean("LowerClawGrab", true);
	clawStates.lowerClawBrakeOn = _preferences->GetBoolean("LowerClawBrakeOn", true);

	dollyStates.back = _preferences->GetBoolean("DollyBack", true);
	dollyStates.forward = _preferences->GetBoolean("DollyForward", false);

	toteMoverStates.moveTotesLeft = _preferences->GetDouble("MoveTotesLeft", -1);
	toteMoverStates.moveTotesRight = _preferences->GetDouble("MoveTotesRight", 1);
	toteMoverStates.stop = _preferences->GetDouble("ToteMoverStop", 0);

	driveConstants.enhancedMaxVelocityHigh = _preferences->GetDouble("EnhancedMaxVelocityHigh", 190);
	driveConstants.enhancedMaxVelocityLow = _preferences->GetDouble("EnhancedMaxVelocityLow", 75);
	driveConstants.slowScalar = _preferences->GetDouble("SlowScalar", 0.6);
	driveConstants.distancePerPulse = _preferences->GetDouble("DriveDistancePerPulse", 0.027271);
	driveConstants.shiftTime = _preferences->GetDouble("ShiftTime", 0.25);
	driveConstants.velocityTestSampleTime = _preferences->GetDouble("VelocityTestSampleTime", 1);
	driveConstants.velocityTestAccelerationTime = _preferences->GetDouble("VelocityTestAccelerationTime", 2);

	liftConstants.distancePerPulse = _preferences->GetDouble("LiftDistancePerPulse", 0);
	liftConstants.lowerClawWidth = _preferences->GetDouble("LowerClawWidth", 0);
	liftConstants.upperClawWidth = _preferences->GetDouble("UpperClawWidth", 0);
	liftConstants.bufferFromTop = _preferences->GetDouble("BufferFromTop", 0);
	liftConstants.bufferBetweenClaws = _preferences->GetDouble("BufferBetweenClaws", 0);
	liftConstants.bufferFromBottom = _preferences->GetDouble("BufferFromBottom", 0);

	liftHeights.lowerClawMaxHeight = _preferences->GetDouble("LowerClawMaxHeight", 0);
	liftHeights.upperClawMaxHeight = _preferences->GetDouble("UpperClawMaxHeight", 0);

	pneumaticConstants.startingPressure = _preferences->GetDouble("StartingPressure", 115);
	pneumaticConstants.currentPressure = pneumaticConstants.startingPressure;
	pneumaticConstants.compressorOnPressure = _preferences->GetDouble("CompressorOnPressure", 80);
	pneumaticConstants.shifterActuationLoss = _preferences->GetDouble("ShifterActuationLoss", 0);
	pneumaticConstants.dollyActuationLoss = _preferences->GetDouble("DollyActuationLoss", 0);
	pneumaticConstants.upperClawGrabberActuationLoss = _preferences->GetDouble("UpperClawGrabberActuationLoss", 0);
	pneumaticConstants.upperClawBrakeActuationLoss = _preferences->GetDouble("UpperClawBrakeActuationLoss", 0);
	pneumaticConstants.lowerClawGrabberActuationLoss = _preferences->GetDouble("LowerClawGrabberActuationLoss", 0);
	pneumaticConstants.lowerClawBrakeActuationLoss = _preferences->GetDouble("LowerClawBrakeActuationLoss", 0);

	itemCounts.lowerClawItems = 0;
	itemCounts.upperClawItems = 0;
	itemCounts.lowerClawMaxItems = _preferences->GetInt("LowerClawMaxItems", 4);
	itemCounts.upperClawMaxItems = _preferences->GetInt("UpperClawMaxItems", 1);

	updatePIDProfiles();
	SmartDashboard::PutData("UpdatePIDProfiles", new UpdatePIDProfiles());

	SmartDashboard::PutData("CompressorOn", new CompressorOn());
	SmartDashboard::PutData("CompressorOff", new CompressorOff());
	SmartDashboard::PutNumber("Current Pressure", pneumaticConstants.currentPressure);
	SmartDashboard::PutString("Compressor", "OFF");

	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

Constants::~Constants() {
	// TODO Auto-generated destructor stub
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


PIDProfile Constants::getDriveProfile(bool highGear) {
	if (highGear == shifterStates.highGear) {
		return driveProfiles[0 + itemCounts.lowerClawItems + itemCounts.upperClawItems];
	} else {
		return driveProfiles[5 + itemCounts.lowerClawItems + itemCounts.upperClawItems];
	}
}


void Constants::incrementLowerClawItems() {
	if (itemCounts.lowerClawItems < itemCounts.lowerClawMaxItems) {
		itemCounts.lowerClawItems++;
	}
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::decrementLowerClawItems() {
	if (itemCounts.lowerClawItems > 0) {
		itemCounts.lowerClawItems--;
	}
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::resetLowerClawItems() {
	itemCounts.lowerClawItems = 0;
	SmartDashboard::PutNumber("Lower Claw Items", itemCounts.lowerClawItems);
}

void Constants::incrementUpperClawItems() {
	if (itemCounts.upperClawItems < itemCounts.upperClawMaxItems) {
		itemCounts.upperClawItems++;
	}
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

void Constants::decrementUpperClawItems() {
	if (itemCounts.upperClawItems > 0) {
		itemCounts.upperClawItems--;
	}
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

void Constants::resetUpperClawItems() {
	itemCounts.upperClawItems = 0;
	SmartDashboard::PutNumber("Upper Claw Items", itemCounts.upperClawItems);
}

void Constants::reducePressure(double pressureLoss) {
	pneumaticConstants.currentPressure -= pressureLoss;
	if (pneumaticConstants.currentPressure <= pneumaticConstants.compressorOnPressure) {
		Command *c = new CompressorOn();
		c->Start();
		pneumaticConstants.currentPressure = pneumaticConstants.startingPressure;
		SmartDashboard::PutString("Compressor", "ON");
	}
	SmartDashboard::PutNumber("Current Pressure", pneumaticConstants.currentPressure);
}















#ifndef ShiftHigh_H
#define ShiftHigh_H

#include "../Robot.h"
#include "WPILib.h"

class ShiftHigh: public Command
{
public:
	ShiftHigh();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
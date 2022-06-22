#pragma once
#include "Main.h"
//#include "CalculatorProcessor.h"
//class CalculatorProcessor;

class IBaseCommand
{
public:
	//CalculatorProcessor* processor;
	virtual int Execute() = 0;
};


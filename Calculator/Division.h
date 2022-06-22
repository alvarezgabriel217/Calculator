#pragma once
#include "IBaseCommand.h"
#include "CalculatorProcessor.h"
class CalculatorProcessor;

class Division : public IBaseCommand
{
private:
	int _num1;
	int _num2;
	CalculatorProcessor* processor;
public:
	Division(int num1, int num2);
	int Execute();
};


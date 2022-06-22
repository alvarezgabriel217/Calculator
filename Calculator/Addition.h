#pragma once
#include "IBaseCommand.h"
class CalculatorProcessor;

class Addition : public IBaseCommand
{
private:
	int _num1;
	int _num2;
	CalculatorProcessor* processor;
public:
	Addition(int num1, int num2);
	int Execute();
};


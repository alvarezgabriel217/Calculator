#include "Subtraction.h"
#include "CalculatorProcessor.h"
Subtraction::Subtraction(int num1, int num2)
{
	_num1 = num1;
	_num2 = num2;
	processor = CalculatorProcessor::GetInstance();
}
int Subtraction::Execute()
{
	return processor->Subtraction(_num1, _num2);
}

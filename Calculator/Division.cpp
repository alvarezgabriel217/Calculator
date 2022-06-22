#include "Division.h"
#include "CalculatorProcessor.h"
Division::Division(int num1, int num2)
{
	_num1 = num1;
	_num2 = num2;
	processor = CalculatorProcessor::GetInstance();
}
int Division::Execute()
{
	return processor->Division(_num1, _num2);
}
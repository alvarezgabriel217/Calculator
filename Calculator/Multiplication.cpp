#include "Multiplication.h"
#include "CalculatorProcessor.h"
Multiplication::Multiplication(int num1, int num2)
{
	_num1 = num1;
	_num2 = num2;
	processor = CalculatorProcessor::GetInstance();
}
int Multiplication::Execute()
{
	return processor->Multiplication(_num1, _num2);
}
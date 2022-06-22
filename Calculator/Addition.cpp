#include "Addition.h"
#include "CalculatorProcessor.h"
Addition::Addition(int num1, int num2)
{
	_num1 = num1;
	_num2 = num2;
	processor = CalculatorProcessor::GetInstance();
}
int Addition::Execute()
{
	return processor->Addition(_num1, _num2);
}
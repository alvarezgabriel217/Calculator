#include "CalculatorProcessor.h"
CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	static CalculatorProcessor* _processor;
	if (_processor == nullptr)
	{
		_processor = new CalculatorProcessor();
	}
	return _processor;
}
//CalculatorProcessor* CalculatorProcessor::GetInstance()
//{
//	if (_processor == nullptr)
//	{
//		_processor = new CalculatorProcessor();
//	}
//	return _processor;
//}
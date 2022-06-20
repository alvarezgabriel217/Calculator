#pragma once
#include <string>
class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
public:
	CalculatorProcessor()
	{
	}

	static CalculatorProcessor* GetInstance()
	{
		if (_processor == nullptr)
		{
			_processor = new CalculatorProcessor();
		}
		return _processor;
	}

	CalculatorProcessor(CalculatorProcessor& other) = delete;

	void operator=(const CalculatorProcessor& other) = delete;

	int Addition(int num1, int num2)
	{
		return (num1 + num2);
	}
	int Subtraction(int num1, int num2)
	{
		return (num1 - num2);
	}
	int Multiplication(int num1, int num2)
	{
		return (num1 * num2);
	}
	int Division(int num1, int num2)
	{
		return (num1 / num2);
	}
};

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;
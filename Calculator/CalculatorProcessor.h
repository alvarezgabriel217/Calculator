#pragma once
#include <string>
//#include "IBaseCommand.h"
#include <vector>

class IBaseCommand;

class CalculatorProcessor
{
private:
	//static CalculatorProcessor* _processor;
	CalculatorProcessor()
	{
	}
public:
	std::vector<IBaseCommand*> commands;

	static CalculatorProcessor* GetInstance();

	/*static CalculatorProcessor& GetInstance()
	{
		static CalculatorProcessor processor;
		return processor;
	}*/

	/*{
		if (_processor == nullptr)
		{
			_processor = new CalculatorProcessor();
		}
		return _processor;
	}*/

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
	std::string ToBinary(int num)
	{
		std::string bin;
		for (int i = 0; i < 26; i++)
		{
			if (num % 2 == 0)
			{
				bin = "0" + bin;
			}
			else
			{
				bin = "1" + bin;
			}
			num /= 2;
		}
		return bin;
	}
	std::string ToHexadecimal(int num)
	{
		std::string hex;
		while (true)
		{
			if (num % 16 < 10)
			{
				hex = std::to_string(num % 16) + hex;
			}
			else if (num % 16 == 10)
			{
				hex = "A" + hex;
			}
			else if (num % 16 == 11)
			{
				hex = "B" + hex;
			}
			else if (num % 16 == 12)
			{
				hex = "C" + hex;
			}
			else if (num % 16 == 13)
			{
				hex = "D" + hex;
			}
			else if (num % 16 == 14)
			{
				hex = "E" + hex;
			}
			else if (num % 16 == 15)
			{
				hex = "F" + hex;
			}
			num /= 16;
			if (num == 0)
			{
				hex = "0x" + hex;
				break;
			}
		}
		return hex;
	}
};

//CalculatorProcessor* CalculatorProcessor::_processor = nullptr;
#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/CalculatorProcessor.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
		TEST_METHOD(FivePlusThirty)
		{
			int answer = processor->Addition(5, 30);
			Assert::AreEqual(answer, 35);
		}
		TEST_METHOD(SeventyMinusTwentyFive)
		{
			int answer = processor->Subtraction(70, 25);
			Assert::AreEqual(answer, 45);
		}
		TEST_METHOD(FourHundredAndTwentyDividedByEighty)
		{
			int answer = processor->Division(420, 80);
			Assert::AreEqual(answer, 5);
		}
		TEST_METHOD(NineTimesNine)
		{
			int answer = processor->Multiplication(9, 9);
			Assert::AreEqual(answer, 81);
		}
		TEST_METHOD(FourHundredAndTwentyToBinary)
		{
			std::string answer = processor->ToBinary(420);
			Assert::AreEqual("00000000000000000110100100", answer.c_str());
		}
		TEST_METHOD(FourtyFourtToHexadecimal)
		{
			std::string answer = processor->ToHexadecimal(44);
			Assert::AreEqual("0x2C", answer.c_str());
		}
		TEST_METHOD(NegativeFivePlusNegativeThirty)
		{
			int answer = processor->Addition(-5, -30);
			Assert::AreEqual(answer, -35);
		}
		TEST_METHOD(NegativeSeventyMinusNegativeTwentyFive)
		{
			int answer = processor->Subtraction(-70, -30);
			Assert::AreEqual(answer, -40);
		}
		TEST_METHOD(NegativeFourHundredAndTwentyDividedByNegativeEighty)
		{
			int answer = processor->Division(-420, -80);
			Assert::AreEqual(answer, 5);
		}
		TEST_METHOD(NegativeNineTimesNine)
		{
			int answer = processor->Multiplication(-9, 9);
			Assert::AreEqual(answer, -81);
		}
	};
}

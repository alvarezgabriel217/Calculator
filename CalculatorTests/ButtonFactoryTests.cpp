#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/ButtonFactory.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		ButtonFactory factory;
		int i = 9;
		TEST_METHOD(Button1)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10000, i);
			int answer = button->GetId();
			Assert::AreEqual(answer, 10000);
		}
		TEST_METHOD(Button2)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10001, i);
			int answer = button->GetId();
			Assert::AreEqual(answer, 10001);
		}
		TEST_METHOD(Button3)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10002, i);
			int answer = button->GetId();
			Assert::AreEqual(answer, 10002);
		}
		TEST_METHOD(Button4)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10003, i);
			int answer = button->GetId();
			Assert::AreEqual(answer, 10003);
		}
		TEST_METHOD(Button5)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10004, i);
			int answer = button->GetId();
			Assert::AreEqual(answer, 10004);
		}
		TEST_METHOD(Button6)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10007, i);
			std::string answer = button->GetLabel();
			Assert::AreEqual("*", answer.c_str());
		}
		TEST_METHOD(Button7)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10011, i);
			std::string answer = button->GetLabel();
			Assert::AreEqual("/", answer.c_str());
		}
		TEST_METHOD(Button8)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10015, i);
			std::string answer = button->GetLabel();
			Assert::AreEqual("+", answer.c_str());
		}
		TEST_METHOD(Button9)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10019, i);
			std::string answer = button->GetLabel();
			Assert::AreEqual("-", answer.c_str());
		}
		TEST_METHOD(Button10)
		{
			wxButton* button = factory.AddButton(new wxWindow, 10023, i);
			std::string answer = button->GetLabel();
			Assert::AreEqual("=", answer.c_str());
		}
	};
}

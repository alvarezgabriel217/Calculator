#include "Main.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"
#include "IBaseCommand.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <vector>

wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(10000, OnButtonClicked)
EVT_BUTTON(10001, OnButtonClicked)
EVT_BUTTON(10002, OnButtonClicked)
EVT_BUTTON(10003, OnButtonClicked)
EVT_BUTTON(10004, OnButtonClicked)
EVT_BUTTON(10007, OnButtonClicked)
EVT_BUTTON(10008, OnButtonClicked)
EVT_BUTTON(10009, OnButtonClicked)
EVT_BUTTON(10010, OnButtonClicked)
EVT_BUTTON(10011, OnButtonClicked)
EVT_BUTTON(10012, OnButtonClicked)
EVT_BUTTON(10013, OnButtonClicked)
EVT_BUTTON(10014, OnButtonClicked)
EVT_BUTTON(10015, OnButtonClicked)
EVT_BUTTON(10016, OnButtonClicked)
EVT_BUTTON(10017, OnButtonClicked)
EVT_BUTTON(10018, OnButtonClicked)
EVT_BUTTON(10019, OnButtonClicked)
EVT_BUTTON(10020, OnButtonClicked)
EVT_BUTTON(10021, OnButtonClicked)
EVT_BUTTON(10023, OnButtonClicked)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(400, 150), wxSize(500, 600))
{
	ButtonFactory factory;

	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 50));
	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 550));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	wxFont textFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont buttonFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	text = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(500, 50), wxTE_RIGHT);

	text->SetFont(textFont);

	sizer->Add(panel, 0, wxEXPAND);
	sizer->Add(panel2, 1, wxEXPAND);


	buttons = new wxButton * [6 * 4];

	wxGridSizer* grid = new wxGridSizer(6, 4, 0, 0);

	int num = 9;
	for (int i = 0; i < 24; i++)
	{

		buttons[i] = factory.AddButton(panel2, 10000 + i, num);
		buttons[i]->SetFont(buttonFont);
		grid->Add(buttons[i], 1, wxEXPAND);
		//buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
	}

	this->SetSizerAndFit(sizer);
	panel2->SetSizer(grid);
	grid->Layout();
}

Main::~Main()
{
	delete[] buttons;
}

void Main::OnButtonClicked(wxCommandEvent& evt)
{
	int id = evt.GetId() - 10000;

	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();

	std::vector<std::string> numbers(2);
	int answer = 0;

	if (id == 0)
	{
		if (bin == "")
		{
			/*int baseNumber = dec;
			for (int i = 0; i < 26; i++)
			{
				if (baseNumber % 2 == 0)
				{
					bin = "0" + bin;
				}
				else
				{
					bin = "1" + bin;
				}
				baseNumber /= 2;
			}*/
			text->SetLabel(processor->ToBinary(dec));
		}
		//text->SetLabel(bin);
	}
	else if (id == 1)
	{
		/*int baseNumber = dec;
		while (true)
		{
			if (baseNumber % 16 < 10)
			{
				hex = std::to_string(baseNumber % 16) + hex;
			}
			else if (baseNumber % 16 == 10)
			{
				hex = "A" + hex;
			}
			else if (baseNumber % 16 == 11)
			{
				hex = "B" + hex;
			}
			else if (baseNumber % 16 == 12)
			{
				hex = "C" + hex;
			}
			else if (baseNumber % 16 == 13)
			{
				hex = "D" + hex;
			}
			else if (baseNumber % 16 == 14)
			{
				hex = "E" + hex;
			}
			else if (baseNumber % 16 == 15)
			{
				hex = "F" + hex;
			}
			baseNumber /= 16;
			if (baseNumber == 0)
			{
				hex = "0x" + hex;
				break;
			}
		}*/
		text->SetLabel(processor->ToHexadecimal(dec));
		//text->SetLabel(hex);
	}
	else if (id == 2)
	{
		text->SetLabel(std::to_string(dec));
	}
	else if (id == 3)
	{
		text->SetLabel("");
		symbol = ' ';
		bin = "";
		dec = 0;
		hex = "";
	}
	else if (id == 4)
	{

	}
	else if (id == 7 || id == 11 || id == 15)
	{
		if (symbol == ' ')
		{
			text->AppendText(buttons[id]->GetLabel());
			symbol = buttons[id]->GetLabel()[0];
		}
	}
	else if (id == 19)
	{
		text->AppendText('-');
	}
	else if (id == 20)
	{
		dec -= dec * 2;
		equation = std::to_string(dec);
		text->SetLabel(equation);
	}
	else if (id == 23)
	{
		equation = text->GetValue();
		int i = 0;
		while (equation != "")
		{
			if (isdigit(equation[0]) || numbers[i] == "")
			{
				numbers[i] += equation[0];
			}
			else
			{
				if (equation[0] == '-')
				{
					symbol = '-';
				}
				i++;
			}
			equation.erase(0, 1);
		}
		/*switch (symbol)
		{
		case '+':
			answer = processor->Addition(std::stoi(numbers[0]), std::stoi(numbers[1]));
			break;
		case '-':
			answer = processor->Subtraction(std::stoi(numbers[0]), std::stoi(numbers[1]));
			break;
		case '*':
			answer = processor->Multiplication(std::stoi(numbers[0]), std::stoi(numbers[1]));
			break;
		case '/':
			answer = processor->Division(std::stoi(numbers[0]), std::stoi(numbers[1]));
			break;
		}*/

		if (numbers[1] != "")
		{

			switch (symbol)
			{
			case '+':
				/*Addition* add = new Addition(std::stoi(numbers[0]), std::stoi(numbers[1]));
				processor = add->processor;
				processor->commands.push_back(add);*/
				processor->commands.push_back(new Addition(std::stoi(numbers[0]), std::stoi(numbers[1])));
				break;
			case '-':
				processor->commands.push_back(new Subtraction(std::stoi(numbers[0]), std::stoi(numbers[1])));
				break;
			case '*':
				processor->commands.push_back(new Multiplication(std::stoi(numbers[0]), std::stoi(numbers[1])));
				break;
			case '/':
				processor->commands.push_back(new Division(std::stoi(numbers[0]), std::stoi(numbers[1])));
				break;
			}

			for (int i = 0; i < processor->commands.size(); i++)
			{
				answer = processor->commands[i]->Execute();
			}
			processor->commands.clear();
			symbol = ' ';

			text->SetLabel(std::to_string(answer));
			dec = answer;
		}
	}
	else
	{
		text->AppendText(buttons[id]->GetLabel());
		equation = text->GetValue();
		dec = std::stoi(equation);
	}
	evt.Skip();
}
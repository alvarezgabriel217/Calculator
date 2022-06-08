#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(400, 150), wxSize(500, 600))
{


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

		buttons[i] = new wxButton(panel2, 10000 + i, wxEmptyString);
		buttons[i]->SetFont(buttonFont);
		grid->Add(buttons[i], 1, wxEXPAND);
		switch (i)
		{
		case 0:
			buttons[i]->SetLabel("BIN");
			break;
		case 1:
			buttons[i]->SetLabel("HEX");
			break;
		case 2:
			buttons[i]->SetLabel("DEC");
			break;
		case 3:
			buttons[i]->SetLabel("C");
			break;
		case 4:
			buttons[i]->SetLabel("%");
			break;
		case 5:
			buttons[i]->Enable(false);
			break;
		case 6:
			buttons[i]->Enable(false);
			break;
		case 7:
			buttons[i]->SetLabel("*");
			break;
		case 11:
			buttons[i]->SetLabel("/");
			break;
		case 15:
			buttons[i]->SetLabel("+");
			break;
		case 19:
			buttons[i]->SetLabel("-");
			break;
		case 20:
			buttons[i]->SetLabel("+/-");
			break;
		case 22:
			buttons[i]->Enable(false);
			break;
		case 23:
			buttons[i]->SetLabel("=");
			break;
		default:
			buttons[i]->SetLabel(std::to_string(num));
			num--;
			break;
		}

	}

	this->SetSizerAndFit(sizer);
	panel2->SetSizer(grid);
	grid->Layout();
}

Main::~Main()
{
	delete[] buttons;
}
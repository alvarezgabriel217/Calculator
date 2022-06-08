#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(400, 150), wxSize(500, 600))
{


	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 50));

	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 575));

	//panel->SetBackgroundColour(wxColor(200, 100, 100));
	//this->SetBackgroundColour(wxColor(204, 204, 204));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 0), wxSize(300, 50), wxTE_RIGHT);
	sizer->Add(panel, 0, wxEXPAND | wxBOTTOM, 5);
	sizer->Add(panel2, 1, wxEXPAND);


	buttons = new wxButton * [7 * 3];

	wxGridSizer* grid = new wxGridSizer(6, 4, 0, 0);

	for (int i = 0; i < 21; i++)
	{
		buttons[i] = new wxButton(panel2, 10000 + i, wxEmptyString);
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
			buttons[i]->Enable(false);
			break;
		default:
			buttons[i]->SetLabel(std::to_string(i-3));
			break;
		}

	}

	//for (int x = 0; x < 7; x++)
	//{
	//	for (int y = 0; y < 3; y++)
	//	{
	//		buttons[y * 7 + x] = new wxButton(this, 10000 + (y * 7 + x), wxEmptyString, wxDefaultPosition, wxSize(100, 25));
	//		//grid->Add(buttons[y * 7 + x], 0, wxEXPAND);
	//		sizer->Add(buttons[y * 7 + x], 1);

	//		if (y * 7 + x == 0)
	//		{
	//			buttons[y * 7 + x]->SetLabel("BIN");
	//		}
	//		else if (y * 7 + x == 7)
	//		{
	//			buttons[y * 7 + x]->SetLabel("HEX");
	//		}
	//		else if (y * 7 + x == 14)
	//		{
	//			buttons[y * 7 + x]->SetLabel("DEC");
	//		}
	//		else
	//		{
	//			buttons[y * 7 + x]->SetLabel(std::to_string(y));
	//		}
	//	}
	//}

	this->SetSizer(sizer);
	panel2->SetSizer(grid);
	grid->Layout();
}

Main::~Main()
{
	delete[] buttons;
}
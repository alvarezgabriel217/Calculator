#include "Main.h"
#include "ButtonFactory.h"

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

	if (id == 0 || id == 1 || id == 2 || id == 20 || id == 23)
	{

	}
	else if (id == 3)
	{
		text->SetLabel("");
	}
	else
	{
		text->AppendText(buttons[id]->GetLabel());
	}
	evt.Skip();
}
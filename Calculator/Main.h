#pragma once

#include "wx/wx.h"
#include "ButtonFactory.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();
public:
	wxButton** buttons;
	wxTextCtrl* text;
	void OnButtonClicked(wxCommandEvent& evt);
	wxChar symbol = ' ';

	wxDECLARE_EVENT_TABLE();
};


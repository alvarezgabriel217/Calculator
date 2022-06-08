#pragma once

#include "wx/wx.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();
public:
	wxButton** buttons;
	wxTextCtrl* text;
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};


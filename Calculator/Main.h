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
	wxPanel* panel;
	wxPanel* panel2;
};


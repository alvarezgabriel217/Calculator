#pragma once

#include "wx/wx.h"

class ButtonFactory
{

public:
	wxButton* AddButton(wxWindow* parent, int id, int &num);
};


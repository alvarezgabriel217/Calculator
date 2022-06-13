#include "ButtonFactory.h"

wxButton* ButtonFactory::AddButton(wxWindow* parent, int id, int &num)
{
	wxButton* button = new wxButton(parent, id);

	switch (id - 10000)
	{
	case 0:
		button->SetLabel("BIN");
		break;
	case 1:
		button->SetLabel("HEX");
		break;
	case 2:
		button->SetLabel("DEC");
		break;
	case 3:
		button->SetLabel("C");
		break;
	case 4:
		button->SetLabel("%");
		break;
	case 5:
		button->Enable(false);
		break;
	case 6:
		button->Enable(false);
		break;
	case 7:
		button->SetLabel("*");
		break;
	case 11:
		button->SetLabel("/");
		break;
	case 15:
		button->SetLabel("+");
		break;
	case 19:
		button->SetLabel("-");
		break;
	case 20:
		button->SetLabel("+/-");
		break;
	case 22:
		button->Enable(false);
		break;
	case 23:
		button->SetLabel("=");
		break;
	default:
		button->SetLabel(std::to_string(num));
		num--;
		break;
	}
	
	return button;

}

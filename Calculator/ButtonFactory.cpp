#include "ButtonFactory.h"

wxButton* ButtonFactory::AddButton(wxWindow* parent, int id)
{
	return new wxButton(parent, id);
}

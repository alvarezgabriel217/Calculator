#pragma once

#include "wx/wx.h"
#include "Main.h"

class App : public wxApp
{
public:
	App();
	~App();
public:
	virtual bool OnInit();
private:
	Main* mainWindow = nullptr;
};


#pragma once


#include "wx/wx.h"
#include "CalUI.h"
#include "ButtonFactory.h"




class CalApp : public wxApp
{
	virtual bool OnInit();

private:
	ButtonFactory* m_frame1 = nullptr;

public:
	CalApp();
	~CalApp();
};

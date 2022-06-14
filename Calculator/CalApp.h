#pragma once


#include "wx/wx.h"
#include "CalUI.h"




class CalApp : public wxApp
{
	virtual bool OnInit();

private:
	CalUI* m_frame1 = nullptr;

public:
	CalApp();
	~CalApp();
};

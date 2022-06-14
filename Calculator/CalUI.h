#pragma once
#include "wx/wx.h"
//#include "CalApp.h"
#include <string>




class CalUI : public wxFrame
{

public:
	CalUI();
	~CalUI();
	void onButtonClicked(wxCommandEvent &evt);

public:
	wxButton* m_btn = nullptr;
	wxTextCtrl* m_text1 = nullptr;
	int number1 = 0;
	int number2 = 0;


	wxDECLARE_EVENT_TABLE();
};


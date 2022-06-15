#pragma once
#include "wx/wx.h"
#include "CalUI.h"

class ButtonFactory : public wxFrame
{

public:
	ButtonFactory();
	~ButtonFactory();


public:
	wxButton* m_btn = nullptr;
	wxTextCtrl* m_text1 = nullptr;

	wxButton* CreateAddButton();
	wxButton* CreateMinusButton();
	wxButton* CreateMultiplyButton();
	wxButton* CreateDivideButton();
	wxButton* CreateNumbers();
	wxButton* CreateSolvers();
	wxTextCtrl* CreateTextBox();


	wxDECLARE_EVENT_TABLE();
};


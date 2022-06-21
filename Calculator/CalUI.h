#pragma once
#include "wx/wx.h"
//#include "CalApp.h"
#include <string>
#include <cstring>
#include <sstream>
#include "1.conversion_header.h"
#include "1.convert.cpp"



class CalUI : public wxFrame
{

public:
	CalUI();
	~CalUI();
	void onButtonClicked(wxCommandEvent &evt);

public:
	wxButton* m_btn = nullptr;
	wxTextCtrl* m_text1 = nullptr;
	double number = 0;
	double number2 = 0;
	int operation = 0;

	//std::string 
	//wxString first = "";
	//std::string first = "";

	std::vector<float> numbers;
	std::vector<char> addition;
	std::vector<char> multiplication;

	wxDECLARE_EVENT_TABLE();
};


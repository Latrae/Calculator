#include "ButtonFactory.h"


ButtonFactory::ButtonFactory() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(700, 500))
{
	ButtonFactory::CreateAddButton();
	ButtonFactory::CreateMinusButton();
	ButtonFactory::CreateMultiplyButton();
	ButtonFactory::CreateDivideButton();

	/*//Numbers
	m_btn = new wxButton(this, 10000, "0", wxPoint(50, 300), wxSize(70, 30));
	m_btn = new wxButton(this, 10001, "1", wxPoint(50, 250), wxSize(40, 30));
	m_btn = new wxButton(this, 10002, "2", wxPoint(100, 250), wxSize(40, 30));
	m_btn = new wxButton(this, 10003, "3", wxPoint(150, 250), wxSize(40, 30));
	m_btn = new wxButton(this, 10004, "4", wxPoint(50, 200), wxSize(40, 30));
	m_btn = new wxButton(this, 10005, "5", wxPoint(100, 200), wxSize(40, 30));
	m_btn = new wxButton(this, 10006, "6", wxPoint(150, 200), wxSize(40, 30));
	m_btn = new wxButton(this, 10007, "7", wxPoint(50, 150), wxSize(40, 30));
	m_btn = new wxButton(this, 10008, "8", wxPoint(100, 150), wxSize(40, 30));
	m_btn = new wxButton(this, 10009, "9", wxPoint(150, 150), wxSize(40, 30));

	//Clear and enter
	m_btn = new wxButton(this, 10010, "C", wxPoint(7, 100), wxSize(40, 30));
	m_btn = new wxButton(this, 10011, "=", wxPoint(125, 290), wxSize(65, 40));

	//Modifiers
	m_btn = new wxButton(this, 10012, "+", wxPoint(200, 100), wxSize(40, 30));
	m_btn = new wxButton(this, 10013, "-", wxPoint(200, 150), wxSize(40, 30));
	m_btn = new wxButton(this, 10014, "*", wxPoint(200, 200), wxSize(40, 30));
	m_btn = new wxButton(this, 10015, "/", wxPoint(200, 250), wxSize(40, 30));


	//mod and parenthesis
	m_btn = new wxButton(this, 10016, "mod", wxPoint(50, 100), wxSize(40, 30));
	m_btn = new wxButton(this, 10017, "(", wxPoint(100, 100), wxSize(40, 30));
	m_btn = new wxButton(this, 10018, ")", wxPoint(150, 100), wxSize(40, 30));

	// bin, hex and dec
	m_btn = new wxButton(this, 10019, "Bin", wxPoint(250, 100), wxSize(40, 30));
	m_btn = new wxButton(this, 10020, "Hex", wxPoint(250, 150), wxSize(40, 30));
	m_btn = new wxButton(this, 10021, "Dec", wxPoint(250, 200), wxSize(40, 30));

	//negative and .
	m_btn = new wxButton(this, 10022, "Neg", wxPoint(250, 250), wxSize(40, 30));
	m_btn = new wxButton(this, 10023, ".", wxPoint(200, 300), wxSize(40, 30));

	//Blank Button
	m_btn = new wxButton(this, 10024, "", wxPoint(400, 400), wxSize(0, 0));


	//Text box
	m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 65), wxSize(300, 30));

	//m_text1 = new wxTextEntry();//this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));


	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);*/
}

wxButton* ButtonFactory::CreateAddButton()
{
	m_btn = new wxButton(this, 10012, "+", wxPoint(200, 100), wxSize(40, 30));
	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}



wxButton* ButtonFactory::CreateMinusButton()
{
	m_btn = new wxButton(this, 10013, "-", wxPoint(200, 150), wxSize(40, 30));
	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}

wxButton* ButtonFactory::CreateMultiplyButton()
{
	m_btn = new wxButton(this, 10014, "*", wxPoint(200, 200), wxSize(40, 30));
	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}

wxButton* ButtonFactory::CreateDivideButton()
{
	m_btn = new wxButton(this, 10015, "/", wxPoint(200, 250), wxSize(40, 30));
	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}

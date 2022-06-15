#include "ButtonFactory.h"

wxBEGIN_EVENT_TABLE(ButtonFactory, wxFrame)
	EVT_BUTTON(wxID_ANY, CalUI::onButtonClicked)
wxEND_EVENT_TABLE()

ButtonFactory::ButtonFactory() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(700, 500))
{
	ButtonFactory::CreateAddButton();
	ButtonFactory::CreateMinusButton();
	ButtonFactory::CreateMultiplyButton();
	ButtonFactory::CreateDivideButton();
	ButtonFactory::CreateNumbers();
	ButtonFactory::CreateTextBox();
	ButtonFactory::CreateSolvers();

	/*
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

	*/
	//m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);
}

ButtonFactory::~ButtonFactory()
{

}

wxButton* ButtonFactory::CreateAddButton()
{
	m_btn = new wxButton(this, 10012, "+", wxPoint(200, 100), wxSize(40, 30));
	//m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}



wxButton* ButtonFactory::CreateMinusButton()
{
	m_btn = new wxButton(this, 10013, "-", wxPoint(200, 150), wxSize(40, 30));
	//m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}

wxButton* ButtonFactory::CreateMultiplyButton()
{
	m_btn = new wxButton(this, 10014, "*", wxPoint(200, 200), wxSize(40, 30));
	//m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}

wxButton* ButtonFactory::CreateDivideButton()
{
	m_btn = new wxButton(this, 10015, "/", wxPoint(200, 250), wxSize(40, 30));
	//m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);

	return m_btn;
}

wxButton* ButtonFactory::CreateNumbers()
{
	int ID = 10001;
	for (int y = 250; y >= 150; y = y - 50)
	{
		for (int x = 50; x <= 150; x = x + 50)
		{
			m_btn = new wxButton(this, ID++, std::to_string((ID)-10000), wxPoint(x, y), wxSize(40, 30));
		}
	}

	return m_btn;
}

wxButton* ButtonFactory::CreateSolvers()
{
	m_btn = new wxButton(this, 10010, "C", wxPoint(7, 100), wxSize(40, 30));
	m_btn = new wxButton(this, 10011, "=", wxPoint(125, 290), wxSize(65, 40));

	return m_btn;
}

wxTextCtrl* ButtonFactory::CreateTextBox()
{
	m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 65), wxSize(300, 30));

	return m_text1;
}

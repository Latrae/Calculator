#include "CalUI.h"

wxBEGIN_EVENT_TABLE(CalUI, wxFrame)
	EVT_BUTTON(wxID_ANY, onButtonClicked)
wxEND_EVENT_TABLE()

CalUI::CalUI() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(700, 500))
{
	//Numbers
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

	
	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);
}

CalUI::~CalUI()
{
	//delete[]btn;
}

//On button click


void CalUI::onButtonClicked(wxCommandEvent& evt)
{

	//int btn_id = (evt.GetId());

	//number1 = _tstoi(->GetName());
	//m_text1->AppendText(m_btn->GetLabel());
	//AppendText();
	//SetValue();
	
	for (int i = 0; i <= 30; i++)
	{
		if (i == (evt.GetId() - 10000) && i <= 9)
		{
			m_text1->AppendText(std::to_string(i));//(evt.GetString());
			break;
		}
		else if (i >= 12 && i <= 15)
		{
			if (i == evt.GetId() - 10000 && i == 12)
			{
				number1 = _tstoi(m_text1->GetValue());
				//m_text1->AppendText('+');
				m_text1->Clear();
				operation = 1;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 13)
			{
				number1 = _tstoi(m_text1->GetValue());
				//m_text1->AppendText("-");
				m_text1->Clear();
				operation = 2;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 14)
			{
				number1 = _tstoi(m_text1->GetValue());
				//m_text1->AppendText("*");
				m_text1->Clear();
				operation = 3;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 15)
			{
				number1 = _tstoi(m_text1->GetValue());
				//m_text1->AppendText("/");
				m_text1->Clear();
				operation = 4;
				break;
			}
		}
		else if (i >= 16 && i <= 18)
		{
			if (i == 16 && i == evt.GetId() - 10000)
			{
				number1 = _tstoi(m_text1->GetValue());
				//m_text1->AppendText("%");
				m_text1->Clear();
				operation = 5;
				break;
			}
			else if (i == 17 && i == evt.GetId() - 10000)
			{
				m_text1->AppendText("(");
				break;
			}
			else if (i == 18 && i == evt.GetId() - 10000)
			{
				m_text1->AppendText(")");
				break;
			}
		}
		else if (i == 10 || i == 11)
		{
			if (i == 10 && i == evt.GetId() - 10000)
			{
				m_text1->Clear();
				break;
			}
			else if (i == 11 && i == evt.GetId() - 10000)
			{
				number2 = _tstoi(m_text1->GetValue());
				
				m_text1->Clear();

				if(operation == 1)
					number1 = number1 + number2;
				if (operation == 2)
					number1 = number1 - number2;
				if (operation == 3)
					number1 = number1 * number2;
				if (operation == 4)
					number1 = number1 / number2;
				if (operation == 5)
					number1 = (int)number1 % (int)number2;

				m_text1->SetValue(std::to_string(number1));
			}
		}
		else if (i == 23)
		{
			if (i == 23 && i == evt.GetId() - 10000)
			{
				m_text1->AppendText(".");
				break;
			}
		}
	}
	//number1 = m_btn->GetName()

	/*if (m_btn->GetLabel() == "+" || m_btn->GetLabel() == "-" || m_btn->GetLabel() == "*" || m_btn->GetLabel() == "/")
	{
		m_text1->AppendText(m_btn->GetLabel());
		m_text1->AppendText("0");
		//m_text1->SetName
	}

	if (m_btn->GetLabel() == "=")
		number1 = _tstoi(m_text1->GetValue());

	else if (m_btn->GetLabel() == "C")
		m_text1->Clear();
		*/
	evt.Skip();
}
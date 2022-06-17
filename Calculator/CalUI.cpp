#include "CalUI.h"
#include "ButtonFactory.h"

wxBEGIN_EVENT_TABLE(CalUI, wxFrame)
	EVT_BUTTON(wxID_ANY, onButtonClicked)
wxEND_EVENT_TABLE()

CalUI::CalUI() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(700, 500))
{
	
	//Blank Button
	m_btn = new wxButton(this, 10024, "", wxPoint(400, 400), wxSize(0, 0));

	m_btn = ButtonFactory::ButtonFactory().CreateAddButton();
	m_btn = ButtonFactory::ButtonFactory().CreateMinusButton();
	m_btn = ButtonFactory::ButtonFactory().CreateMultiplyButton();
	m_btn = ButtonFactory::ButtonFactory().CreateDivideButton();
	m_btn = ButtonFactory::ButtonFactory().CreateNumbers();
	m_btn = ButtonFactory::ButtonFactory().CreateSolvers();
	m_btn = ButtonFactory::ButtonFactory().CreateMParenthasis();
	m_btn = ButtonFactory::ButtonFactory().CreateNegative();


	m_text1 = ButtonFactory::ButtonFactory().CreateTextBox();


	


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
				first = m_text1->GetValue();
				number1 = wxAtoi(first);
				//m_text1->AppendText('+');
				m_text1->Clear();
				operation = 1;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 13)
			{
				number1 = wxAtoi(m_text1->GetValue());
				//m_text1->AppendText("-");
				m_text1->Clear();
				operation = 2;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 14)
			{
				number1 = wxAtoi(m_text1->GetValue());
				//m_text1->AppendText("*");
				m_text1->Clear();
				operation = 3;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 15)
			{
				number1 = wxAtoi(m_text1->GetValue());
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
				number1 = wxAtoi(m_text1->GetValue());
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
				number1 = 0;
				number2 = 0;
				first = "";
				break;
			}
			else if (i == 11 && i == evt.GetId() - 10000)
			{
				first = m_text1->GetValue();
				number2 = wxAtoi(first);
				

				if(operation == 1)
					number1 = float(number1) + float(number2);
				if (operation == 2)
					number1 = number1 - number2;
				if (operation == 3)
					number1 = number1 * number2;
				if (operation == 4)
					number1 = number1 / number2;
				if (operation == 5)
					number1 = (int)number1 % (int)number2;
				
				m_text1->Clear();

				m_text1->SetValue(std::to_string(number1));

				number1 = 0;
				number2 = 0;
				first = "";
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
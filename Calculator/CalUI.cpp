#include "CalUI.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"
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

	//m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 65), wxSize(300, 30));
	
	m_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CalUI::onButtonClicked, this);
}

CalUI::~CalUI()
{
	//delete[]m_btn;
	//delete m_text1;
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
				//first = m_text1->GetValue();
				m_text1->GetValue().ToDouble(&number);
				number = (float)number;
				//number2 = (float)number2;
				m_text1->Clear();
				m_text1->AppendText('+');
				m_text1->Clear();
				operation = 1;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 13)
			{
				//number1 = wxAtoi(m_text1->GetValue());
				m_text1->GetValue().ToDouble(&number);
				number = (float)number;
				//number2 = (float)number2;
				m_text1->Clear();
				m_text1->AppendText("-");
				m_text1->Clear();
				operation = 2;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 14)
			{
				//number1 = wxAtoi(m_text1->GetValue());
				m_text1->GetValue().ToDouble(&number);
				number = (float)number;
				//number2 = (float)number2;
				m_text1->Clear();
				m_text1->AppendText("*");
				m_text1->Clear();
				operation = 3;
				break;
			}
			else if (i == evt.GetId() - 10000 && i == 15)
			{
				//number1 = wxAtoi(m_text1->GetValue());
				m_text1->GetValue().ToDouble(&number);
				number = (float)number;
				//number2 = (float)number2;
				m_text1->Clear();
				m_text1->AppendText("/");
				m_text1->Clear();
				operation = 4;
				break;
			}
		}
		else if (i >= 16 && i <= 18)
		{
			if (i == 16 && i == evt.GetId() - 10000)
			{
				//number1 = wxAtoi(m_text1->GetValue());
				m_text1->GetValue().ToDouble(&number);

				m_text1->Clear();
				m_text1->AppendText("%");
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
				number = 0;
				number2 = 0;
				//first = "";
				break;
			}
			else if (i == 11 && i == evt.GetId() - 10000)
			{
				//first.append(m_text1->GetValue());
				//std::string second = "890887";
				//first.c_str();



				m_text1->GetValue().ToDouble(&number2);
				//m_text1->GetValue().c_str();


				//number = second;
				//second = number;
				//number2 = wxAtoi(first);
				//first = number;
				//for (int i = first.First(m_text1->GetValue()); i >= first.length() - 1; ++i)
				{
					/*if ((first[i] > 47 && first[i] < 58) || first[i] == 46)
					{
						if (tmpc >= MAX_NUMBER_LENGTH)
							return std::nanf("");
						tmp[tmpc++] = eq[i];
					}*/
					/*if (first[i] == '0' || first[i] == '1' || first[i] == '2' || first[i] == '3'
						|| first[i] == '4' || first[i] == '5' || first[i] == '6' || first[i] == '7'
						|| first[i] == '8' || first[i] == '9')
					{ }
						//number = (int)first;
					else if(first[i] == '1')
					{ }*/

				}

				CalcProcessor* CalcProcessor = CalcProcessor::GetInstance();

				if (operation == 1)
					number = CalcProcessor->GetAddition(number, number2);
				if (operation == 2)
					number = CalcProcessor->GetSubtraction(number, number2);
				if (operation == 3)
					number = CalcProcessor->GetMultiplication(number, number2);
				if (operation == 4)
					number = CalcProcessor->GetDivision(number, number2);
				if (operation == 5)
					number = CalcProcessor->GetModulo((int)number, (int)number2);
					

				/*if (operation == 1)
					number = (int)number + (int)number2;
				if (operation == 2)
					number = (int)number - (int)number2;
				if (operation == 3)
					number = (int)number * (int)number2;
				if (operation == 4)
					number = (int)number / (int)number2;
				if (operation == 5)
					number = (int)number % (int)number2;
					*/

				m_text1->Clear();

				m_text1->SetValue(std::to_string(number));
				//number = 0;
				//number1 = 0;
				//number2 = 0;
				//first = "";
			}
		}
		else if (i == 19)
		{
			if (i == 19 && i == evt.GetId() - 10000)
			{
				std::string results = "";
				//number = wxAtoi(m_text1->GetValue());
				int BinNumber = wxAtoi(m_text1->GetValue());
				for (int i = 0; i < 32; i++)
				{
					if (BinNumber % 2 == 0)
					{
						results = "0" + results;
					}
					else
					{
						results = "1" + results;
					}
					BinNumber = BinNumber / 2;
				}
				m_text1->Clear();
				m_text1->AppendText(results);//std::to_string(BinNumber));
			}
		}
		else if (i == 20)
		{
			if (i == 20 && i == evt.GetId() - 10000)
			{
				int Hex = wxAtoi(m_text1->GetValue());
				
				std::string HexNumber = "";
				while (Hex > 0)
				{
					int HexMod = Hex % 16;
					if (HexMod < 10)
						HexNumber = std::to_string(HexMod) + HexNumber;
					else if (HexMod == 10) { HexNumber = "A" + HexNumber; }
					else if (HexMod == 11) { HexNumber = "B" + HexNumber; }
					else if (HexMod == 12) { HexNumber = "C" + HexNumber; }
					else if (HexMod == 13) { HexNumber = "D" + HexNumber; }
					else if (HexMod == 14) { HexNumber = "E" + HexNumber; }
					else if (HexMod == 15) { HexNumber = "F" + HexNumber; }

					Hex = Hex / 16;
				}
				HexNumber = "0x" + HexNumber;

				//int Hex = stoi(HexNumber, nullptr, 16);
				//int Hex = wxAtoi(m_text1->GetValue());
				//strtol();
				//strtoul();
				m_text1->Clear();
				m_text1->AppendText(HexNumber);
			}
		}
		else if (i == 21)
		{
			if (i == 21 && i == evt.GetId() - 10000)
			{
				std::string BaseNumber = "";
				int Base = wxAtoi(m_text1->GetValue());

				m_text1->Clear();
				m_text1->AppendText(std::to_string(Base));
			}
		}
		else if (i == 22)
		{
			if (i == 22 && i == evt.GetId() - 10000)
			{
				float NegNumber = wxAtof(m_text1->GetValue());

				NegNumber = NegNumber - (NegNumber * 2);
				m_text1->Clear();

				m_text1->AppendText(std::to_string(NegNumber));
			}
		}
		else if (i == 23)
		{
			if (i == 23 && i == evt.GetId() - 10000)
			{
				if (!m_text1->GetValue().Contains("."))
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

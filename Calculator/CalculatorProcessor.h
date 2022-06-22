#pragma once
//#include <string>
//#include "ButtonFactory.h"
//#include "CalUI.h"


class CalcProcessor// : public CalUI
{
private:
	CalcProcessor() {}
	static CalcProcessor* _CalcProcessor;



public:
	static CalcProcessor* GetInstance();
	
	CalcProcessor(CalcProcessor& other) = delete;
	void operator=(const CalcProcessor& other) = delete;



	double GetAddition(double number, double number2);
	double GetMultiplication(double number, double number2);
	double GetDivision(double number, double number2);
	double GetSubtraction(double number, double number2);
	int GetModulo(int number, int number2);

	

};
	CalcProcessor* CalcProcessor::_CalcProcessor = nullptr;


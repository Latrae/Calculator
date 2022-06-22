#include "CalculatorProcessor.h"

CalcProcessor* CalcProcessor::GetInstance()
{
	if (_CalcProcessor == nullptr)
	{
		_CalcProcessor = new CalcProcessor();
	}

	return _CalcProcessor;
}
double CalcProcessor::GetAddition(double number, double number2)
{
	number = number + number2;
	return number;
}
double CalcProcessor::GetMultiplication(double number, double number2)
{
	number = number * number2;
	return number;
}
double CalcProcessor::GetDivision(double number, double number2)
{
	number = number / number2;
	return number;
}
double CalcProcessor::GetSubtraction(double number, double number2)
{
	number = number - number2;
	return number;
}
int CalcProcessor::GetModulo(int number, int number2)
{
	number = number % number2;
	return (int)number;
}
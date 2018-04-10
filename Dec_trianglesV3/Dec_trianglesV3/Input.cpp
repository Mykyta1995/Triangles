#include "stdafx.h"
#include "Input.h"

//method for input value for type double 
double input::Input::get_double()
{
	while (true) {
		double d = (double)Numbers::min_value;
		if (std::wcin >> d)
			return d;
		std::wcout << L"Ошибка типа,пожалуйста попробуйте еще раз:";
		skip_to_double();
	}
}

//method for skip input stream
void input::Input::skip_to_double()
{
	if (std::wcin.fail()) {
		std::wcin.clear();
		for (wchar_t ch; std::wcin >> ch;) {
			if (iswdigit(ch) || ch == '-')
				std::wcin.unget();
			return;
		}
	}
	else
		Errors::Error::error("Error input");
}

//method for input value for type double in range
double input::Input::get_double_range(int min_value, int max_value)
//min_value this start range and max_value this end range
{
	while (true) {
		double d = get_double();
		if (d > min_value && d <= max_value)
			return d;
		std::wcout << L"Число " << d << L" выходит за пределы интервала от " << min_value << L" до " << max_value << ":";
	}
}


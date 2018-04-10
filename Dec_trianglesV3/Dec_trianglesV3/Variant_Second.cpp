#include "stdafx.h"
#include "Variant_second.h"

//constructor default
Variant_Second::Variant_Second()
{
	std::wcout << L"Введите отрезок BH:";
	this->input_first = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);
	std::wcout << L"Введите угол B:";
	this->input_second = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);
}

//method for search angle B
void Variant_Second::task_first()
{
	if (this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_firts = (double)Numbers::right_angle - this->input_second;
	this->dec_firts = std::round(this->dec_firts);
}

//method for search HC
void Variant_Second::task_second()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_second = this->input_first*tan((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_second = std::round(this->dec_second * 10) / 10;
}

//method for search BC
void Variant_Second::task_third()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_third = this->input_first / cos((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_third = std::round(this->dec_third * 10) / 10;
}

//method for search HD
void Variant_Second::task_fore()
{
	if (this->dec_second == (double)Numbers::not_decition ||
		this->input_first == (double)Numbers::not_decition ||
		this->dec_third == (double)Numbers::not_decition)
		return;
	this->dec_fore = (this->input_first*this->dec_second) / this->dec_third;
	this->dec_fore = std::round(this->dec_fore * 10) / 10;
}

//method for search BD
void Variant_Second::task_five()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->dec_third == (double)Numbers::not_decition)
		return;
	this->dec_five = pow(this->input_first, 2) / this->dec_third;
	this->dec_five = std::round(this->dec_five * 10) / 10;
}

//method for search DC
void Variant_Second::task_six()
{
	if (this->dec_third == (double)Numbers::not_decition ||
		this->dec_five == (double)Numbers::not_decition)
		return;
	this->dec_six = this->dec_third - this->dec_five;
	this->dec_six = std::round(this->dec_six * 10) / 10;
}

//method for show answer
std::wstring Variant_Second::Answer() const
{
	return std::wstring(L"Угол С= " + change_type::Change_type::to_wstring(this->dec_firts) + L" °\n"
		+ L"Отрезок HC= " + change_type::Change_type::to_wstring(this->dec_second) + L" см\n"
		+ L"Отрезок BC= " + change_type::Change_type::to_wstring(this->dec_third) + L" см\n"
		+ L"Отрезок HD= " + change_type::Change_type::to_wstring(this->dec_fore) + L" см\n"
		+ L"Отрезок BD= " + change_type::Change_type::to_wstring(this->dec_five) + L" см\n"
		+ L"Отрезок BC= " + change_type::Change_type::to_wstring(this->dec_six) + L" см\n");
}

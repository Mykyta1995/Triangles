#include "stdafx.h"
#include "Variant_Fore.h"

//constructor default
Variant_Fore::Variant_Fore()
{
	std::wcout << L"Введите отрезок ND:";
	this->input_first = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);
	std::wcout << L"Введите угол N:";
	this->input_second = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);

}

//method for decide task first(search angle D)
void Variant_Fore::task_first()
{
	if (this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_firts = (double)Numbers::right_angle - this->input_second;
	this->dec_firts = std::round(this->dec_firts);
}

//method for decide task second(search NR)
void Variant_Fore::task_second()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_second = this->input_first*cos((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_second = std::round(this->dec_second * 10) / 10;
}

//method for decide task third(search DR)
void Variant_Fore::task_third()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_third = this->input_first*sin((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_third = std::round(this->dec_third * 10) / 10;
}

//method for decide task fore(search RA)
void Variant_Fore::task_fore()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->dec_third == (double)Numbers::not_decition ||
		this->dec_second == (double)Numbers::not_decition)
		return;
	this->dec_fore = (this->dec_third*this->dec_second) / this->input_first;
	this->dec_fore = std::round(this->dec_fore * 10) / 10;
}

//method for decide task five(search RA)
void Variant_Fore::task_five()
{
	if (this->dec_second == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_five = this->dec_second*cos((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_five = std::round(this->dec_five * 10) / 10;
}

//method for decide task six(search AD)
void Variant_Fore::task_six()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->dec_five == (double)Numbers::not_decition)
		return;
	this->dec_six = this->input_first - this->dec_five;
	this->dec_six = std::round(this->dec_six * 10) / 10;
}

//method for show answers
std::wstring Variant_Fore::Answer() const
{
	return std::wstring(L"Угол D= " + change_type::Change_type::to_wstring(this->dec_firts) + L" °\n"
		+ L"Отрезок NRF= " + change_type::Change_type::to_wstring(this->dec_second) + L" см\n"
		+ L"Отрезок DR= " + change_type::Change_type::to_wstring(this->dec_third) + L" см\n"
		+ L"Отрезок RA= " + change_type::Change_type::to_wstring(this->dec_fore) + L" см\n"
		+ L"Отрезок AN= " + change_type::Change_type::to_wstring(this->dec_five) + L" см\n"
		+ L"Отрезок AD= " + change_type::Change_type::to_wstring(this->dec_six) + L" см\n");
}



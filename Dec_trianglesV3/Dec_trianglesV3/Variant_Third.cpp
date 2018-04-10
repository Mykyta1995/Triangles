#include "stdafx.h"
#include "Variant_Third.h"

//constructor
Variant_Third::Variant_Third()
{
	std::wcout << L"Введите отрезок OF:";
	this->input_first = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);
	std::wcout << L"Введите угол C:";
	this->input_second = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);
}

//method for decide task first(search OC)
void Variant_Third::task_first()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_firts = this->input_first*(cos((this->input_second*PI) / (double)Numbers::max_angle) / sin((this->input_second*PI) / (double)Numbers::max_angle));
	this->dec_firts = std::round(this->dec_firts * 10) / 10;
}

//method for decide task second(search CF)
void Variant_Third::task_second()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	double s = sin((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_second = this->input_first / sin((this->input_second*PI) / (double)Numbers::max_angle);
	this->dec_second = std::round(this->dec_second * 10) / 10;
}

//method for decide task third(search OH)
void Variant_Third::task_third()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->dec_firts == (double)Numbers::not_decition ||
		this->dec_second == (double)Numbers::not_decition)
		return;
	this->dec_third = (this->dec_firts*this->input_first) / this->input_second;
	this->dec_third = std::round(this->dec_third * 10) / 10;
}

//method for decide task fore(search FH)
void Variant_Third::task_fore()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->dec_second == (double)Numbers::not_decition)
		return;
	this->dec_fore = pow(this->input_first, 2) / this->dec_second;
	this->dec_fore = std::round(this->dec_fore * 10) / 10;
}

//method for decide task five(search CH)
void Variant_Third::task_five()
{
	if (this->dec_second == (double)Numbers::not_decition ||
		this->dec_fore == (double)Numbers::not_decition)
		return;
	this->dec_five = this->dec_second - this->dec_fore;
	this->dec_five = std::round(this->dec_five * 10) / 10;
}

//method for decide task five(angle F)
void Variant_Third::task_six()
{
	if (this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_six = (double)Numbers::right_angle - this->input_second;
	this->dec_six = std::round(dec_six);
}

//method for show results
std::wstring Variant_Third::Answer() const
{
	return std::wstring(L"Отрезок ОС= " + change_type::Change_type::to_wstring(this->dec_firts) + L" см\n"
		+ L"Отрезок СF= " + change_type::Change_type::to_wstring(this->dec_second) + L" см\n"
		+ L"Отрезок OH= " + change_type::Change_type::to_wstring(this->dec_third) + L" см\n"
		+ L"Отрезок FH= " + change_type::Change_type::to_wstring(this->dec_fore) + L" см\n"
		+ L"Отрезок CF= " + change_type::Change_type::to_wstring(this->dec_five) + L" см\n"
		+ L"Угол F= " + change_type::Change_type::to_wstring(this->dec_six) + L" °\n");
}


#include "stdafx.h"
#include "Variant_First.h"

//constructor default
Variant_First::Variant_First()
{
	std::wcout << L"Введите отрезок KD:";
	this->input_first = input::Input::get_double_range((int)Numbers::min_value, (int)Numbers::max_value);
	std::wcout << L"Введите отрезок PD:";
	this->input_second = input::Input::get_double_range((int)Numbers::min_value, this->input_first);
}

//method for decide task firts (search MD)
void Variant_First::task_first()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	if (this->input_first == this->input_second)
		Errors::Error::error("Mistaken condition");
	this->dec_firts = std::pow(this->input_first, 2) / this->input_second;
	this->dec_firts = std::round(this->dec_firts * 10) / 10;
}

//method for decide task second(search MP)
void Variant_First::task_second()
{
	if (this->dec_firts == (double)Numbers::not_decition ||
		this->input_second == (double)Numbers::not_decition)
		return;
	this->dec_second = this->dec_firts - this->input_second;
	this->dec_second = std::round(this->dec_second * 10) / 10;
}

//method for decide task third(search MK)
void Variant_First::task_third()
{
	if (this->dec_firts == (double)Numbers::not_decition ||
		this->dec_second == (double)Numbers::not_decition)
		return;
	this->dec_third = std::sqrt(this->dec_firts*this->dec_second);
	this->dec_third = std::round(this->dec_third * 10) / 10;
}

//method for decide task fore(search KP)
void Variant_First::task_fore()
{
	if (this->dec_third == (double)Numbers::not_decition ||
		this->input_first == (double)Numbers::not_decition ||
		this->dec_firts == (double)Numbers::not_decition)
		return;
	this->dec_fore = this->dec_third*this->input_first / this->dec_firts;
	this->dec_fore = std::round(this->dec_fore * 10) / 10;
}

//method for decide task fore(search angle D)
void Variant_First::task_five()
{
	if (this->input_first == (double)Numbers::not_decition ||
		this->dec_firts == (double)Numbers::not_decition)
		return;
	this->dec_five = std::acos((this->input_first / this->dec_firts)*PI / (int)Numbers::max_angle);
	this->dec_five = std::round(this->dec_five);
}

//method for decide task fore(search angle M)
void Variant_First::task_six()
{
	if (this->dec_five == (double)Numbers::not_decition)
		return;
	this->dec_six = (double)Numbers::right_angle - this->dec_five;
	this->dec_six = std::round(this->dec_six);
}

//method for return answer
std::wstring Variant_First::Answer() const
{
	return std::wstring(L"Отрезок MD= " + change_type::Change_type::to_wstring(this->dec_firts) + L" см\n"
		+ L"Отрезок MP= " + change_type::Change_type::to_wstring(this->dec_second) + L" см\n"
		+ L"Отрезок MK= " + change_type::Change_type::to_wstring(this->dec_third) + L" см\n"
		+ L"Отрезок KP= " + change_type::Change_type::to_wstring(this->dec_fore) + L" см\n"
		+ L"Угол D= " + change_type::Change_type::to_wstring(this->dec_five) + L"°\n"
		+ L"Угол M= " + change_type::Change_type::to_wstring(this->dec_six) + L"°\n");
}


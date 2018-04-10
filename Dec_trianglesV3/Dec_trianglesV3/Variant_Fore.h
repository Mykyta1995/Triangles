#pragma once
#include "Header.h"
using namespace Logic;

class Variant_Fore :public Base
{
public:
	//constructor default
	Variant_Fore();

	//decide task firts
	void task_first() override;

	//decide task second
	void task_second() override;

	//decide task third
	void task_third() override;

	//decide task fore
	void task_fore() override;

	//decide task five
	void task_five() override;

	//decide task six
	void task_six() override;

	//method for return answer
	std::wstring Answer() const override;

	//destructor
	~Variant_Fore() {};
};


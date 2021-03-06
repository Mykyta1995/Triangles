// Dec_trianglesV3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

void Decide(std::shared_ptr<Base>& obj)
{
	try {
		std::wcout << L"________________________________________________________\n";
		obj->task_first();
		obj->task_second();
		obj->task_third();
		obj->task_fore();
		obj->task_five();
		obj->task_six();
		std::wcout << obj->Answer();
		std::wcout << L"________________________________________________________\n";
	}
	catch (std::runtime_error & er) {
		std::cerr << er.what() << "\n";
	}
}

int Choose_user()
{
	int num = (int)Numbers::min_value;
	std::wcout << L"1) Треугольник MKD\n";
	std::wcout << L"2) Треугольник BHC\n";
	std::wcout << L"3) Треугольник COF\n";
	std::wcout << L"4) Треугольник DNR\n";
	std::wcout << L"Для выхода введите любое другое число\n";
	std::wcout << L"Ваг выбор:";
	num = input::Input::get_double();
	return num;
}

int main()
{
	typedef std::shared_ptr<Base> smart_base;
	_wsetlocale(LC_ALL, L".866");
	while (true) {
		int num = Choose_user();
		if (num == 1) {
			smart_base obj = std::make_shared<Variant_First>();
			Decide(obj);
		}
		else if (num == 2)
		{
			smart_base obj = std::make_shared<Variant_Second>();
			Decide(obj);
		}
		else if (num == 3) {
			smart_base obj = std::make_shared<Variant_Third>();
			Decide(obj);
		}
		else if (num == 4) {
			smart_base obj = std::make_shared<Variant_Fore>();
			Decide(obj);
		}
		else
			break;
	}
	return 0;
}


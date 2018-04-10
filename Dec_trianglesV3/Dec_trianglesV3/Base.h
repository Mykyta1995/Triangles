#pragma once
#include "Header.h"

namespace Logic
{
	//base class for 4 variants
	class Base
	{
	protected:
		double input_first = (double)Numbers::not_decition;
		double input_second = (double)Numbers::not_decition;
		double dec_firts = (double)Numbers::not_decition;
		double dec_second = (double)Numbers::not_decition;
		double dec_third = (double)Numbers::not_decition;
		double dec_fore = (double)Numbers::not_decition;
		double dec_five = (double)Numbers::not_decition;
		double dec_six = (double)Numbers::not_decition;
	public:
		//constructor
		Base() {};

		//destructor
		virtual ~Base() {};

		//method for decition task first 
		virtual void task_first() = 0;

		//method for decition task second 
		virtual void task_second() = 0;

		//method for decition task third 
		virtual void task_third() = 0;

		//method for decition task fore 
		virtual void task_fore() = 0;

		//method for decition task five 
		virtual void task_five() = 0;

		//method for decition task six 
		virtual void task_six() = 0;

		virtual std::wstring Answer()const = 0;

	};
}


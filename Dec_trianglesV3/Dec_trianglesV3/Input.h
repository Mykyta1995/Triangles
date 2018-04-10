#pragma once
#include "Header.h"
namespace input {
	class Input
	{
		//constructor
		Input() = default;

		//destructor
		~Input() = default;
	public:
		//method for input value for type double 
		static double get_double();

		//method for skip input stream
		static void skip_to_double();

		//method for input value for type double in range
		static double get_double_range(int min_value, int max_value);
	};
}


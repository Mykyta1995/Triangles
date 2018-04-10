#pragma once
#include "Header.h"
namespace Errors {
	static class Error
	{
		//constructor
		Error() = default;

		//destrucrtor
		~Error() = default;
	public:

		//methdof for run exception runtime_error
		static void error(std::string message)
			//message errors
		{
			throw std::runtime_error(message);
		}
	};
}


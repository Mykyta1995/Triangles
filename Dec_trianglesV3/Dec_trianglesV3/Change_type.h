#pragma once
#include "Header.h"
namespace change_type
{
	static class Change_type
	{
		//constructor
		Change_type() = default;

		//destructor
		~Change_type() = default;
	public:
		//method for change int to wstring
		static std::wstring to_wstring(const double value)
		{
			std::wstringstream wss;
			wss << value;
			std::wstring ws;
			wss >> ws;
			return ws;
		}
	};
}



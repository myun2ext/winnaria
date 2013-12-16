#ifndef __github_com_myun2__winoria__core__atom_HPP__
#define __github_com_myun2__winoria__core__atom_HPP__

#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			class atom
			{
			public:
				typedef ATOM ImplType, atom_type;
			private:
				atom_type value;
			public:
				atom(){}
				atom(const ImplType& in_value) : value(in_value) {}

				operator atom_type() const { return value; }
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__atom_HPP__
//http://msdn.microsoft.com/en-us/library/windows/desktop/ms649053(v=vs.85).aspx
//http://msdn.microsoft.com/ja-jp/library/cc429245.aspx
#ifndef __github_com_myun2__winoria__core__atom_HPP__
#define __github_com_myun2__winoria__core__atom_HPP__

#include "myun2/winoria/exception.hpp"
#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			DECL_WINORIA_EXCEPTION( failed_add_atom );

			class atom
			{
			public:
				typedef ATOM ImplType, impl_type, atom_type;
			private:
				atom_type value;
			public:
				atom(){}
				atom(LPCTSTR name){ allocate(name); }
				atom(const ImplType& in_value) : value(in_value) {}

				operator atom_type() const { return value; }

				static ATOM allocate(LPCTSTR name) {
					ATOM ret = ::AddAtom(name);
					if ( ret == 0 )
						throw failed_add_atom();
					return ret;
				}
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__atom_HPP__
//http://msdn.microsoft.com/en-us/library/windows/desktop/ms649053(v=vs.85).aspx
//http://msdn.microsoft.com/ja-jp/library/cc429245.aspx
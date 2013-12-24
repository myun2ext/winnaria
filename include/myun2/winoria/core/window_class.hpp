#ifndef __github_com_myun2__winoria__core__window_class_HPP__
#define __github_com_myun2__winoria__core__window_class_HPP__

#include "myun2/winoria/exception.hpp"
#include <string>
#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			class window_class
			{
			private:
				typedef WNDCLASSEX ImplType, impl_type, core_type;
				core_type wndcls;
				::std::string window_class_name;

				void reset_class() {
					ZeroMemory(&wndcls, sizeof(wndcls));
					wndcls.cbSize = sizeof(core_type);
				}
			public:
				//window_class() { reset_class(); }
				window_class(const char* name) : window_class_name(name) {
					reset_class();
					wndcls.lpszClassName = window_class_name.c_str();
				}
				const char* get_class_name() const { return window_class_name.c_str(); }

				operator WNDCLASSEX& () { return wndcls; }
				operator const WNDCLASSEX& () const { return wndcls; }
				operator WNDCLASSEX* () { return &wndcls; }
				operator const WNDCLASSEX* () const { return &wndcls; }
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__window_class_HPP__

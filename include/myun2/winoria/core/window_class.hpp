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
			DECL_WINORIA_EXCEPTION( register_window_class_failed );
			DECL_WINORIA_EXCEPTION( release_window_class_failed );

			////

			class window_class
			{
			private:
				typedef WNDCLASSEX core_type;
				typedef ATOM atom_type;

				core_type wndcls;
				atom_type atom;
				::std::string window_class_name;

				void reset_class() {
					ZeroMemory(&wndcls, sizeof(wndcls));
					wndcls.cbSize = sizeof(core_type);
				}
			public:
				window_class() { reset_class(); }
				window_class(const char* name) : window_class_name(name) {
					reset_class();
					wndcls.lpszClassName = window_class_name.c_str();
				}

				void regist() const {
					atom = ::RegisterClassEx(&wndcls)
					if ( atom == 0 )
						throw register_window_class_failed();
				}
				void release(HINSTANCE hAppInstance = NULL) const {
					if ( ::UnregisterClass(get_class_name(), hAppInstance) == 0 )
						throw release_window_class_failed();
				}

				core_type& get_wndclass() { return wndcls; }
				const core_type& get_wndclass() const { return wndcls; }

				const char* get_class_name() const { return window_class_name.c_str(); }
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__window_class_HPP__

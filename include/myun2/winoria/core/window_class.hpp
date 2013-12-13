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

			class window_class
			{
			public:
				::WNDCLASS wndcls;
			private:
				::std::string window_class_name;
				void zeroreset() { ZeroMemory(&wndcls, sizeof(wndcls)); }
			public:
				window_class(){ zeroreset(); }
				window_class(const char* name) : window_class_name(name) {
					zeroreset();
					wndcls.lpszClassName = window_class_name.c_str();
				}

				void regist() const {
					if ( ::RegisterClass(&wndcls) == 0 )
						throw register_window_class_failed();
				}
				void release(HINSTANCE hAppInstance = NULL) const {
					if ( ::UnregisterClass(wndcls.lpszClassName, hAppInstance) == 0 )
						throw release_window_class_failed();
				}

				::WNDCLASS& get_wndclass() { return wndcls; }
				const ::WNDCLASS& get_wndclass() const { return wndcls; }

				const char* get_class_name() const { return wndcls.lpszClassName; }
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__window_class_HPP__

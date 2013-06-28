#ifndef __github_com_myun2__winoria__core__window_class_HPP__
#define __github_com_myun2__winoria__core__window_class_HPP__

#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			class register_window_class_failed {};
			class release_window_class_failed {};

			class window_class
			{
			protected:
				WNDCLASS wndcls;
			public:
				void reset() { ZeroMemory(&wndcls, sizeof(wndcls)); }

				window_class(){ reset(); }
				window_class(const char* name){
					reset();
					wndcls.lpszClassName = name;
				}

				void regist() const {
					if ( ::RegisterClass(&wndcls) == 0 )
						throw register_window_class_failed();
				}
				void release(HINSTANCE hAppInstance = NULL) const {
					if ( ::UnregisterClass(wndcls.lpszClassName, hAppInstance) == 0 )
						throw release_window_class_failed();
				}
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__window_class_HPP__

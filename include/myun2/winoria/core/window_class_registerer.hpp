#ifndef __github_com_myun2__winoria__core__window_class_registerer_HPP__
#define __github_com_myun2__winoria__core__window_class_registerer_HPP__

#include "myun2/winoria/exception.hpp"
#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			DECL_WINORIA_EXCEPTION( failed_register_window_class );
			DECL_WINORIA_EXCEPTION( failed_unregister_window_class );

			////

			class window_class_registerer
			{
			private:
				typedef ::WNDCLASSEX wndcls_type;
				typedef ATOM atom;

				wndcls_type wndcls;
				atom_type atom;
			public:
				window_class_registerer(const window_class& wc) { register(wc); }

				static atom_type register(const window_class& wc) {
					atom = ::RegisterClassEx((::WNDCLASSEX*)wndcls)
					if ( atom == 0 )
						throw failed_register_window_class();
					return atom;
				}

				static void unregister(LPCTSTR class_name, HINSTANCE hAppInstance = NULL){
					if ( ::UnregisterClass(class_name, hAppInstance) == 0 )
						throw failed_unregister_window_class();
				}
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__window_class_registerer_HPP__

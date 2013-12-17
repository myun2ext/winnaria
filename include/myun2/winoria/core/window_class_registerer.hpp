#ifndef __github_com_myun2__winoria__core__window_class_registerer_HPP__
#define __github_com_myun2__winoria__core__window_class_registerer_HPP__

#include "myun2/winoria/core/atom.hpp"
#include "myun2/winoria/core/window_class.hpp"
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
				//typedef atom::impl_type atom_type;
				window_class wc;
				atom wc_atom;
			public:
				window_class_registerer(const window_class& _wc) : wc(_wc){ wc_atom = register_class(wc); }
				virtual ~window_class_registerer(){ unregister(wc.get_class_name()); }

				static ::ATOM register_class(const window_class& wc)
				{
					::ATOM atom = ::RegisterClassEx((::WNDCLASSEX*)wndcls)
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

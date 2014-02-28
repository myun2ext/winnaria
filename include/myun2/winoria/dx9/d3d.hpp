#ifndef __github_com_myun2__winoria__dx9__d3d_HPP__
#define __github_com_myun2__winoria__dx9__d3d_HPP__

#include "myun2/winoria/exception.hpp"
#include <D3D9.h>

namespace myun2
{
	namespace winoria
	{
		namespace dx9
		{
			class d3d
			{
			public:
				typedef ::IDirect3D9* _If;

				static D3d create() {
					return ::Direct3DCreate9(D3D_SDK_VERSION);
				}
			};
		}
	}
}

#endif//__github_com_myun2__winoria__dx9__d3d_HPP__

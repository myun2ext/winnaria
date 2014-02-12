#ifndef __github_com_myun2__winoria__dxgi__swap_chain_desc_HPP__
#define __github_com_myun2__winoria__dxgi__swap_chain_desc_HPP__

#include "myun2/winoria/dxgi/mode_desc.hpp"
#include "myun2/winoria/dxgi/sample_desc.hpp"

namespace myun2
{
	namespace winoria
	{
		namespace dxgi
		{
			struct swap_chain_desc
			{
				DXGI_SWAP_CHAIN_DESC dxgi_value;

				mode_desc buffer_desc;
				sample_desc sample;
				DXGI_USAGE BufferUsage;
				UINT BufferCount;
				HWND OutputWindow;
				BOOL Windowed;
				DXGI_SWAP_EFFECT SwapEffect;
				UINT Flags;
				mode_desc mode;
			};
		}
	}
}

#endif//__github_com_myun2__winoria__dxgi__swap_chain_desc_HPP__

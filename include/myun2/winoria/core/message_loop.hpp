#ifndef __github_com_myun2__winoria__core__message_loop_HPP__
#define __github_com_myun2__winoria__core__message_loop_HPP__

#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			void message_loop
			{
				MSG msg;
				while ( GetMessage(&msg, NULL, 0, 0) )
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		}
	}
}

#endif//__github_com_myun2__winoria__core__message_loop_HPP__

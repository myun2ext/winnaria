#ifndef __github_com_myun2__winoria__main_HPP__
#define __github_com_myun2__winoria__main_HPP__

#include <windows.h>
#include "myun2/winoria/win_main_holder.hpp"

//	require win_main class.

class win_main;

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow
)
{
	myun2::winoria::win_main_holder<win_main> wm
		(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	return wm.run();
}

#endif//__github_com_myun2__winoria__main_HPP__

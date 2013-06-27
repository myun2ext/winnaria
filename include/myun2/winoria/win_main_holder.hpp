#ifndef __github_com_myun2__winnaria__win_main_holder_HPP__
#define __github_com_myun2__winnaria__win_main_holder_HPP__

#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		class application_instance
		{
		public:
			HINSTANCE hInstance, 
			HINSTANCE hPrevInstance, 
			LPSTR lpCmdLine, 
			int nCmdShow

			application_instance(
				HINSTANCE _hInstance, 
				HINSTANCE _hPrevInstance, 
				LPSTR _lpCmdLine, 
				int _nCmdShow
			) :
				hInstance(_hInstance),
				hPrevInstance(_hPrevInstance),
				lpCmdLine(_lpCmdLine),
				nCmdShow(_nCmdShow)
			{}
		};

		///////////////////////

		template <typename _Base>
		class win_main_holder : public _Base
		{
		private:
			application_instance app_instance;
		public:
			win_main_holder(
				HINSTANCE hInstance, 
				HINSTANCE hPrevInstance, 
				LPSTR lpCmdLine, 
				int nCmdShow
			) : app_instance(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
			{}
		};
	}
}

#endif//__github_com_myun2__winnaria__win_main_holder_HPP__

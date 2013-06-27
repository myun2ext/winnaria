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
			HINSTANCE m_hInstance;
			HINSTANCE m_hPrevInstance;
			LPSTR m_lpCmdLine;
			int m_nCmdShow;

			application_instance(
				HINSTANCE _hInstance, 
				HINSTANCE _hPrevInstance, 
				LPSTR _lpCmdLine, 
				int _nCmdShow
			) :
				m_hInstance(_hInstance),
				m_hPrevInstance(_hPrevInstance),
				m_lpCmdLine(_lpCmdLine),
				m_nCmdShow(_nCmdShow)
			{}
		};

		///////////////////////

		template <typename _WinMainImpl>
		class win_main_holder : public application_instance, public _WinMainImpl
		{
		private:
			//application_instance app_instance;
		public:
			win_main_holder(
				HINSTANCE hInstance,
				HINSTANCE hPrevInstance,
				LPSTR lpCmdLine, 
				int nCmdShow
			) :
				application_instance(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
			{}
		};
	}
}

#endif//__github_com_myun2__winnaria__win_main_holder_HPP__

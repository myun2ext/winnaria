#ifndef __github_com_myun2__winoria__core__window_HPP__
#define __github_com_myun2__winoria__core__window_HPP__

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			struct window_options
			{
				LPCTSTR lpClassName;
				LPCTSTR lpWindowName;
				DWORD dwStyle;
				int x;
				int y;
				int nWidth;
				int nHeight;
				HWND hWndParent;
				HMENU hMenu;
				HINSTANCE hInstance;
				LPVOID lpParam;

				window_options()
				{
					lpClassName = NULL;
					lpWindowName = NULL;
					dwStyle = NULL;
					x = 0;
					y = 0;
					nWidth = 0;
					nHeight = 0;
					hWndParent = NULL;
					hMenu = NULL;
					hInstance = NULL;
					lpParam = NULL;
				}
			};

			struct create_window_failed_exception {};

			class window
			{
			protected:
				HWND m_hWnd;
			public:
				window(){}
				window(const window_options& params) { create(params); }
				
				void create(const window_options& params)
				{
					m_hWnd = ::CreateWindow(
						param.lpClassName,
						param.lpWindowName,
						param.dwStyle,
						param.x,
						param.y,
						param.nWidth,
						param.nHeight,
						param.hWndParent,
						param.hMenu,
						param.hInstance,
						param.lpParam);

					if ( m_hWnd == NULL ) throw create_window_failed_exception;
				}
			};
		}
	}
}

#endif//__github_com_myun2__winoria__core__window_HPP__

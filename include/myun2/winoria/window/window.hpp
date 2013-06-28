#ifndef __github_com_myun2__winoria__window__window_HPP__
#define __github_com_myun2__winoria__window__window_HPP__

#include "myun2/winoria/core/window.hpp"
#include "myun2/winoria/core/window_class.hpp"

namespace myun2
{
	namespace winoria
	{
		class window
		{
		private:
			class window_class : public core::window_class
			{
			private:
				typedef core::window_class _Base;
			public:
				window_class() : _Base("__Application_WinoriaAutoWindowClass_ProcessId") {}
			};
			window_class my_window_class;
			core::window my_window;
		public:
			void run()
			{
				my_window_class.regist();
				my_window.create(core::window_options(
				));
			}
		};
	}
}

#endif//__github_com_myun2__winoria__window__window_HPP__

#ifndef __github_com_myun2__winoria__core__api_assert_HPP__
#define __github_com_myun2__winoria__core__api_assert_HPP__

#include <windows.h>
#include "myun2/winoria/exception.hpp"

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			struct api_failed_exception {};

			template <typename T>
			void api_assert(T v, const char* msg) {
				if ( v == 0 )
					throw api_failed_exception();
			}
		}
	}
}

#endif//__github_com_myun2__winoria__core__api_assert_HPP__

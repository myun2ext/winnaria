#ifndef __github_com_myun2__winoria__core__api_assert_HPP__
#define __github_com_myun2__winoria__core__api_assert_HPP__

#include <windows.h>
#include "myun2/winoria/exception.hpp"
#include "myun2/winoria/core/format_message.hpp"

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			DECL_WINORIA_EXCEPTION(api_failed_exception);

			template <typename T>
			void assert_nonzero_api_returned(T v, const char* detail="")
			{
				if ( value == 0 )
				{
					throw api_failed_exception(v, format_message(v) + detail);
				}
			}

			template <typename T>
			void throw_format_exception(DWORD code, const char* detail="") {
				throw T(code, format_message(v) + detail);
			}

			void throw_last_error_exception(const char* detail="") {
				throw_format_exception(::GetLastError(), detail);
			}
		}
	}
}

#endif//__github_com_myun2__winoria__core__api_assert_HPP__

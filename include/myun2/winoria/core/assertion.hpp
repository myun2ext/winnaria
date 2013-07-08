#ifndef __github_com_myun2__winoria__core__assertion_HPP__
#define __github_com_myun2__winoria__core__assertion_HPP__

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
				if ( v == 0 )
				{
					throw api_failed_exception(v, format_message(v) + detail);
				}
			}

			template <typename T>
			void api_valid_assert(T v, const char* detail="") {
				assert_nonzero_api_returned(v, detail);
			}

			template <typename T>
			void throw_formatted_exception(DWORD code, const char* detail="") {
				throw T(code, format_message(code) + detail);
			}

			template <typename T>
			void throw_last_error_exception(const char* detail="") {
				throw_formatted_exception<T> (::GetLastError(), detail);
			}
		}
	}
}

#endif//__github_com_myun2__winoria__core__assertion_HPP__

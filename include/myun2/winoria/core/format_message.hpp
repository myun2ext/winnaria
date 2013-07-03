#ifndef __github_com_myun2__winoria__core__format_message_HPP__
#define __github_com_myun2__winoria__core__format_message_HPP__

#include <windows.h>

namespace myun2
{
	namespace winoria
	{
		namespace core
		{
			::std::string format_message(DWORD code)
			{
				LPTSTR message_buffer = NULL;
				if ( ::FormatMessage(	FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
									NULL, code, LANG_USER_DEFAULT, (LPTSTR)&message_buffer, 0, NULL ) == 0 )
					return 0;
				::std::string message_str = message_buffer;
				::LocalFree(message_buffer);
				return message_str;
			}
		}
	}
}

#endif//__github_com_myun2__winoria__core__format_message_HPP__

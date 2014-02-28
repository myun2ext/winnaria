#include "myun2/winoria/exception.hpp"
#include <stdio.h>

using myun2::winoria::exception;

DECL_WINORIA_EXCEPTION(test_exception);

int main()
{
	try
	{
		throw test_exception("This is Test.", 3);
	}
	catch(const exception& e)
	{
		printf("Exception Name:  %s\n", e.name.c_str());
		printf("Code:            0x%08X\n", e.code);
		printf("Message:         \"%s\"\n", e.message.c_str());
		return 0;
	}

	return 1;
}
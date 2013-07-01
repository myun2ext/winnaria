#include "myun2/winoria/window.hpp"

using namespace myun2::winoria;

class win_main
{
public:
	int run()
	{
		try
		{
			window win;
			win.run();
			return 0;
		}
		catch(const ::std::string& msg)
		{
			printf("%s\n", msg.c_str());
		}
	}
};

#include "myun2/winoria/main.hpp"

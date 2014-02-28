#include "myun2/winoria/core/window_class_registerer.hpp"
#include <stdio.h>

using myun2::winoria::core::window_class;
using myun2::winoria::core::window_class_registerer;

int main()
{
	window_class wc("");
	window_class_registerer::register_class(wc);

	return 1;
}

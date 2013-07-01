#ifndef __github_com_myun2__winoria__exception_HPP__
#define __github_com_myun2__winoria__exception_HPP__

#include <string>

namespace myun2
{
	namespace winoria
	{
		class exception : public ::std::string
		{
		public:
			exception(){}
			exception(const char* s): ::std::string(s){}
			exception(const ::std::string& s): ::std::string(s){}
		};
	}
}

#define DECL_WINORIA_EXCEPTION(name)	\
		class name : public exception	\
		{	\
		public:	\
			name(){}	\
			name(const char* s): exception(s){}	\
			name(const ::std::string& s): exception(s){}	\
		};

#endif//__github_com_myun2__winoria__exception_HPP__

#ifndef __github_com_myun2__winoria__exception_HPP__
#define __github_com_myun2__winoria__exception_HPP__

#include <string>

namespace myun2
{
	namespace winoria
	{
		class exception //: public ::std::string
		{
		public:
			const int code;
			const ::std::string name;
			const ::std::string message;
			//typedef ::std::string _Base, message;

			exception(const char* name_in)
				: name(name_in), code(0) {}
			exception(const char* name_in, int code_in)
				: name(name_in), code(code_in) {}

			exception(const char* name_in, const char* msg_in)
				: name(name_in), code(0), message(msg_in) {}
			exception(const char* name_in, const ::std::string& msg_in)
				: name(name_in), code(0), message(msg_in) {}

			exception(const char* name_in, int code_in, const char* msg_in)
				: name(name_in), code(code_in), message(msg_in) {}
			exception(const char* name_in, int code_in, const ::std::string& msg_in)
				: name(name_in), code(code_in), message(msg_in) {}
		};
	}
}

#define DECL_WINORIA_EXCEPTION(ClassName)	\
		class ClassName : public ::myun2::winoria::exception	\
		{	\
		private:	\
			typedef ::myun2::winoria::exception _Base;	\
		public:	\
			ClassName()	\
				: _Base(#ClassName) {}	\
			ClassName(int code_in)	\
				: _Base(#ClassName, code_in) {}	\
			ClassName(const char* msg_in)	\
				: _Base(#ClassName, msg_in) {}	\
			ClassName(const ::std::string& msg_in)	\
				: _Base(#ClassName, msg_in) {}	\
			ClassName(int code_in, const char* msg_in)	\
				: _Base(#ClassName, code_in, msg_in) {}	\
			ClassName(const char* msg_in, int code_in)	\
				: _Base(#ClassName, code_in, msg_in) {}	\
			ClassName(int code_in, const ::std::string& msg_in)	\
				: _Base(#ClassName, code_in, msg_in) {}	\
		};

#endif//__github_com_myun2__winoria__exception_HPP__

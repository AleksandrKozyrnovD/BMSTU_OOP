#ifndef _BASE_EXCEPTION_H_
#define _BASE_EXCEPTION_H_

#include <exception>
#include <string>

using str = const char *;

class BaseException : public std::exception {
public:
	BaseException(const str &time, const str &filename,
	              const size_t &line, const str &class_name,
	              const str &method_name, const str &info) noexcept
	{
//		ErrorInfo = "\nTime: " + time +
//		            "\nError in file " + filename +
//		            ", line " + std::to_string(line) +
//		            ", in method " + method_name +
//		            " of class " + class_name +
//		            "\n Info: " + info + "\n";
		snprintf(ErrorInfo, sizeof(ErrorInfo), "\nTime:  %s\nError in file  %s, line  %d, in method  %s of class  %s\n Info:  %s\n",
				 time, filename, line, method_name, class_name, info);
	}

	const char *what() const noexcept
	{
		return ErrorInfo;
	}

protected:
	char  ErrorInfo[512];
};

#endif // _BASE_EXCEPTION_H_
//
// Created by aleksandr on 4/12/24.
//

#ifndef LAB2_CONTAINEREXCEPTION_H
#define LAB2_CONTAINEREXCEPTION_H

#include <iostream>
#include <exception>
#include <cstring>

using namespace std;

class ContainerException : public std::exception
{
protected:
	char errormsg[256];

public:
	ContainerException() noexcept = default;

	ContainerException(const char *File, const char *Function, const char *msg, int Line) noexcept
	{
		snprintf(errormsg, 256, "\nFile: %s\nFunction: %s\nLine:%d +\nMessage: %s",
				 File, Function, Line, msg);
	}

	~ContainerException() override = default;

	const char *what() const noexcept override
	{
		return errormsg;
	}
};

#endif //LAB2_CONTAINEREXCEPTION_H

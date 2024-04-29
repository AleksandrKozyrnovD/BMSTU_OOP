//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_ITERATOREXCEPTION_H
#define LAB2_ITERATOREXCEPTION_H

#include <iostream>
#include <exception>
#include <cstring>

class IteratorException : std::exception
{
protected:
//	std::string errormsg;
	char errormsg[256];
public:
	IteratorException() noexcept = default;

	IteratorException(const char *File, const char *Function, const char *msg, int Line) noexcept
	{
//		errormsg = "\nFile: " + File + "\nFunction: " + Function + "\nLine: " + std::to_string(Line) + "\nMessage: " + msg;
		snprintf(errormsg, 256, "\nFile: %s\nFunction: %s\nLine: %d\nMessage: %s",
				 File, Function, Line, msg);
	}

	~IteratorException() override = default;

	const char *what() const noexcept override
	{
		return errormsg;
	}
};

class IteratorInvalid : IteratorException
{
public:
	IteratorInvalid(const char *File, const char *Function, const char *msg, int Line) noexcept
	: IteratorException(File, Function, msg, Line)
	{}
};


#endif //LAB2_ITERATOREXCEPTION_H

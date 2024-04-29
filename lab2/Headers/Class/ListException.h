//
// Created by aleksandr on 4/12/24.
//

#ifndef LAB2_LISTEXCEPTION_H
#define LAB2_LISTEXCEPTION_H

#include "../Base/ContainerException.h"

class ListException : public ContainerException
{
public:
	ListException(const char *File, const char *Function, const char *message, int Line) noexcept
	: ContainerException(File, Function, message, Line) {}
};


class ListEmptyException : public ListException
{
public:
	ListEmptyException(const char *File, const char *Function, const char *message, int Line) noexcept
	: ListException(File, Function, message, Line) {}
};

class ListIndexException : public ListException
{
public:
	ListIndexException(const char *File, const char *Function, const char *message, int Line) noexcept
	: ListException(File, Function, message, Line) {}
};

class ListSliceException : public ListException
{
public:
	ListSliceException(const char *File, const char *Function, const char *message, int Line) noexcept
	: ListException(File, Function, message, Line) {}
};

#endif //LAB2_LISTEXCEPTION_H

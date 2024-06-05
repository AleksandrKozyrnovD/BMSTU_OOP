#ifndef _BASE_CONTAINER_H_
#define _BASE_CONTAINER_H_

#include <cstdlib>

class BaseContainer {

	using size_type = size_t;

public:
	bool IsEmpty() const {return size == 0;}

	size_t Size() const {return size;}

	~BaseContainer();

protected:
	BaseContainer()
	{
		size = 0;
	}
	size_type size = 0;
};

#endif // _BASE_CONTAINER_H_
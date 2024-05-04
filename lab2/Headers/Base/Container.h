//
// Created by aleksandr on 4/12/24.
//

#ifndef LAB2_CONTAINER_H
#define LAB2_CONTAINER_H

class Container
{
protected:
	int size;
public:
	using size_type = int;

	Container() noexcept;

	explicit Container(int size) noexcept;

	virtual ~Container() noexcept = default;

	bool IsEmpty() const noexcept;

	int GetSize() const noexcept;
};

#include "Container.hpp"

#endif //LAB2_CONTAINER_H

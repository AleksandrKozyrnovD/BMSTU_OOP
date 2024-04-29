//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_CONTAINER_HPP
#define LAB2_CONTAINER_HPP

#include "Container.h"

Container::Container() noexcept
		: size(0)
{}

Container::Container(int size) noexcept
		: size(size)
{}

Container::~Container() noexcept
{}

bool Container::IsEmpty() const noexcept
{
	return this->size == 0;
}

int Container::GetSize() const noexcept
{
	return this->size;
}

#endif //LAB2_CONTAINER_HPP

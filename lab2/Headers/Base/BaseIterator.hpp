//
// Created by aleksandr on 4/21/24.
//

#ifndef LAB2_BASEITERATOR_HPP
#define LAB2_BASEITERATOR_HPP

#include "BaseIterator.h"

template<RestrictedType T>
BaseIterator<T>::BaseIterator() noexcept
: index(0), size(0)
{}

template<RestrictedType T>
BaseIterator<T>::~BaseIterator() noexcept
{}

template<RestrictedType T>
BaseIterator<T>::BaseIterator(const BaseIterator<T>& other) noexcept
: index(other.index), size(other.size), current(other.current)
{}

template <RestrictedType T>
void BaseIterator<T>::CheckValidity(const char *File, const char *Function, int line) const
{
	if (this->index >= this->size || this->index < 0 || this->current.expired())
	{
		char errmsg[128];
		snprintf(errmsg, 128, "Invalid iterator index: %d, where size: %d",
		         this->index, this->size);
		throw IteratorInvalid(File, Function, errmsg, line);
	}
}

template <RestrictedType T>
bool BaseIterator<T>::operator==(const BaseIterator& iterator) const
{
	return this->index == iterator.index;
}


#endif //LAB2_BASEITERATOR_HPP

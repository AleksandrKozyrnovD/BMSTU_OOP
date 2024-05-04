//
// Created by aleksandr on 4/14/24.
//

#ifndef LAB2_BASEITERATOR_H
#define LAB2_BASEITERATOR_H

#include "../Class/MyConcepts.h"
#include "../Class/IteratorException.h"

template<RestrictedType T>
class List;

template<RestrictedType T>
class BaseIterator
{
protected:
	int index;
	int size;
	using Node = List<T>::Node;
	using NodePtr = std::weak_ptr<Node>;
	NodePtr current;

	void CheckValidity(const char *File, const char *Function, int line) const;

	BaseIterator() noexcept;
	BaseIterator(const BaseIterator& other) noexcept;
public:

	bool operator==(const BaseIterator<T>& iterator) const;

	~BaseIterator() noexcept;
};

#include "BaseIterator.hpp"




#endif //LAB2_BASEITERATOR_H

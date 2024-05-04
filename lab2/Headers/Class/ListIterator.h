//
// Created by aleksandr on 4/14/24.
//

#ifndef LAB2_LISTITERATOR_H
#define LAB2_LISTITERATOR_H

#include "../Base/BaseIterator.h"
#include "MyConcepts.h"
#include "IteratorException.h"
//#include "ConstListIterator.h"

#pragma region old

template<RestrictedType T>
class ConstListIterator;


template<RestrictedType T>
class ListIterator : public BaseIterator<T>
{

	using value_type = T;
	using pointer = std::shared_ptr<T>;
	using reference = T&;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::forward_iterator_tag;

protected:
	reference GetCurrent() const noexcept;
	pointer GetCurrentPointer() const noexcept;

public:
	ListIterator() noexcept = default;
	explicit ListIterator(int size) noexcept;

	ListIterator(const ListIterator<value_type>& iterator) noexcept;
	ListIterator(const List<value_type>& list) noexcept;

	ListIterator(const ConstListIterator<value_type>& other) noexcept;

	ListIterator<T>& operator=(const ListIterator<value_type>& iterator) noexcept;
	ListIterator<T>& operator=(const List<value_type>& list) noexcept;


	reference operator*() const;
	pointer operator->() const;
	ListIterator<T>& operator++();
	ListIterator<T> operator++(int);


	operator bool() const noexcept;
//	bool operator==(const ListIterator<T>& iterator) const;
//	bool operator!=(const ListIterator<T>& iterator) const;
};

#include "IteratorImplementation/ListIterator.hpp"
#pragma endregion



#endif //LAB2_LISTITERATOR_H

//
// Created by aleksandr on 4/15/24.
//

#ifndef LAB2_CONSTLISTITERATOR_H
#define LAB2_CONSTLISTITERATOR_H


#include "../Base/BaseIterator.h"
#include "MyConcepts.h"
#include "IteratorException.h"


#pragma region old

template<RestrictedType T>
class ListIterator;

template<RestrictedType T>
class ConstListIterator : public BaseIterator<T>
{

	using value_type = T;
	using pointer = const std::shared_ptr<T>;
	using reference = const T&;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::forward_iterator_tag;

protected:
	reference GetCurrent() const noexcept;
	pointer GetCurrentPointer() const noexcept;

public:
	ConstListIterator() noexcept = default;
	explicit ConstListIterator(int size) noexcept;

	ConstListIterator(const ConstListIterator<value_type>& iterator) noexcept;
	ConstListIterator(const List<value_type>& list) noexcept;
	ConstListIterator(const ListIterator<value_type>& other) noexcept;

	ConstListIterator<T>& operator=(const ConstListIterator<value_type>& iterator) noexcept;
	ConstListIterator<T>& operator=(const List<value_type>& list) noexcept;


	reference operator*() const;
	pointer operator->() const;
	ConstListIterator<T>& operator++();
	ConstListIterator<T> operator++(int);


	operator bool() const noexcept;
//	bool operator==(const ConstListIterator<T>& iterator) const;
//	bool operator!=(const ConstListIterator<T>& iterator) const;
};

#include "IteratorImplementation/ConstListIterator.hpp"
#pragma endregion


#endif //LAB2_CONSTLISTITERATOR_H

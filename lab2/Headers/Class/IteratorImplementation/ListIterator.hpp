//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_LISTITERATOR_HPP
#define LAB2_LISTITERATOR_HPP

#include "../ListIterator.h"
#include "../List.h"

#pragma region old

template<RestrictedType T>
ListIterator<T>::ListIterator(int size) noexcept
{
	this->index = size;
	this->size = size;
}

template<RestrictedType T>
ListIterator<T>::ListIterator(const BaseIterator<T>& iterator) noexcept
: BaseIterator<T>(iterator)
{}

template <RestrictedType T>
ListIterator<T>::reference ListIterator<T>::GetCurrent() const noexcept
{
	this->CheckValidity(__FILE__, __FUNCTION__, __LINE__);

	return this->current.lock()->GetData();
}

template <RestrictedType T>
ListIterator<T>::reference ListIterator<T>::operator*() const
{
	return this->GetCurrent();
}



template <RestrictedType T>
ListIterator<T>::ListIterator(const ListIterator<value_type>& iterator) noexcept
: BaseIterator<T>(iterator)
{}

template <RestrictedType T>
ListIterator<T>::ListIterator(const List<value_type>& list) noexcept
{
	this->current = list.head;
	this->size = list.size;
	this->index = 0;
}


template <RestrictedType T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator<value_type>& iterator) noexcept
{
	this->current = iterator.current;
	this->size = iterator.size;
	this->index = iterator.index;
	return *this;
}

template <RestrictedType T>
ListIterator<T>& ListIterator<T>::operator=(const List<value_type>& list) noexcept
{
	this->current = list.head;
	this->size = list.size;
	this->index = 0;
	return *this;
}

template <RestrictedType T>
ListIterator<T>::pointer ListIterator<T>::GetCurrentPointer() const noexcept
{
	return &this->current->GetData();
}

template <RestrictedType T>
ListIterator<T>::pointer ListIterator<T>::operator->() const
{
	return this->GetCurrentPointer();
}

template <RestrictedType T>
ListIterator<T>& ListIterator<T>::operator++()
{
	this->CheckValidity(__FILE__, __FUNCTION__, __LINE__);

	this->index++;
	this->current = this->current.lock()->GetNext();
	return *this;
}

template <RestrictedType T>
ListIterator<T> ListIterator<T>::operator++(int)
{
	++(*this);
	return *this;
}

template <RestrictedType T>
ListIterator<T>::operator bool() const noexcept
{
	return (bool) (this->index < this->size && !this->current.expired());
}

template <RestrictedType T>
bool ListIterator<T>::operator==(const ListIterator& iterator) const
{
	return this->index == iterator.index;
}

template <RestrictedType T>
bool ListIterator<T>::operator!=(const ListIterator& iterator) const
{
	return !(*this == iterator);
}

#pragma endregion



#endif //LAB2_LISTITERATOR_HPP

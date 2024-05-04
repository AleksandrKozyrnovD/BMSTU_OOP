//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_CONSTLISTITERATOR_HPP
#define LAB2_CONSTLISTITERATOR_HPP

#include "../ConstListIterator.h"
#include "../List.h"

#pragma region old


template<RestrictedType T>
ConstListIterator<T>::ConstListIterator(int size) noexcept
{
	this->index = size;
	this->size = size;
}

template<RestrictedType T>
ConstListIterator<T>::ConstListIterator(const ListIterator<T>& iterator) noexcept
: BaseIterator<T>(iterator)
{}

template <RestrictedType T>
ConstListIterator<T>::reference ConstListIterator<T>::GetCurrent() const noexcept
{
	this->CheckValidity(__FILE__, __FUNCTION__, __LINE__);

	return this->current.lock()->GetData();
}

template <RestrictedType T>
ConstListIterator<T>::reference ConstListIterator<T>::operator*() const
{
	return this->GetCurrent();
}



template <RestrictedType T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<value_type>& iterator) noexcept
: BaseIterator<T>(iterator)
{}

template <RestrictedType T>
ConstListIterator<T>::ConstListIterator(const List<value_type>& list) noexcept
{
	this->current = list.head;
	this->size = list.size;
	this->index = 0;
}

template <RestrictedType T>
ConstListIterator<T>& ConstListIterator<T>::operator=(const ConstListIterator<value_type>& iterator) noexcept
{
	this->current = iterator.current;
	this->size = iterator.size;
	this->index = iterator.index;
	return *this;
}

template <RestrictedType T>
ConstListIterator<T>& ConstListIterator<T>::operator=(const List<value_type>& list) noexcept
{
	this->current = list.head;
	this->size = list.size;
	this->index = 0;
	return *this;
}

template <RestrictedType T>
ConstListIterator<T>::pointer ConstListIterator<T>::GetCurrentPointer() const noexcept
{
	return &this->current->GetData();
}

template <RestrictedType T>
ConstListIterator<T>::pointer ConstListIterator<T>::operator->() const
{
	return this->GetCurrentPointer();
}

template <RestrictedType T>
ConstListIterator<T>& ConstListIterator<T>::operator++()
{
	this->CheckValidity(__FILE__, __FUNCTION__, __LINE__);

	this->index++;
	this->current = this->current.lock()->GetNext();
	return *this;
}

template <RestrictedType T>
ConstListIterator<T> ConstListIterator<T>::operator++(int)
{
	++(*this);
	return *this;
}

template <RestrictedType T>
ConstListIterator<T>::operator bool() const noexcept
{
	return (bool) (this->index < this->size && !this->current.expired());
}

//template <RestrictedType T>
//bool ConstListIterator<T>::operator==(const ConstListIterator& iterator) const
//{
//	return this->index == iterator.size;
//}
//
//template <RestrictedType T>
//bool ConstListIterator<T>::operator!=(const ConstListIterator& iterator) const
//{
//	return !(*this == iterator);
//}

#pragma endregion


#endif //LAB2_CONSTLISTITERATOR_HPP

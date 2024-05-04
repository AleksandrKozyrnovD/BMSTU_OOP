//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_LISTOPERATORS_HPP
#define LAB2_LISTOPERATORS_HPP

#include "../List.h"

template<RestrictedType T>
T& List<T>::operator[](int index)
{
	return this->Get(index);
}

template<RestrictedType T>
const T& List<T>::operator[](int index) const
{
	return this->Get(index);
}

template<RestrictedType T>
std::strong_ordering List<T>::operator<=>(const List<T> &other) const
{
	return this->Compare(other);
}

template<RestrictedType T>
List<T> List<T>::operator+(const List<T>& other) const
{
	List<T> result = *this;

	return result.Merge(other);
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T> List<T>::operator+(const List<U> &other) const
{
	List<T> result = *this;

	return result.Merge(other);
}

template<RestrictedType T>
List<T>& List<T>::operator+=(const List<T>& other)
{
	return this->Merge(other);
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T>& List<T>::operator+=(const List<U>& other)
{
	return this->Merge(other);
}

template<RestrictedType T>
template<ConvertableContainer<T> C>
List<T>& List<T>::operator+=(const C& container)
{
	return this->Merge(container);
}

template<RestrictedType T>
List<T>& List<T>::operator=(const List<T>& other)
{
	this->Clear();
	for (auto& i : other)
	{
		this->PushBack(i);
	}
//	this->head = other.head;
//	this->size = other.size;

	return *this;
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T>& List<T>::operator=(const List<U>& other)
{
	this->Clear();
	for (auto& i : other)
	{
		this->PushBack(i);
	}
}

template<RestrictedType T>
template<ConvertableContainer<T> C>
List<T>& List<T>::operator=(const C& container)
{
	this->Clear();
	for (auto i : container)
	{
		this->PushBack(i);
	}
}

template<RestrictedType T>
List<T>& List<T>::operator=(List<T>&& other) noexcept
{
	this->head = other.head;
	this->size = other.size;

	other.head = nullptr;

	return *this;
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T>& List<T>::operator=(List<U>&& other) noexcept
{
	this->head = other.head;
	this->size = other.size;

	other.head = nullptr;
}

#endif //LAB2_LISTOPERATORS_HPP

//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_LISTCONSTRUCTORS_HPP
#define LAB2_LISTCONSTRUCTORS_HPP

#include "../List.h"

template<RestrictedType T>
List<T>::List(const List<T>& other)
: Container(), head(nullptr), tail(nullptr)
{
	for (auto i : other)
	{
		this->PushBack(i);
	}
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T>::List(const List<U>& other)
: Container(), head(nullptr), tail(nullptr)
{
	for (auto i : other)
	{
		this->PushBack(i);
	}
}

template<RestrictedType T>
List<T>::List(List<T>&& other) noexcept
: Container(other.size), head(other.head), tail(other.tail)
{
	other.head = nullptr;
}

//template<RestrictedType T>
//template<Convertable_To<T> U>
//List<T>::List(List<U>&& other) noexcept
////: Container(), head(other.head), tail(other.tail)
//{
//	for (auto& i : other)
//	{
//		this->PushBack(i);
//	}
//	other.Clear();
////	other.head = nullptr;
////	other.tail = nullptr;
//}

template<RestrictedType T>
List<T>::List(std::initializer_list<T> list)
: Container(), head(nullptr), tail(nullptr)
{
	for (auto& i : list)
	{
		this->PushBack(i);
	}
//	auto it = list.begin();
//
//	pointer currentNode = std::make_shared<Node>(*it);
//	this->head = currentNode;
//	++it;
//
//	for (; it != list.end(); ++it)
//	{
//		currentNode->SetNext(std::make_shared<Node>(*it));
//		currentNode = currentNode->GetNext();
//	}
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T>::List(std::initializer_list<U> list)
: Container(), head(nullptr), tail(nullptr)
{
	for (auto& i : list)
	{
		this->PushBack(i);
	}
//	auto it = list.begin();
//
//	pointer currentNode = std::make_shared<Node>(*it);
//	this->head = currentNode;
//	++it;
//
//	for (; it != list.end(); ++it)
//	{
//		currentNode->SetNext(std::make_shared<Node>(*it));
//		currentNode = currentNode->GetNext();
//	}
}

template<RestrictedType T>
template<ConvertableIterator<T> I>
List<T>::List(I begin, I end)
: Container(), head(nullptr), tail(nullptr)
{
	pointer currentNode = std::make_shared<Node>(*begin);
	this->head = currentNode;
	++begin;
	this->size++;

	for (; begin != end; ++begin)
	{
		this->size++;
		currentNode->SetNext(std::make_shared<Node>(*begin));
		currentNode = currentNode->GetNext();
	}
}


template<RestrictedType T>
template<ConvertableContainer<T> C>
List<T>::List(const C& container)
//: Container(container.size()), head(nullptr), tail(nullptr)
: head(nullptr), tail(nullptr)
{
	for (auto& i : container)
	{
		this->PushBack(i);
	}
//	auto it = container.begin();
//
//	pointer currentNode = std::make_shared<Node>(*it);
//	this->head = currentNode;
//	++it;
//
//	for (; it != container.end(); ++it)
//	{
//		currentNode->SetNext(std::make_shared<Node>(*it));
//		currentNode = currentNode->GetNext();
//	}
}

#endif //LAB2_LISTCONSTRUCTORS_HPP

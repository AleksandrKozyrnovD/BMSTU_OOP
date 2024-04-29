//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_NODE_HPP
#define LAB2_NODE_HPP

#include "../List.h"

//========Node Constructors================
template<RestrictedType T>
List<T>::Node::Node() noexcept
: next(nullptr), data(T())
{}

template<RestrictedType T>
List<T>::Node::Node(const Node& other) noexcept
: data(other.data)
{
	this->next = std::make_shared(*other.next);
}

template<RestrictedType T>
List<T>::Node::Node(Node&& other) noexcept
: data(std::move(other.data)), next(*other.next)
{
	other.next = nullptr;
}


template<RestrictedType T>
List<T>::Node::Node(T data) noexcept
		: data(data), next(nullptr)
{}
//========Node Constructors================


template<RestrictedType T>
List<T>::Node& List<T>::Node::operator=(const Node& other)
{
	this->data = other.data;
	this->next = other.next;

	return *this;
}

template<RestrictedType T>
List<T>::Node& List<T>::Node::operator=(Node&& other) noexcept
{
	this->data = std::move(other.data);
	this->next = other.next;
	other.next = nullptr;

	return *this;
}

//template <typename Type>
//shared_ptr<Type> Node<Type>::get()
//{
//	shared_ptr<Node> work = this->shared_from_this();
//
//	return { work, &work->data };
//}

template<RestrictedType T>
List<T>::reference List<T>::Node::GetData()
{
	return this->data;
}

template<RestrictedType T>
List<T>::reference List<T>::Node::operator*()
{
	return GetData();
}

template<RestrictedType T>
List<T>::const_reference List<T>::Node::GetData() const
{
	return this->data;
}

template<RestrictedType T>
List<T>::pointer List<T>::Node::GetNext() const
{
	return this->next;
}

template<RestrictedType T>
void List<T>::Node::SetNext(pointer Next) noexcept
{
	this->next = Next;
}

template<RestrictedType T>
void List<T>::Node::SetData(T Data) noexcept
{
	this->data = Data;
}

#endif //LAB2_NODE_HPP

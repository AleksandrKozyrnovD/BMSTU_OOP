//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_LISTMETHODS_HPP
#define LAB2_LISTMETHODS_HPP

#include "../List.h"

template<RestrictedType T>
void List<T>::PushFront(T data)
{
//	pointer newNode = pointer(data);

	pointer newNode = std::make_shared<Node>(data);

	if (this->head != nullptr)
	{
		newNode->SetNext(this->head);
		this->head = newNode;
	}
	else
	{
		newNode->SetNext(nullptr);
		this->head = this->tail = newNode;
	}
	this->size++;
}

template<RestrictedType T>
void List<T>::PushBack(T data)
{
//	pointer newNode = pointer(data);

	pointer newNode = std::make_shared<Node>(data);
	if (this->head == nullptr)
	{
		this->head = this->tail = newNode;
	}
	else
	{
		this->tail->SetNext(newNode);
		this->tail = newNode;
	}

	this->size++;
}

template<RestrictedType T>
T& List<T>::PopFront()
{
	EmptyListCheck(__FILE__, __FUNCTION__ , __LINE__);


	T data = this->head->GetData();
	if (this->head != this->tail)
	{
		this->head = this->head->GetNext();
	}
	else
	{
		this->head = this->tail = nullptr;
	}
	this->size--;

	return data;
}

template<RestrictedType T>
T& List<T>::PopBack()
{
	EmptyListCheck(__FILE__, __FUNCTION__ , __LINE__);

	T data;
	if (this->head->GetNext() == nullptr)
	{
		data = this->head->GetData();
		this->head = this->tail = nullptr;
	}
	else if (this->head->GetNext()->GetNext() == nullptr)
	{
		data = this->head->GetNext()->GetData();
		this->head->SetNext(nullptr);
		this->tail = this->head;
	}
	else
	{
		pointer current = this->head;
		for (; current->GetNext() != this->tail; current = current->GetNext());

		data = this->tail->GetData();
		current->SetNext(nullptr);
		this->tail = current;
	}
	this->size--;

	return data;
}

template<RestrictedType T>
T& List<T>::MyGet(int index)
{
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__ , __LINE__, index);

	ListIterator<T> beg = this->begin();
	for (int i = 0; i < index; i++)
	{
		++beg;
	}

	return *beg;
}

template<RestrictedType T>
const T& List<T>::MyGet(int index) const
{
	IndexOutOfRangeCheck(__FILE__, __LINE__, index);

	ConstListIterator<T> beg = this->begin();
	for (int i = 0; i < index; i++)
	{
		++beg;
	}
}

template<RestrictedType T>
T& List<T>::Get(int index)
{

	return this->MyGet(index);
}

template<RestrictedType T>
const T& List<T>::Get(int index) const
{
	return this->MyGet(index);
}


template<RestrictedType T>
void List<T>::Set(int index, T& data)
{
	this->Get(index) = data;
}

template<RestrictedType T>
template<Convertable_To<T> U>
void List<T>::Set(int index, U& data)
{
	this->Get(index) = data;
}

template<RestrictedType T>
void List<T>::Remove(int index)
{
	EmptyListCheck(__FILE__, __FUNCTION__, __LINE__);
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__, __LINE__, index);


	if (index == this->size - 1)
	{
		this->PopBack();
	}
	else if (index == 0)
	{
		this->PopFront();
	}
	else
	{
		pointer current = this->head;
		pointer prev = nullptr;
		for (int i = 0; i < index; i++)
		{
			prev = current;
			current = current->GetNext();
		}
		prev->SetNext(current->GetNext());
		this->size--;
	}
}

template<RestrictedType T>
void List<T>::Remove(int from, int to)
{
	SliceCheck(__FILE__, __FUNCTION__, __LINE__, from, to);

	if (from == 0)
	{
		for (int i = from; i < to; i++)
		{
			this->PopFront();
		}
	}
	else if (to == this->size)
	{
		for (int i = from; i < to; i++)
		{
			this->PopBack();
		}
	}
	else
	{
		pointer firstBorder = this->head;

		for (int i = 0; i < from - 1; i++)
		{
			firstBorder = firstBorder->GetNext();
		}

		pointer secondBorder = firstBorder->GetNext();

		for (int i = from; i < to; i++)
		{
			secondBorder = secondBorder->GetNext();
		}

		firstBorder->SetNext(secondBorder);
		this->size -= (from - to);
	}
}

template<RestrictedType T>
void List<T>::Remove(ListIterator<T>& begin, ListIterator<T>& end)
{
	ListIterator<T> it = this->begin();

	pointer prev = nullptr;
	pointer current = this->head;

	for (; it != begin; ++it)
	{
		prev = current;
		current = current->GetNext();
	}
	pointer border = prev;

	for (; begin != end; ++begin)
	{
		prev = current;
		current = current->GetNext();
		this->size--;
	}

	if (border != nullptr)
	{
		border->SetNext(current);
	}
	else
	{
		this->head = this->tail = nullptr;
		this->size = 0;
	}
}

template<RestrictedType T>
List<T>& List<T>::Merge(const List<T> &other)
{
	for (auto i : other)
	{
		this->PushBack(i);
	}

	return *this;
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T>& List<T>::Merge(const List<U>& other)
{
	for (auto i : other)
	{
		this->PushBack(i);
	}

	return *this;
}

template<RestrictedType T>
List<T> List<T>::Merge(const List<T> &other) const
{
	List<T> result = *this;

	return result.Merge(other);
}

template<RestrictedType T>
template<Convertable_To<T> U>
List<T> List<T>::Merge(const List<U>& other) const
{
	List<T> result = List(*this);

	return result.Merge(other);
}

template<RestrictedType T>
template<ConvertableIterator<T> I>
List<T>& List<T>::Merge(I begin, I end)
{
	for (; begin != end; ++begin)
	{
		this->PushBack(*begin);
	}

	return *this;
}

template<RestrictedType T>
template<ConvertableIterator<T> I>
List<T> List<T>::Merge(I begin, I end) const
{
	List<T> result = List<T>(*this);

	return result.Merge(begin, end);
}

template<RestrictedType T>
template<ConvertableContainer<T> C>
List<T>& List<T>::Merge(C& container)
{
	for (auto& i : container)
	{
		this->PushBack(i);
	}

	return *this;
}

template<RestrictedType T>
template<ConvertableContainer<T> C>
List<T> List<T>::Merge(C& container) const
{
	List<T> result = List(*this);

	return result.Merge(container);
}

template<RestrictedType T>
void List<T>::Clear()
{
	this->head = this->tail = nullptr;
	this->size = 0;
}


template<RestrictedType T>
std::strong_ordering List<T>::Compare(const List<T> &other) const
{
	int thisSize = this->GetSize();
	int otherSize = other.GetSize();

	if (thisSize < otherSize)
	{
		return std::strong_ordering::less;
	}
	else if (thisSize > otherSize)
	{
		return std::strong_ordering::greater;
	}
	return std::strong_ordering::equal;
}


template<RestrictedType T>
void List<T>::PushNodeFront(pointer node)
{
	node->SetNext(this->head);
	this->head = node;
	this->size++;
}

template<RestrictedType T>
void List<T>::PushNodeBack(pointer node)
{
	pointer current = this->head;
	if (current == nullptr)
	{
		this->head = node;
	}
	else
	{
		for (; current->GetNext()!= nullptr; current = current->GetNext());

		current->SetNext(node);
	}
	this->size++;
}

template<RestrictedType T>
List<T> List<T>::GetSlice(int start, int end) const
{
	SliceCheck(__FILE__, __FUNCTION__, __LINE__, start, end);

	List<T> result;
	ListIterator<T> listIterator = ListIterator<T>(*this);

	for (int i = 0; i < start; i++, ++listIterator);

	for (int i = start; i < end; i++, ++listIterator)
	{
		result.PushBack(*listIterator);
	}

	return result;
}


template<RestrictedType T>
List<T>::Iterator List<T>::begin()
{
	EmptyListCheck(__FILE__, __FUNCTION__, __LINE__);

	return ListIterator<T>(*this);
}

template<RestrictedType T>
List<T>::Iterator List<T>::end()
{
	return ListIterator<T>(this->size);
}

template<RestrictedType T>
List<T>::ConstIterator List<T>::begin() const
{
	EmptyListCheck(__FILE__, __FUNCTION__, __LINE__);

	return ConstListIterator<T>(*this);
}

template<RestrictedType T>
List<T>::ConstIterator List<T>::end() const
{
	return ConstListIterator<T>(this->size);
}

template<RestrictedType T>
List<T>::ConstIterator List<T>::cbegin() const
{
	EmptyListCheck(__FILE__, __FUNCTION__, __LINE__);

	return ConstListIterator<T>(*this);
}

template<RestrictedType T>
List<T>::ConstIterator List<T>::cend() const
{
	return ConstListIterator<T>(this->size);
}

template<RestrictedType T>
void List<T>::IndexOutOfRangeCheck(const char *file, const char *function, int line, int index) const
{
	if (index < 0 || index > this->GetSize())
	{
		char msg[128];
//		const char *msg = "Index out of range: " + std::to_string(index) + " but Range: 0-" + std::to_string(this->GetSize());
		snprintf(msg, 128, "Index out of range: %d, but Range :0-%d",
				 index, this->GetSize());
		throw ListIndexException(file, function, msg, line);
	}
}

template<RestrictedType T>
void List<T>::EmptyListCheck(const char *file, const char *function, int line) const
{
	if (this->GetSize() == 0)
	{
		const char *msg = "Empty list";
		throw ListEmptyException(file, function, msg, line);
	}

}

template<RestrictedType T>
void List<T>::SliceCheck(const char *file, const char *function, int line, int start, int end) const
{
	EmptyListCheck(file, function, line);

	IndexOutOfRangeCheck(file, function, line, start);
	IndexOutOfRangeCheck(file, function, line, end);

	if (start >= end)
	{
		char msg[128];
		snprintf(msg, 128, "start >= end || %d >= %d",
				 start, end);
		throw ListSliceException(file, function, msg, line);
	}
}

template<RestrictedType T>
void List<T>::Insert(T data, int index)
{
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__, __LINE__, index);

	if (index == 0)
	{
		this->PushFront(data);
	}
	else if (index == this->size) //End
	{
		this->PushBack(data);
	}
	else
	{
		pointer currentNode = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->GetNext();
		}
		pointer nextcurrentNode = currentNode->GetNext();
		currentNode->SetNext(std::make_shared<Node>(data));
		currentNode->GetNext()->SetNext(nextcurrentNode);
		this->size++;
	}
}

template<RestrictedType T>
template<Convertable_To<T> U>
void List<T>::Insert(U data, int index)
{
	return this->Insert(T(data), index);
}

template<RestrictedType T>
void List<T>::Insert(const List<T> &other, int index)
{
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__ , __LINE__, index);

	if (index == 0)
	{
		for (auto i : other)
		{
			this->PushFront(i);
		}
	}
	else if (index == this->size)
	{
		this->Merge(other);
	}
	else
	{
		pointer currentNode = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->GetNext();
		}
		pointer nextcurrentNode = currentNode->GetNext();

		for (auto i : other)
		{
			currentNode->SetNext(std::make_shared<Node>(i));
			currentNode = currentNode->GetNext();
		}
		currentNode->SetNext(nextcurrentNode);
		this->size += other.size;
	}
}

template<RestrictedType T>
template<Convertable_To<T> U>
void List<T>::Insert(const List<U> &other, int index)
{
//	return this->Insert(other, index);
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__ , __LINE__, index);

	if (index == 0)
	{
		for (auto i : other)
		{
			this->PushFront(i);
		}
	}
	else if (index == this->size)
	{
		this->Merge(other);
	}
	else
	{
		pointer currentNode = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->GetNext();
		}
		pointer nextcurrentNode = currentNode->GetNext();

		for (auto i : other)
		{
			currentNode->SetNext(std::make_shared<Node>(i));
			currentNode = currentNode->GetNext();
			this->size++;
		}
		currentNode->SetNext(nextcurrentNode);
//		this->size += other.size;
	}
}

template<RestrictedType T>
template<InputIterator I>
requires requires(typename I::value_type t) { { t } -> std::convertible_to<T>;}
void List<T>::Insert(I begin, I end, int index)
{
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__ , __LINE__, index);

	if (index == 0)
	{
		for (; begin != end; ++begin)
		{
			this->PushFront(*begin);
		}
	}
	else if (index == this->size)
	{
		this->Merge(begin, end);
	}
	else
	{
		pointer currentNode = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->GetNext();
		}
		pointer nextcurrentNode = currentNode->GetNext();

		for (; begin != end; ++begin)
		{
			currentNode->SetNext(std::make_shared<Node>(*begin));
			currentNode = currentNode->GetNext();
			this->size++;
		}
		currentNode->SetNext(nextcurrentNode);
	}
}

template<RestrictedType T>
template<ConvertableContainer<T> C>
void List<T>::Insert(C& container, int index)
{
	IndexOutOfRangeCheck(__FILE__, __FUNCTION__ , __LINE__, index);

	if (index == 0)
	{
		for (auto i : container)
		{
			this->PushFront(i);
		}
	}
	else if (index == this->size)
	{
		this->Merge(container);
	}
	else
	{
		pointer currentNode = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->GetNext();
		}
		pointer nextcurrentNode = currentNode->GetNext();

		for (auto i : container)
		{
			currentNode->SetNext(std::make_shared<Node>(i));
			currentNode = currentNode->GetNext();
			this->size++;
		}
		currentNode->SetNext(nextcurrentNode);
	}
}

template<RestrictedType T>
ostream& operator<<(ostream& os, List<T>& list)
{
	if (!list.GetSize())
	{
		std::cout << "{}";
	}
	else
	{
		std::cout << "{ ";
		for (auto& i : list)
		{
			std::cout << i << " ";
		}
		std::cout << "}";
	}

	return os;
}

#endif //LAB2_LISTMETHODS_HPP

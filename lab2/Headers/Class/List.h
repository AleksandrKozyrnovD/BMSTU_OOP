//
// Created by aleksandr on 4/12/24.
//

#ifndef LAB2_LIST_H
#define LAB2_LIST_H

#include <memory>
#include <iostream>
#include "../Base/Container.h"
#include "../Base/BaseIterator.h"
#include "ListException.h"
#include "ListIterator.h"
#include "ConstListIterator.h"

#include "MyConcepts.h"


template<RestrictedType T>
class List : public Container
{
private:
	friend class ListIterator<T>;
	friend class ConstListIterator<T>;
	friend class BaseIterator<T>;

	using reference = T&;
	using const_reference = const T&;

	using value_type = T;
	using iterator = ListIterator<T>;
	using const_iterator = ConstListIterator<T>;
	using iterator_category = std::forward_iterator_tag;
	using Iterator = ListIterator<T>;
	using ConstIterator = ConstListIterator<T>;

	#pragma region struct_Node
	struct Node
	{
		friend class ListIterator<T>;
		friend class ConstListIterator<T>;
		friend class BaseIterator<T>;

		value_type data;
		std::shared_ptr<Node> next;

		Node() noexcept;
		Node(const Node& other) noexcept;
		Node(Node&& other) noexcept;
		explicit Node(T data) noexcept;
		~Node() = default;


		Node& operator=(const Node& other);
		Node& operator=(Node&& other) noexcept;

		reference GetData();
		const_reference GetData() const;
		void SetData(T data) noexcept;
		std::shared_ptr<Node> GetNext() const;
		void SetNext(std::shared_ptr<Node> next) noexcept;
		reference operator*();
	};
	#pragma endregion
	using pointer = std::shared_ptr<Node>;

private:
	pointer head;
	pointer tail;

protected:
	void PushNodeFront(pointer node);
	void PushNodeBack(pointer node);
	T& MyGet(int index);
	const T& MyGet(int index) const;

	#pragma region Exceptions
	void EmptyListCheck(const char *file, const char *function, int line) const;
	void IndexOutOfRangeCheck(const char *file, const char *function, int line, int index) const;
	void SliceCheck(const char *file, const char *function, int line, int start, int end) const;
	#pragma endregion
public:

	#pragma region Constructors

	List() noexcept = default;
	explicit List(const List<T>& other);
	template<Convertable_To<T> U>
	explicit List(const List<U>& other);

	List(List<T>&& other) noexcept;

	List(std::initializer_list<T> list);
	template<Convertable_To<T> U>
	List(std::initializer_list<U> list);


	template<ConvertableIterator<T> I>
	List(I begin, I end);

	template<ConvertableContainer<T> C>
	List(const C& container);

	~List() override = default;

	#pragma endregion

	#pragma region Iterators

	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;
	ConstIterator cbegin() const;
	ConstIterator cend() const;

	#pragma endregion

	#pragma region PushPop

	void PushFront(T data);
	void PushBack(T data);
	T& PopFront();
	T& PopBack();

//	void Remove(int index);
//	void Remove(int from, int to);

	void Remove(ListIterator<T>& begin, ListIterator<T>& end);


	#pragma endregion

	#pragma region GetSet

	T& Get(int index);
	const T& Get(int index) const;
	T& operator[](int index);
	const T& operator[](int index) const;
	void Set(int index, T& data);
	template<Convertable_To<T> U>
	void Set(int index, U& data);
	void Clear();

	#pragma endregion

	#pragma region Merge

	List<T>& Merge(const List<T>& other);
	List<T> Merge(const List<T>& other) const;

	template<Convertable_To<T> U>
	List<T>& Merge(const List<U>& other);

	template<Convertable_To<T> U>
	List<T> Merge(const List<U>& other) const;

	//Merge
	template<ConvertableIterator<T> I>
	List<T>& Merge(I begin, I end);

	template<ConvertableIterator<T> I>
	List<T> Merge(I begin, I end) const;

	template<ConvertableContainer<T> C>
	List<T>& Merge(const C& container);

	template<ConvertableContainer<T> C>
	List<T> Merge(const C& container) const;

	#pragma endregion

	#pragma region Insert

	void Insert(T data, int index);
	template<Convertable_To<T> U>
	void Insert(U data, int index);

	void Insert(const List<T>& other, int index); //Copy other list
	template<Convertable_To<T> U>
	void Insert(const List<U>& other, int index); //copy other list

	template<InputIterator I>
	requires requires(typename I::value_type t) { { t } -> std::convertible_to<T>;}
	void Insert(I begin, I end, int index);

	template<ConvertableContainer<T> C>
	void Insert(const C& container, int index);

	#pragma endregion

	//Insert от Merge отличается тем, что в инсерте выбирается куда вставлять, когда
	//в мерже всегда в конец.

	List<T> GetSlice(int start, int end) const;

	std::strong_ordering Compare(const List<T>& other) const;
	std::strong_ordering operator<=>(const List<T>& other) const;

	#pragma region Operators

	List<T>& operator=(const List<T>& other);
	template<Convertable_To<T> U>
	List<T>& operator=(const List<U>& other);
	template<ConvertableContainer<T> C>
	List<T>& operator=(const C& container);

	List<T>& operator=(List<T>&& other) noexcept;
	template<Convertable_To<T> U>
	List<T>& operator=(List<U>&& other) noexcept;

	List<T> operator+(const List<T>& other) const;
	template<Convertable_To<T> U>
	List<T> operator+(const List<U>& other) const;

	List<T>& operator+=(const List<T>& other);
	template<Convertable_To<T> U>
	List<T>& operator+=(const List<U>& other);
	template<ConvertableContainer<T> C>
	List<T>& operator+=(const C& container);

	template<RestrictedType Type>
	friend ostream& operator<<(ostream& os, List<Type>& list);

	#pragma endregion
};


//==================Realisation========================
#include "Implementation/Node.hpp"
#include "Implementation/ListConstructors.hpp"
#include "Implementation/ListMethods.hpp"
#include "Implementation/ListOperators.hpp"


#endif //LAB2_LIST_H

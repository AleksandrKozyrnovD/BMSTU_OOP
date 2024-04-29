//
// Created by aleksandr on 4/15/24.
//

#ifndef LAB2_TREE_H
#define LAB2_TREE_H

#include "../Base/Container.h"
#include <memory>
#include <iostream>


template<typename T>
class Node
{
private:
	T data;
	std::shared_ptr<Node<T>> left;
	std::shared_ptr<Node<T>> right;
public:
	Node() noexcept;
	Node(const Node<T>& other) noexcept;
	Node(Node<T>&& other) noexcept;
	explicit Node(T data) noexcept;

	~Node() noexcept = default;

	std::shared_ptr<Node<T>> GetLeft() const;
	std::shared_ptr<Node<T>> GetRight() const;

	T& GetData();
	const T& GetData() const;

	void SetLeft(std::shared_ptr<Node<T>> left);
	void SetRight(std::shared_ptr<Node<T>> right);

	void SetData(T data);
};

template<typename Type, typename Key>
class Tree : public Container
{
private:
	std::shared_ptr<Node<Type>> root;
public:
	Tree() noexcept;
	Tree(const Tree<Type, Key>& other) noexcept;
	Tree(Tree<Type, Key>&& other) noexcept;
	~Tree() noexcept = default;

	void Add(Type data, Key key);
	void Remove(Type data, Key key);
	Type& Find(Key key);
	const Type& Find(Key key) const;
};

#endif //LAB2_TREE_H

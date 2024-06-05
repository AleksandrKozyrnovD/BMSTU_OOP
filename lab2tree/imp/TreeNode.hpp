#ifndef _TREE_NODE_HPP_
#define _TREE_NODE_HPP_

#include <cmath>
#include <memory>

#include "../inc/Tree.h"

#define EPS __DBL_EPSILON__ // 2.2204460492503131e-16

template <Comparable Type>
shared_ptr<Type> Tree<Type>::TreeNode::allocateData()
{
	try
	{
		shared_ptr<value_type> new_ptr(new value_type);
		return new_ptr;
	}
	catch (bad_alloc &error)
	{
		time_t cur_time = time(NULL);
		throw MemoryException(ctime(&cur_time), __FILE__, __LINE__,
		                      typeid(*this).name(), __FUNCTION__);
	}
}

template <Comparable Type>
shared_ptr<typename Tree<Type>::TreeNode> Tree<Type>::TreeNode::allocateNode()
{
	try
	{
		shared_ptr<TreeNode> new_ptr(new TreeNode);
		return new_ptr;
	}
	catch (bad_alloc &error)
	{
		time_t cur_time = time(NULL);
		throw MemoryException(ctime(&cur_time), __FILE__, __LINE__,
		                      typeid(*this).name(), __FUNCTION__);
	}
}

template <Comparable Type>
Tree<Type>::TreeNode::TreeNode() {}

template <Comparable Type>
Tree<Type>::TreeNode::TreeNode(const Type &data)
{
	set(data);
}

template <Comparable Type>
Tree<Type>::TreeNode::TreeNode(Type &&data)
{
	set(data);
}

template <Comparable Type>
template <typename OtherType>
Tree<Type>::TreeNode::TreeNode(const OtherType &data)
{
	set(data);
}

//template <Comparable Type>
//template <typename OtherType>
//Tree<Type>::TreeNode::TreeNode(OtherType &&data)
//{
//	set(data);
//}

template <Comparable Type>
Tree<Type>::TreeNode::TreeNode(const TreeNode &other) = default;
template <Comparable Type>
Tree<Type>::TreeNode::TreeNode(TreeNode &&other) noexcept = default;

template <Comparable Type>
void Tree<Type>::TreeNode::set(const Type &data)
{
	data_ptr_ = allocateData();
	*data_ptr_ = data;
	empty_ = false;
}

//template <Comparable Type>
//void Tree<Type>::TreeNode::set(Type &&data)
//{
//	data_ptr_ = allocateData();
//	*data_ptr_ = data;
//	empty_ = false;
//}

//template <Comparable Type>
//template <typename OtherType>
//void Tree<Type>::TreeNode::set(const OtherType &data)
//{
//	data_ptr_ = allocateData();
//	*data_ptr_ = data;
//	empty_ = false;
//}

//template <Comparable Type>
//template <typename OtherType>
//void Tree<Type>::TreeNode::set(OtherType &&data)
//{
//	data_ptr_ = allocateData();
//	*data_ptr_ = data;
//	empty_ = false;
//}

template <Comparable Type>
bool Tree<Type>::TreeNode::isEmpty()
{
	return empty_;
}

template <Comparable Type>
void Tree<Type>::TreeNode::set_left(shared_ptr<TreeNode> next)
{
	left_ = next;
}


template <Comparable Type>
void Tree<Type>::TreeNode::set_right(shared_ptr<TreeNode> next)
{
	right_ = next;
}


template <Comparable Type>
shared_ptr<typename Tree<Type>::TreeNode> Tree<Type>::TreeNode::left()
{
	return left_;
}

template <Comparable Type>
shared_ptr<typename Tree<Type>::TreeNode> Tree<Type>::TreeNode::right()
{
	return right_;
}

//template <Comparable Type>
//const Type &Tree<Type>::TreeNode::getData() const
//{
//	return *data_ptr_;
//}

template <Comparable Type>
Type &Tree<Type>::TreeNode::getData()
{
	return *data_ptr_;
}

template <Comparable Type>
Tree<Type>::TreeNode &Tree<Type>::TreeNode::operator=(const TreeNode &other) = default;

template <Comparable Type>
Tree<Type>::TreeNode &Tree<Type>::TreeNode::operator=(TreeNode &&other) noexcept = default;

template <Comparable Type>
bool Tree<Type>::TreeNode::operator==(const TreeNode &other) const
{
	return this == addressof(other);
}

template <Comparable Type>
bool Tree<Type>::TreeNode::operator!=(const TreeNode &other) const
{
	return !(this == addressof(other));
}

template <Comparable Type>
Tree<Type>::TreeNode::~TreeNode() = default;

#endif // _TREE_NODE_HPP_
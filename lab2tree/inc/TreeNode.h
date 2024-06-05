#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

#include <memory>

#include "Tree.h"
#include "Iterator.h"
#include "Exceptions.h"
#include "Concepts.h"


using namespace std;

//template <Comparable Type>
//class Tree;

//template <Comparable Type>
//class TreeNode
//{
//
//	using value_type = Type;
//	friend class Tree<Type>;
//
//public:
//	template <typename U>
//	TreeNode(const U &data);
//
//
//	TreeNode(const TreeNode<value_type> &other);
//	TreeNode(TreeNode<value_type> &&other) noexcept;
//
//	shared_ptr<value_type> allocateData();
//	shared_ptr<TreeNode<value_type>> allocateNode();
//
//	bool isEmpty();
//
//	void set(const value_type &data)
//	{
//		data_ptr_ = allocateData();
//		*data_ptr_ = data;
//		empty_ = false;
//	}
//
//	template <typename U>
//	void set(const U &data);
//
//
//	void set_left(shared_ptr<TreeNode<value_type>> next);
//	void set_right(shared_ptr<TreeNode<value_type>> next);
//
//	shared_ptr<TreeNode<value_type>> left();
//	shared_ptr<TreeNode<value_type>> right();
//
//	const Type &getData() const
//	{
//		return *data_ptr_;
//	}
//	Type &getData()
//	{
//		return *data_ptr_;
//	}
//
//	TreeNode<value_type> &operator=(const TreeNode<value_type> &other);
//	TreeNode<value_type> &operator=(TreeNode<value_type> &&other) noexcept;
//
//	bool operator==(const TreeNode<value_type> &other) const;
//	bool operator!=(const TreeNode<value_type> &other) const;
//
//	~TreeNode();
//
//protected:
//	TreeNode();
//	explicit TreeNode(const value_type &data);
//	explicit TreeNode(value_type &&data);
//
//private:
//	shared_ptr<TreeNode<value_type>> left_ = nullptr;
//	shared_ptr<TreeNode<value_type>> right_ = nullptr;
//	bool empty_ = true;
//	shared_ptr<value_type> data_ptr_ = nullptr;
//};

#endif // _TREE_NODE_H_
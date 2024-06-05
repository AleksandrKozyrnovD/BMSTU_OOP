#ifndef _TREE_H_
#define _TREE_H_

#include "BaseContainer.h"
#include "../imp/Iterator.hpp"
#include "../imp/ConstIterator.hpp"
#include "Exceptions.h"
#include "Concepts.h"
//#include "../imp/TreeNode.hpp"
//#include "TreeNode.h"
#include <type_traits>
#include <ranges>


//template <Comparable Type>
//class TreeNode;

using namespace std;

template <Comparable Type>
class Tree : public BaseContainer
{
	friend class Iterator<Type>;
	friend class ConstIterator<Type>;

	using value_type = Type;
	using iterator = ConstIterator<value_type>;
	using const_iterator = ConstIterator<Type>;

//	using node = TreeNode;

public:
	#pragma region Constructors

	Tree();
	~Tree();


	explicit Tree(const Tree<value_type> &tree);
	template <Convertable_To<Type> OtherType>
	explicit Tree(const Tree<OtherType> &tree);

	template<std::ranges::input_range Range>
	explicit Tree(Range&& range);

	Tree(const size_t sizeValue, const value_type *arr);
	template <Convertable_To<Type> OtherType>
	Tree(const size_t sizeValue, const OtherType *arr);

	Tree(const initializer_list<value_type> elements);
	template <Convertable_To<Type> OtherType>
	Tree(const initializer_list<OtherType> elements);

	Tree(Tree<value_type> &&tree) noexcept;

//	Tree(iterator begin, iterator end);
	template <InputIterator I>
	requires requires(typename I::value_type t) {{ t } -> convertible_to<Type>; }
	Tree(I begin, I end);

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	explicit Tree(const Cont &container);


	#pragma endregion Constructors

	bool Delete(const value_type &data);
	bool Insert(const value_type &data);
	const_iterator Find(const value_type &data) const;
	void Intersection(const Tree<Type> &tree);

//	template<std::ranges::input_range Range>
//	void Intersection(Range&& range);

	template<std::ranges::input_range Range>
	requires requires(typename Range::value_type t)  {{ t }  -> convertible_to<Type>;  }
	void Intersection(Range&& range);

	Tree<Type> operator&(const Tree<Type> &tree) const;
	Tree<Type> &operator&=(const Tree<Type> &tree);
	template<std::ranges::input_range Range>
	requires requires(typename Range::value_type t)   {{ t }   -> convertible_to<Type>;   }
	Tree<Type>  operator&(const Range &range) const;
	template<std::ranges::input_range Range>
	requires requires(typename Range::value_type t)   {{ t }   -> convertible_to<Type>;   }
	Tree<Type>  operator&=(const Range &range);

	template <Convertable_To<Type> OtherType>
	bool Insert(const OtherType &data);


	#pragma region Iterators
	const_iterator begin() noexcept;
	const_iterator end() noexcept;

	const_iterator begin() const noexcept;
	const_iterator end() const noexcept;
	const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;

	#pragma endregion Iterators

	#pragma region Operations

	#pragma region Assignments
	Tree<value_type> &operator=(const initializer_list<value_type> elements);
	template <Convertable_To<Type> OtherType>
	Tree<value_type> &operator=(const initializer_list<OtherType> elements);

	Tree<value_type> &operator=(const Tree<value_type> &tree);
	template <Convertable_To<Type> OtherType>
	Tree<value_type> &operator=(const Tree<OtherType> &tree);

	Tree<value_type> &operator=(Tree<value_type> &&tree) noexcept;
	template <Convertable_To<Type> OtherType>
	Tree<value_type> &operator=(Tree<OtherType> &&tree) noexcept;

	template <ContainerComparable Cont>
	Tree<value_type> &operator=(const Cont &container);
	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<value_type> &operator=(const Cont &container);

	#pragma endregion Assignments

	#pragma region Comparsions
	bool isEqual(const Tree<value_type> &tree) const;
	bool operator==(const Tree<value_type> &tree) const;
	bool isNotEqual(const Tree<value_type> &tree) const;
	bool operator!=(const Tree<value_type> &tree) const;
	template <Convertable_To<Type> OtherType>
	bool IsEquivalent(const Tree<common_type_t<Type, OtherType>>& tree) const;
	template <Convertable_To<Type> OtherType>
	bool IsNotEquivalent(const Tree<common_type_t<Type, OtherType>>& tree) const;
	#pragma endregion Comparsions

	#pragma region Indexations
	const value_type &operator[](const size_t index) const;
	#pragma endregion Indexations

	#pragma region Add
	Tree<value_type> Add(const Tree<value_type> &tree) const;
	Tree<value_type> operator+(const Tree<value_type> &tree) const;

	template <Convertable_To<Type> OtherType>
	Tree<value_type> Add(const Tree<OtherType> &tree) const;
	template <Convertable_To<Type> OtherType>
	Tree<value_type> operator+(const Tree<OtherType> &tree) const;

	template<Convertable_To<Type> OtherType>
	Tree<common_type_t<Type, OtherType>> CopyAdd(const Tree<OtherType>  &tree) const;

	Tree<value_type> Add(const Type &num) const;
	Tree<value_type> operator+(const Type &num) const;

	template <Convertable_To<Type> OtherType>
	Tree<value_type> Add(const OtherType &num) const;
	template <Convertable_To<Type> OtherType>
	Tree<value_type> operator+(const OtherType &num) const;

	template <Convertable_To<Type> OtherType>
	Tree<common_type_t<Type, OtherType>> CopyAdd(const OtherType &num) const;

	Tree<Type> &EqAdd(const Tree<Type> &tree);
	Tree<Type> &operator+=(const Tree<Type> &tree);

	template <Convertable_To<Type> OtherType>
	Tree<Type> &EqAdd(const Tree<OtherType> &tree);
	template <Convertable_To<Type> OtherType>
	Tree<Type> &operator+=(const Tree<OtherType> &tree);

	Tree<Type> &EqAdd(const Type &num);
	Tree<Type> &operator+=(const Type &num);

	template <Convertable_To<Type> OtherType>
	Tree<Type> &EqAdd(const OtherType &num);
	template <Convertable_To<Type> OtherType>
	Tree<Type> &operator+=(const OtherType &num);


	Tree<Type> Add(const size_t sizeValue, const value_type *arr) const;
	Tree<Type> Add(const initializer_list<value_type> elements) const;

//	Tree<Type> Add(iterator begin, iterator end) const;

	template <InputIterator I>
	requires requires(typename I::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> Add(I begin, I end) const;

	template <InputIterator I>
	requires requires(typename I::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<common_type_t<Type, typename I::value_type>> CopyAdd(I begin, I end) const;

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> Add(const Cont &container) const;

	Tree<Type> operator+(const initializer_list<value_type> elements) const;
	Tree<Type> operator+(Tree<value_type> &&tree) const;

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> operator+(const Cont &container) const;

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<common_type_t<Type, typename Cont::value_type>> CopyAdd(const Cont  &container);

	Tree<Type> &EqAdd(const size_t sizeValue, const value_type *arr);
	Tree<Type> &EqAdd(const initializer_list<value_type> elements);

	Tree<Type> &EqAdd(iterator begin, iterator end);

	template <InputIterator I>
	requires requires(typename I::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> &EqAdd(I begin, I end);

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> &EqAdd(const Cont &container);

	Tree<Type> &operator+=(const initializer_list<value_type> elements);
//	Tree<Type> &operator+=(Tree<value_type> &&tree);

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> &operator+=(const Cont &container);

	template <Convertable_To<Type> OtherType>
	Tree<Type> Add(const size_t sizeValue, const OtherType *arr) const;

	template <Convertable_To<Type> OtherType>
	Tree<Type> Add(const initializer_list<OtherType> elements) const;

	template <Convertable_To<Type> OtherType>
	Tree<common_type_t<Type, OtherType>> CopyAdd(const initializer_list<OtherType> elements) const;

	template <Convertable_To<Type> OtherType>
	Tree<Type> Add(Iterator<OtherType> begin, Iterator<OtherType> end) const;

	template <Convertable_To<Type> OtherType>
	Tree<Type> operator+(const initializer_list<OtherType> elements) const;

	template <Convertable_To<Type> OtherType>
	Tree<Type> operator+(Tree<OtherType> &&tree) const;

	template <Convertable_To<Type> OtherType>
	Tree<Type> &EqAdd(const size_t sizeValue, const OtherType *arr);

	template <Convertable_To<Type> OtherType>
	Tree<Type> &EqAdd(const initializer_list<OtherType> elements);


	template <Convertable_To<Type> OtherType>
	Tree<Type> &EqAdd(Iterator<OtherType> begin, Iterator<OtherType> end);

	template <Convertable_To<Type> OtherType>
	Tree<Type> &operator+=(const initializer_list<OtherType> elements);


	#pragma endregion Add

	#pragma region Remove
	Tree<Type> Remove(const Tree<Type> &tree) const;
	Tree<Type> operator-(const Tree<Type> &tree) const;

	Tree<Type> Remove(const Type &num) const;
	Tree<Type> operator-(const Type &num) const;

	Tree<Type> &EqRemove(const Tree<Type> &tree);
	Tree<Type> &operator-=(const Tree<Type> &tree);

	Tree<Type> &EqRemove(const Type &num);
	Tree<Type> &operator-=(const Type &num);

	Tree<Type> Remove(const size_t sizeValue, const value_type *arr) const;
	Tree<Type> Remove(const initializer_list<value_type> elements) const;

//	Tree<Type> Remove(iterator begin, iterator end) const;

	template <InputIterator I>
	requires requires(typename I::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> Remove(I begin, I end) const;

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> Remove(const Cont &container) const;

	Tree<Type> operator-(const initializer_list<value_type> elements) const;
	Tree<Type> operator-(Tree<value_type> &&tree) const;

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> operator-(const Cont &container) const;

	Tree<Type> &EqRemove(const size_t sizeValue, const value_type *arr);
	Tree<Type> &EqRemove(const initializer_list<value_type> elements);
	Tree<Type> &EqRemove(Tree<value_type> &&tree);

	Tree<Type> &EqRemove(iterator begin, iterator end);

	template <InputIterator I>
	requires requires(typename I::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> &EqRemove(I begin, I end);

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> &EqRemove(const Cont &container);

	Tree<Type> &operator-=(const initializer_list<value_type> elements);

	template <ContainerComparable Cont>
	requires requires(typename Cont::value_type t) {{ t } -> convertible_to<Type>; }
	Tree<Type> &operator-=(const Cont &container);

	#pragma endregion Remove

	bool IsRootEmpty() { return root_->isEmpty();}
//	std::shared_ptr<TreeNode<Type>> root() {return root_;};

	#pragma endregion Operations

protected:
	class TreeNode
	{

		using value_type = Type;
		friend class Tree<Type>;

	public:
		template <typename U>
		TreeNode(const U &data);


		TreeNode(const TreeNode &other);
		TreeNode(TreeNode &&other) noexcept;

		shared_ptr<value_type> allocateData();
		shared_ptr<TreeNode> allocateNode();

		bool isEmpty();

		void set(const value_type &data);

		template <typename U>
		void set(const U &data);


		void set_left(shared_ptr<TreeNode> next);
		void set_right(shared_ptr<TreeNode> next);

		shared_ptr<TreeNode> left();
		shared_ptr<TreeNode> right();

		const Type &getData() const;
		Type &getData();

		TreeNode &operator=(const TreeNode &other);
		TreeNode &operator=(TreeNode &&other) noexcept;

		bool operator==(const TreeNode &other) const;
		bool operator!=(const TreeNode &other) const;

		~TreeNode();

	public:
		TreeNode();
		explicit TreeNode(const value_type &data);
		explicit TreeNode(value_type &&data);

	private:
		shared_ptr<TreeNode> left_ = nullptr;
		shared_ptr<TreeNode> right_ = nullptr;
		bool empty_ = true;
		shared_ptr<value_type> data_ptr_ = nullptr;
	};


	void allocateRoot();

	#pragma region Checks
	void zeroSizeCheck(const size_t line) const;
	void indexCheck(const size_t index, const size_t line) const;
	template <typename OtherType>
	void sizesCheck(const Tree<OtherType> &tree, const size_t line) const;
	template <typename OtherType>
	void divisionByZeroCheck(const OtherType &num, const size_t line) const;
	#pragma endregion Checks

private:
	std::shared_ptr<TreeNode> root_ = nullptr;
};

#include "../imp/Tree.hpp"
#include "../imp/TreeNode.hpp"

#endif
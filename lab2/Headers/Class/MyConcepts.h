//
// Created by aleksandr on 4/17/24.
//

#ifndef LAB2_MYCONCEPTS_H
#define LAB2_MYCONCEPTS_H

#include <memory>

template<typename Type>
concept HasCopyConstructor = requires(Type a)
{
	Type(a);
};

template<typename Type>
concept HasMoveConstructor = requires(Type a)
{
	Type(std::move(a));
};

template<typename Type>
concept HasAssignmentOperator = requires(Type a)
{
	a = a;
};




template <typename I>
concept Iterator = requires()
{
	typename I::value_type;
	typename I::difference_type;
	typename I::pointer;
	typename I::reference;
};

template <typename T, typename U>
concept DerivedFrom = std::is_base_of<U, T>::value;

template<typename T>
concept EqualityComparable = requires(T a, T b)
{
	{ a == b } -> std::same_as<bool>;
	{ a != b } -> std::same_as<bool>;
};

template <typename I>
concept InputIterator = Iterator<I> &&
                        requires { typename I::iterator_category; } &&
                        EqualityComparable<I> &&
                        DerivedFrom<typename I::iterator_category, std::input_iterator_tag>;

template <typename I>
concept IterIncrementable = requires(I it)
{
	{ ++it } -> std::same_as<I&>;
	{ it++ } -> std::same_as<I>;
};

//template <typename I>
//concept ForwardIterator = InputIterator<I> &&
//                          IterIncrementable<I> &&
//                          DerivedFrom<typename I::iterator_category, forward_iterator_tag>;

template<typename C>
concept ContainerConcept = requires(C c)
{
	typename C::value_type;
	typename C::size_type;
	typename C::iterator;
	typename C::const_iterator;

	{ c.size() } noexcept -> std::same_as<typename C::size_type>;
	{ c.begin() } -> std::same_as<typename C::iterator>;
	{ c.end() } -> std::same_as<typename C::iterator>;
};

template<typename Type>
concept RestrictedType = HasCopyConstructor<Type> && HasMoveConstructor<Type> && HasAssignmentOperator<Type>;// && !ForwardIterator<Type>;

template <typename OtherType, typename Type>
concept Convertable_To = std::convertible_to<OtherType, Type>;

template<typename C, typename Type>
concept ConvertableContainer = ContainerConcept<C> && std::convertible_to<typename C::value_type, Type>;

template<typename I, typename T>
concept ConvertableIterator = InputIterator<I> && std::convertible_to<typename I::value_type, T>;

#endif //LAB2_MYCONCEPTS_H

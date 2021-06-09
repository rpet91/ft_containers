/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TypeTraits.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 13:06:40 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/09 14:30:27 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETRAITS_HPP
# define TYPETRAITS_HPP

namespace ft
{
	// Iterator tags
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// Enable if
	template < bool B, typename T = void >
	struct enable_if
	{
	};

	template < typename T >
	struct enable_if<true, T>
	{
		typedef T	type;
	};

	template < class T >
	class is_iterator
	{
		private:
			typedef char	one;
			typedef int		two;

			template < typename C >
				static one	test(typename C::iterator_category* = 0);
			template < typename C >
				static two	test(...);

		public:
			static const bool result = sizeof(one) == sizeof(test<T>(0));
	};

	template < class T >
	struct iterator_traits : public enable_if<is_iterator<T>::result, T>
	{
	};

	template < class T >
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag	type;
	};
	
	template < class T >
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag	type;
	};
}
#endif









/*	// InputIterator
	template < typename T >
	struct is_iterator
	{
		public:
			bool	value = (sizeof(;
	};

	template < typename T >
	struct check_iterator : public enable_if<is_iterator<T>::value, T>
	{
	};

	template < typename T >
	struct check_iterator<T*>
	{
		typedef	random_access_iterator_tag	type;
	};
	
}

#endif*/

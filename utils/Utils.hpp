/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/23 13:18:56 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/26 14:10:53 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "TypeTraits.hpp"
# include <cstddef>

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct less : binary_function <T,T,bool>
	{
		bool	operator()(const T& x, const T& y) const
		{
			return (x < y);
		}
	};
	
	template <typename T>
	bool	isEqual(T const &first, T const &second)
	{
		return (first == second);
	}
	
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class T>
	void	swap(T &a, T &b)
	{
		T	c(a);

		a = b;
		b = c;
	}

	template <class InputIt1, class InputIt2>
	bool	 lexicographical_compare(InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<class It>
	typename ft::iterator_traits<It>::difference_type
	do_distance(It first, It last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<It>::difference_type result = 0;

		while (first != last)
		{
			++first;
			++result;
		}
		return (result);
	}
	
	template<class It>
	typename ft::iterator_traits<It>::difference_type
	do_distance(It first, It last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <class It>
	typename ft::iterator_traits<It>::difference_type
	distance(It first, It last)
	{
		return (ft::do_distance(first, last, typename ft::iterator_traits<It>::iterator_category()));
	}
}

#endif

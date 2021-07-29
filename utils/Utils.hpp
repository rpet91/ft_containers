/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/23 13:18:56 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/29 09:18:08 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "TypeTraits.hpp"
# include <cstddef>

namespace ft
{
	template <typename T>
	bool	less(T const &first, T const &second)
	{
		return (first < second);
	}
	
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

	template <class InputIterator1, class InputIterator2>
	bool	 lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, InputIterator2 last2)
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

	template <class InputIterator>
	ptrdiff_t	distance(InputIterator first, InputIterator last)
	{
		ptrdiff_t	size = 0;

		while (first != last)
		{
			first++;
			size++;
		}
		return (size);
	}
}

#endif

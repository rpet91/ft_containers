/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:37:40 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/27 13:22:34 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template < class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T& >
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_tye;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
	class Iterator {
		public:
			Iterator()
			{
			}
			virtual ~Iterator()
			{
			}
			Iterator(ListIterator const &src)
			{
				*this = src;
			}
			Iterator    &operator=(ListIterator const &src)
			{
				(void) src;
				return (*this);
			}
	};
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:37:40 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/26 14:18:09 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>

namespace ft
{
	template < class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T& >
	class Iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;

			Iterator() : _ptr(0)
			{
			}

			Iterator(pointer ptr) : _ptr(ptr)
			{
			}

			virtual ~Iterator()
			{
			}

			Iterator(Iterator const &src)
			{
				*this = src;
			}

			Iterator    &operator=(Iterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}

		protected:
			pointer		_ptr;
	};
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:55:49 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/28 11:14:41 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "Iterator.hpp"
# include "TypeTraits.hpp"
# include <iostream>

namespace ft
{
	template < class T, class Pointer, class Reference,
			 class Category = ft::bidirectional_iterator_tag >
	class BidirectionalIterator : public Iterator< Category, T >
	{
		typedef Iterator<Category, T>							base_iterator;
		typedef BidirectionalIterator<T, const T*, const T&>	const_iterator;
		typedef BidirectionalIterator<T, T*, T&>				iterator;
		typedef T*												pointer;
		typedef T&												reference;

		public:
			BidirectionalIterator() : base_iterator()
			{
			}

			BidirectionalIterator(T *ptr) : base_iterator(ptr)
			{
			}

			virtual ~BidirectionalIterator()
			{
			}

			BidirectionalIterator(BidirectionalIterator const &src)
			{
				*this = src;
			}

			iterator	&operator=(iterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}

/*			iterator	&operator++()
			{
				std::cout << "++ operator" << std::endl;
				++*this;
				return (*this);
			}

			iterator	operator++(int)
			{
				std::cout << "++ int operator" << std::endl;
				iterator	old = *this;
			
				++*this;
				return (old);
			}

			iterator	&operator--()
			{
				std::cout << "-- operator" << std::endl;
				--*this;
				return (*this);
			}

			iterator	operator--(int)
			{
				std::cout << "-- int operator" << std::endl;
				iterator	old = *this;

				--*this;
				return (old);
			}*/

			operator	const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}
	};
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:55:49 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/21 09:35:32 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "Iterator.hpp"
# include "TypeTraits.hpp"

namespace ft
{
	template < typename T >
	class BidirectionalIterator : public Iterator< ft::bidirectional_iterator_tag, T >
	{
		typedef Iterator< ft::bidirectional_iterator_tag, T >	base_iterator;
		typedef BidirectionalIterator							iterator;

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

			iterator	&operator++()
			{
				++*this;
				return (*this);
			}

			iterator	operator++(int)
			{
				iterator	old = *this;
			
				++*this;
				return (old);
			}

			iterator	&operator--()
			{
				--*this;
				return (*this);
			}

			iterator	operator--(int)
			{
				iterator	old = *this;

				--*this;
				return (old);
			}

	};
}

#endif

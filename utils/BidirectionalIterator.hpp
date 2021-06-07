/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:55:49 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/07 13:07:40 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "Iterator.hpp"
# include "Category.hpp"

namespace ft
{
	template < typename T >
	class BidirectionalIterator : public Iterator< ft::bidirectional_iterator_tag, T >
	{
		public:
			BidirectionalIterator()
			{
			}
			virtual ~BidirectionalIterator()
			{
			}
			BidirectionalIterator(BidirectionalIterator const &src)
			{
				*this = src;
			}
			BidirectionalIterator	&operator=(BidirectionalIterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}
			BidirectionalIterator	&operator++()
			{
				this->_current = this->_current->next;
				return (*this);
			}
			BidirectionalIterator	operator++(int)
			{
				this->_current = this->_current->prev;
				return (*this);
			}
			BidirectionalIterator	&operator--()
			{
				this->_current = this->_current->next;
				return (*this);
			}
			BidirectionalIterator	operator--(int)
			{
				this->_current = this->_current->prev;
				return (*this);
			}
	};
}

#endif

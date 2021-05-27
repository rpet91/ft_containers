/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:55:49 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/27 14:23:45 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "Iterator.hpp"

namespace ft
{
	template < typename T >
	class BidirectionalIterator : public Iterator {
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
				(void) src;
				return (*this);
			}
			BidirectionalIterator	&operator++()
			{
				this->_current = this->_current->next;
				return (*this);
			}
			BidirectionalIterator	&operator--()
			{
				this->_current = this->_current->prev;
				return (*this);
			}
	};
}

#endif

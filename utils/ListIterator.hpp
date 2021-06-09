/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/09 12:56:12 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP
# include "ListNode.hpp"
# include "BidirectionalIterator.hpp"

namespace ft
{
	template < typename Node, typename T >
	class ListIterator : public BidirectionalIterator< Node >
	{
		typedef ListIterator					iterator;
		typedef	BidirectionalIterator< Node > 	bidirectional_iterator;

		public:
			ListIterator() : bidirectional_iterator()
			{
			}
			ListIterator(Node *ptr) : bidirectional_iterator(ptr)
			{
			}
			virtual ~ListIterator()
			{
			}
			ListIterator(ListIterator const &src)
			{
				*this = src;
			}
			iterator	&operator=(iterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}
			T				&operator*()
			{
				return (this->_ptr->data);
			}
			iterator	&operator++()
			{
				this->_ptr = this->_ptr->next;
				return (*this);
			}
			iterator	operator++(int)
			{
				iterator	old = *this;

				this->_ptr = this->_ptr->next;
				return (old);
			}
			iterator	&operator--()
			{
				this->_ptr = this->_ptr->prev;
				return (*this);
			}
			iterator	operator--(int)
			{
				iterator	old = *this;

				this->_ptr = this->_ptr->prev;
				return (old);
			}
			bool			operator==(iterator const &src) const
			{
				return (this->_ptr == src._ptr);
			}
			bool			operator!=(iterator const &src) const
			{
				return (this->_ptr != src._ptr);
			}
	};
}

#endif

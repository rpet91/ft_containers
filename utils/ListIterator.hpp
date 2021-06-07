/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/07 13:41:43 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP
# include "ListNode.hpp"
# include "BidirectionalIterator.hpp"
# include "Category.hpp"
# include <iostream> //joejoe

namespace ft
{
	template < typename T >
	class ListIterator : public BidirectionalIterator< ft::bidirectional_iterator_tag >
	{
		public:
			ListIterator() : _current(0)
			{
			}
			ListIterator(ListNode<T> *node) : _current(node)
			{
			}
			virtual ~ListIterator()
			{
			}
			ListIterator(ListIterator const &src)
			{
				*this = src;
			}
			ListIterator	&operator=(ListIterator const &src)
			{
				this->_current = src._current;
				return (*this);
			}
			T				&operator*()
			{
				return (this->_current->data);
			}
			ListIterator	&operator++()
			{
				this->_current = this->_current->next;
				return (*this);
			}
			ListIterator	operator++(int)
			{
				this->_current = this->_current->next;
				return (*this);
			}
			ListIterator	&operator--()
			{
				this->_current = this->_current->prev;
				return (*this);
			}
			ListIterator	operator--(int)
			{
				this->_current = this->_current->prev;
				return (*this);
			}
			bool			operator==(ListIterator const &src) const
			{
				return (this->_current == src._current);
			}
			bool			operator!=(ListIterator const &src) const
			{
				return (this->_current != src._current);
			}

			ListNode<T>		*_current;
	};
}

#endif

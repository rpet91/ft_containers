/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/27 13:08:01 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP
# include "BidirectionalIterator.hpp"
# include "ListNode.hpp"

namespace ft
{
	template < typename T >
	class ListIterator : public BidirectionalIterator {
		public:
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
			ListIterator	&operator--()
			{
				this->_current = this->_current->prev;
				return (*this);
			}

		private:
			ListIterator()
			{
			}

			ListNode<T>		*_current;
	};
}

#endif

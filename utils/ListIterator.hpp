/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/01 13:48:39 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP
# include "ListNode.hpp"
# include "BidirectionalIterator.hpp"
# include <cstddef>

namespace ft
{
	template < class Node, class T, class Pointer = T*, class Reference = T&>
	class ListIterator : public BidirectionalIterator< Node, Node*, Node& >
	{
		public:
			typedef ListIterator<Node, T>						iterator;
			typedef ListIterator<const Node, const T>			const_iterator;
			typedef	BidirectionalIterator<Node, Node*, Node&> 	bidirectional_iterator;
			typedef ptrdiff_t									size_type;
			typedef T*											pointer;
			typedef T&											reference;

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

			reference	operator*()
			{
				return (this->_ptr->data);
			}
			
			pointer		operator->()
			{
				return (&this->_ptr->data);
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

			operator	const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}
	};
}

#endif

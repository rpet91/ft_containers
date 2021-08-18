/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   NodeIterator.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/18 13:51:30 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODEITERATOR_HPP
# define NODEITERATOR_HPP
# include "ListNode.hpp"
# include "MapNode.hpp"
# include "BidirectionalIterator.hpp"
# include <cstddef>

namespace ft
{
	template < class Node, class T, class Pointer = T*, class Reference = T&>
	class NodeIterator : public BidirectionalIterator< Node, Node*, Node& >
	{
		public:
			typedef NodeIterator<Node, T>						iterator;
			typedef NodeIterator<const Node, const T>			const_iterator;
			typedef	BidirectionalIterator<Node, Node*, Node&> 	bidirectional_iterator;
			typedef ptrdiff_t									difference_type;
			typedef T*											pointer;
			typedef T&											reference;

		public:
			NodeIterator() : bidirectional_iterator()
			{
			}

			NodeIterator(Node *ptr) : bidirectional_iterator(ptr)
			{
			}

			virtual ~NodeIterator()
			{
			}

			NodeIterator(NodeIterator const &src)
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
				return &(this->_ptr->data);
			}

			NodeIterator	&operator++()
			{
				this->_ptr = this->_ptr->nextNode();
				return (*this);
			}

			NodeIterator	operator++(int)
			{
				NodeIterator	old = *this;

				this->_ptr = this->_ptr->nextNode();
				return (old);
			}

			NodeIterator	&operator--()
			{
				this->_ptr = this->_ptr->prevNode();
				return (*this);
			}

			NodeIterator	operator--(int)
			{
				NodeIterator	old = *this;

				this->_ptr = this->_ptr->prevNode();
				return (old);
			}

			operator	const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}
	};
}

#endif

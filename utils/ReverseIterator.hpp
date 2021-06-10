/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReverseIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/10 14:43:25 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft
{
	template < typename Node<T>, typename T >
	class ReverseIterator 
	{
		typedef ReverseIterator					iterator;

		public:
			ReverseIterator()
			{
			}
			ReverseIterator(Node *ptr)
			{
			}
			virtual ~ReverseIterator()
			{
			}
			ReverseIterator(ReverseIterator const &src)
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
		
		private:
i			iterator	_
	};
}

#endif

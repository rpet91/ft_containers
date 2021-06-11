/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReverseIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/11 11:43:52 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft
{
	template < class Iterator >
	class ReverseIterator
	{
		typedef ReverseIterator							iterator;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::size_type			size_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;

		public:
			ReverseIterator() : _current()
			{
			}
			ReverseIterator(Iterator iterator_type) : _current(iterator_type)
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
				this->_current = src._current;
				return (*this);
			}
			iterator	&operator*() const
			{
				iterator	tmp = this->_current;

				return (*--tmp);
			}
			iterator	*operator->() const
			{
				iterator	tmp = this->_current;

				return (&--tmp);
			}
			iterator	&operator++()
			{
				--this->_current;
				return (*this);
			}
			iterator	operator++(int)
			{
				iterator	old = *this;

				--this->_current;
				return (old);
			}
			iterator	&operator--()
			{
				++this->_current;
				return (*this);
			}
			iterator	operator--(int)
			{
				iterator	old = *this;

				++this->_current;
				return (old);
			}
			iterator	operator[](difference_type n) const
			{
				return (*(*this + n));
			}
			iterator	operator+(difference_type n) const
			{
				return (this->_current - n);
			}
			iterator	operator-(difference_type n) const
			{
				return (this->_current + n);
			}
			iterator	&operator+=(difference_type n)
			{
				this->_current -= n;
				return (*this);
			}
			iterator	&operator-=(difference_type n)
			{
				this->_current += n;
				return (*this);
			}

		private:
			Iterator	_current;
	};
}

#endif
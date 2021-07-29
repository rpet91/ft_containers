/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReverseIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 09:01:07 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/28 09:23:34 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP
# include "TypeTraits.hpp"

namespace ft
{
	template < class Iterator >
	class ReverseIterator
	{
		public:
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::const_iterator		const_type;
			typedef Iterator								iterator_type;
			typedef ReverseIterator<iterator_type>			iterator;
			typedef ReverseIterator<const_type>				const_iterator;
		
		private:
			iterator_type	_current;

		public:
			ReverseIterator() : _current()
			{
			}

			ReverseIterator(iterator_type iter) : _current(iter)
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

			iterator_type	base() const
			{
				return (this->_current);
			}

			reference	operator*() const
			{
				iterator_type	tmp = this->_current;

				return (*--tmp);
			}

			pointer		operator->() const
			{
				return (&(operator*()));
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

			reference	operator[](difference_type n) const
			{
				return (base()[-n - 1]);
			}

			ReverseIterator	operator+(difference_type n) const
			{
				return (this->_current - n);
			}

			ReverseIterator	operator-(difference_type n) const
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

			operator	const_iterator() const
			{
				return (const_iterator(this->_current));
			}
	};

	template <class Iter1, class Iter2>
	bool operator==(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iter1, class Iter2>
	bool operator!=(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iter1, class Iter2>
	bool operator<(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iter1, class Iter2>
	bool operator<=(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iter1, class Iter2>
	bool operator>(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iter1, class Iter2>
	bool operator>=(const ReverseIterator<Iter1>& lhs, const ReverseIterator<Iter2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	// n + a
	template <class Iterator>
	ReverseIterator<Iterator>	operator+(typename ReverseIterator<Iterator>::difference_type n, const ReverseIterator<Iterator> &rev_it)
	{
		return (rev_it + n);
	}

	// a - b
	template <class Iterator1, class Iterator2>
	typename ReverseIterator<Iterator1>::difference_type
	operator-(const ReverseIterator<Iterator1> &lhs, const ReverseIterator<Iterator2> &rhs)
	{
		return (rhs.base() - lhs.base());
	}	
}

#endif

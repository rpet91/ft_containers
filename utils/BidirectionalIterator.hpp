/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:55:49 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/01 13:42:12 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "Iterator.hpp"
# include "TypeTraits.hpp"
# include <iostream> //weg

namespace ft
{
	template < class T, class Pointer, class Reference,
			 class Category = ft::bidirectional_iterator_tag >
	class BidirectionalIterator : public Iterator< Category, T >
	{
		typedef Iterator<Category, T>							base_iterator;
		typedef BidirectionalIterator<T, T*, T&>				iterator;
		typedef T*												pointer;
		typedef T&												reference;

		public:
			BidirectionalIterator() : base_iterator()
			{
			}

			BidirectionalIterator(T *ptr) : base_iterator(ptr)
			{
			}

			virtual ~BidirectionalIterator()
			{
			}

			BidirectionalIterator(BidirectionalIterator const &src)
			{
				*this = src;
			}

			iterator	&operator=(iterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}

			// *a
			reference	operator*()
			{
				return (*this->_ptr);
			}

			// a->m
			pointer		operator->()
			{
				return (&(*this->_prt));
			}

			// ++a
			iterator	&operator++()
			{
				++*this;
				return (*this);
			}

			// a++
			iterator	operator++(int)
			{
				iterator	old = *this;
			
				++*this;
				return (old);
			}

			// --a
			iterator	&operator--()
			{
				--*this;
				return (*this);
			}

			// a--
			iterator	operator--(int)
			{
				iterator	old = *this;

				--*this;
				return (old);
			}

			// friend declaration
			template < class T1, class T2 >
			friend bool operator==(BidirectionalIterator< T1, T1*, T1& > const &lhs, BidirectionalIterator< T2, T2*, T2& > const &rhs);

	};

	// a == b
	template <class T1, class T2>
	bool operator==(BidirectionalIterator< T1, T1*, T1& > const &lhs,
			BidirectionalIterator< T2, T2*, T2& > const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	
	// a != b
	template <class T1, class T2>
	bool operator!=(BidirectionalIterator< T1, T1*, T1& > const &lhs,
			BidirectionalIterator< T2, T2*, T2& > const &rhs)
	{
		return (!(lhs == rhs));
	}
}

#endif

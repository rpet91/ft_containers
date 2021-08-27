/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 12:55:49 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/26 14:15:32 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP
# include "Iterator.hpp"
# include "TypeTraits.hpp"
# include <cstddef>

namespace ft
{
	template < class T, class Pointer, class Reference,
			 class Category = ft::bidirectional_iterator_tag >
	class BidirectionalIterator : public Iterator< Category, T >
	{
		public:
			typedef Iterator<Category, T>							base_iterator;
			typedef BidirectionalIterator<T, T*, T&>				iterator;
			typedef BidirectionalIterator<T, const T*, const T&>	const_iterator;
			typedef ptrdiff_t										difference_type;
			typedef T*												pointer;
			typedef T&												reference;
			typedef Category										iterator_category;

		public:
			BidirectionalIterator() : base_iterator()
			{
			}

			BidirectionalIterator(pointer ptr) : base_iterator(ptr)
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
			
			// a == b
			bool		operator==(iterator const &src)
			{
				return (this->_ptr == src._ptr);
			}
			
			// a != b
			bool		operator!=(iterator const &src)
			{
				return !(*this == src);
			}

			// *a
			reference	operator*() const
			{
				return (*this->_ptr);
			}

			// a->m
			pointer		operator->() const
			{
				return (&(*this->_ptr));
			}

			// ++a
			iterator	&operator++()
			{
				this->_ptr++;
				return (*this);
			}

			// a++
			iterator	operator++(int)
			{
				iterator	old = *this;
			
				this->_ptr++;
				return (old);
			}

			// --a
			iterator	&operator--()
			{
				this->_ptr--;
				return (*this);
			}

			// a--
			iterator	operator--(int)
			{
				iterator	old = *this;

				this->_ptr--;
				return (old);
			}

			// friend declaration for ==
			template <class T1, class T2, class T3>
			friend bool operator==(BidirectionalIterator< T1, T2*, T2& > const &lhs, BidirectionalIterator< T1, T3*, T3& > const &rhs);
	};

	// a == b
	template <class T1, class T2, class T3>
	bool operator==(BidirectionalIterator< T1, T2*, T2& > const &lhs,
			BidirectionalIterator< T1, T3*, T3& > const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	
	// a != b
	template <class T1, class T2, class T3>
	bool operator!=(BidirectionalIterator< T1, T2*, T2& > const &lhs,
			BidirectionalIterator< T1, T3*, T3& > const &rhs)
	{
		return !(lhs == rhs);
	}
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 13:27:09 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/21 08:23:55 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP
# include "BidirectionalIterator.hpp"
# include "TypeTraits.hpp"
# include <cstddef>

namespace ft
{
	template < class T, class Pointer = T*, class Reference = T&,
			 class Category = ft::random_access_iterator_tag >
	class RandomAccessIterator : public BidirectionalIterator< T, T*, T&, Category >
	{
		public:
			typedef RandomAccessIterator<T, T*, T&>				iterator;
			typedef RandomAccessIterator<T, const T*, const T&>	const_iterator;
			typedef	BidirectionalIterator<T, T*, T&, Category>	bidirectional_iterator;
			typedef ptrdiff_t									difference_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef Category									iterator_category;

		public:
			RandomAccessIterator() : bidirectional_iterator()
			{
			}
			
			RandomAccessIterator(pointer ptr) : bidirectional_iterator(ptr)
			{
			}

			virtual ~RandomAccessIterator()
			{
			}

			RandomAccessIterator(RandomAccessIterator const &src)
			{
				*this = src;
			}

			iterator				&operator=(iterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}

			// a + n
			iterator				operator+(difference_type const &n) const
			{
				iterator	tmp = *this;

				tmp._ptr += n;
				return (tmp);
			}
			
			// a - n
			iterator				operator-(difference_type const &n) const
			{
				iterator	tmp = *this;

				tmp._ptr -= n;
				return (tmp);
			}
		
			// a - b	
			difference_type			operator-(iterator const &val) const
			{
				return (this->_ptr - val._ptr);
			}

			// a += n
			iterator				operator+=(difference_type const &n)
			{
				this->_ptr += n;
				return (*this);
			}

			// a -= n
			iterator				operator-=(difference_type const &n)
			{
				this->_ptr -= n;
				return (*this);
			}

			// a[n]
			reference				operator[](difference_type const &n) const
			{
				return (*(this->_ptr + n));
			}
			
			RandomAccessIterator	&operator++()
			{
				this->_ptr++;
				return (*this);
			}
			
			RandomAccessIterator	operator++(int)
			{
				iterator	old = *this;

				this->_ptr++;
				return (old);
			}
			
			RandomAccessIterator	&operator--()
			{
				this->_ptr--;
				return (*this);
			}
			
			RandomAccessIterator	operator--(int)
			{
				iterator	old = *this;

				this->_ptr--;
				return (old);
			}

			operator				iterator() const
			{
				return (iterator(this->_ptr));
			}
			
			operator				const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}

			// friend declaration for ==
			template <class T1, class T2, class T3>
			friend bool	operator==(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs);

			// friend declaration for !=
			template <class T1, class T2, class T3>
			friend bool	operator!=(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs);

			// friend declaration for <
			template <class T1, class T2, class T3>
			friend bool	operator<(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs);

			// friend declaration for >
			template <class T1, class T2, class T3>
			friend bool	operator>(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs);

			// friend declaration for <=
			template <class T1, class T2, class T3>
			friend bool	operator<=(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs);

			// friend declaration for >=
			template <class T1, class T2, class T3>
			friend bool	operator>=(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs);

		};
	
	// n + a
	template <class T>
	RandomAccessIterator<T, T*, T&>	operator+(typename RandomAccessIterator< T, T*, T& >::difference_type const &n, RandomAccessIterator< T, T*, T& > const &iterator)
	{
		return (iterator + n);
	}
	
	// a == b
	template <class T1, class T2, class T3>
	bool	operator==(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	
	// a != b
	template <class T1, class T2, class T3>
	bool	operator!=(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs)
	{
		return !(lhs == rhs);
	}

	// a < b
	template <class T1, class T2, class T3>
	bool	operator<(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}

	// a > b
	template <class T1, class T2, class T3>
	bool	operator>(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs)
	{
		return (rhs._ptr < lhs._ptr);
	}

	// a <= b
	template <class T1, class T2, class T3>
	bool	operator<=(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs)
	{
		return (!(rhs._ptr < lhs._ptr));
	}

	// a >= b
	template <class T1, class T2, class T3>
	bool	operator>=(RandomAccessIterator< T1, T2*, T2& > const &lhs, RandomAccessIterator< T1, T3*, T3& > const &rhs)
	{
		return (!(lhs._ptr < rhs._ptr));
	}

}

#endif

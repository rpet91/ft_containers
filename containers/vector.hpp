/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:55 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/02 09:44:58 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "RandomAccessIterator.hpp"
# include "ReverseIterator.hpp"
# include "TypeTraits.hpp"
# include "Utils.hpp"
# include <memory>
# include <cstddef>
# include <stdexcept>
# include <iostream> //todo: weg

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef RandomAccessIterator<T, T*, T&>					iterator;
			typedef RandomAccessIterator<T, const T*, const T&>		const_iterator;
			typedef ReverseIterator<iterator>						reverse_iterator;
			typedef ReverseIterator<const_iterator>					const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:
			allocator_type	_allocator;
			size_type		_size;
			size_type		_capacity;
			pointer			_data;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:
			// Default constructor
			explicit vector(const allocator_type &alloc = allocator_type()) :
				_allocator(alloc), _size(0), _capacity(0), _data(NULL)
			{
			}

			// Fill constructor
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _data(0)
			{
				assign(n, val);
			}

			// Range constructor
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, 
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0,
				const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _capacity(0), _data(0)
			{
				assign(first, last);
			}

			// Copy constructor
			vector(const vector &x) : _size(0), _capacity(0), _data(0)
			{
				*this = x;
			}

			// Destructor
			~vector()
			{
				clear();
				this->_allocator.deallocate(this->_data, this->_capacity);
			}

			// Assignment operator
			vector	&operator=(const vector &x)
			{
				assign(x.begin(), x.end());
				return (*this);
			}

		///////////////
		// ITERATORS //
		///////////////
		
		public:
			// Begin
			iterator				begin()
			{
				return (iterator(this->_data));
			}

			const_iterator			begin() const
			{
				return (const_iterator(this->_data));
			}

			// End
			iterator				end()
			{
				return (iterator(&this->_data[this->_size]));
			}

			const_iterator			end() const
			{
				return (const_iterator(&this->_data[this->_size]));
			}

			// Rbegin
			reverse_iterator		rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			// Rend
			reverse_iterator		rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(begin()));
			}

		//////////////
		// CAPACITY //
		//////////////

		public:
			// Size
			size_type	size() const
			{
				return (this->_size);
			}

			// Max size
			size_type	max_size() const
			{
				return (this->_allocator.max_size());
			}

			// Resize
			void		resize(size_type n, value_type val= value_type())
			{
				_setCapacity(n);
				while (this->_size > n)
					pop_back();
				while (this->_size < n)
					push_back(val);
			}

			// Capacity
			size_type	capacity() const
			{
				return (this->_capacity);
			}

			// Empty
			bool		empty() const
			{
				return (this->_size == 0);
			}

			// Reserve
			void		reserve(size_type n)
			{
				_setCapacity(n, true);
			}

		////////////////////
		// ELEMENT ACCESS //
		////////////////////

		public:
			// Operator[] (subscript)
			reference		operator[](size_type n)
			{
				return (this->_data[n]);
			}

			const_reference	operator[](size_type n) const
			{
				return (this->_data[n]);
			}

			// At
			reference		at(size_type n)
			{
				if (n >= this->_size)
					throw (std::out_of_range("out of range"));
				return (this->_data[n]);
			}

			const_reference	at(size_type n) const
			{
				if (n >= this->_size)
					throw (std::out_of_range("out of range"));
				return (this->_data[n]);
			}

			// Front
			reference		front()
			{
				return (this->_data[0]);
			}

			const_reference	front() const
			{
				return (this->_data[0]);
			}

			// Back
			reference		back()
			{
				return (this->_data[this->_size - 1]);
			}

			const_reference	back() const
			{
				return (this->_data[this->_size - 1]);
			}

		///////////////
		// MODIFIERS //
		///////////////

		public:
			// Assign
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
						typename ft::iterator_traits<InputIterator>::iterator_category* = 0)
			{
				clear();
				_setCapacity(ft::distance(first, last), true);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void		assign(size_type n, const value_type &val)
			{
				clear();
				_setCapacity(n, true);
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			// Push back
			void		push_back(const value_type &val)
			{
				_addElement(val, size());
			}

			// Pop back
			void	pop_back()
			{
				this->_size--;
				this->_allocator.destroy(&this->_data[this->_size]);
			}

			// Insert
			iterator	insert(iterator position, const value_type &val)
			{
				difference_type	insertPos = ft::distance(begin(), position);

				insert(position, 1, val);
				return (begin() + insertPos);
			}

			void		insert(iterator position, size_type n, const value_type &val)
			{
				difference_type	insertPosition = ft::distance(begin(), position);

				_setCapacity(this->_size + n);
				_moveElementsForward(n, insertPosition);
				for (size_type i = 0; i < n; i++)
					_addElement(val, insertPosition + i);
			}

			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last,
										typename ft::iterator_traits<InputIterator>::iterator_category* = 0)
			{
				difference_type	insertPosition = ft::distance(begin(), position);
				difference_type n = ft::distance(first, last);

				_setCapacity(this->_size + n);
				_moveElementsForward(n, insertPosition);
				for (difference_type i = 0; i < n; i++)
					_addElement(*(first + i), insertPosition + i);
			}

			// Erase
			iterator	erase(iterator position)
			{
				return (erase(position, position + 1));
			}

			iterator	erase(iterator first, iterator last)
			{
				difference_type	erasePosition = ft::distance(begin(), first);
				difference_type	n = ft::distance(first, last);

				_moveElementsBackward(n, erasePosition);
				for (difference_type i = 0; i < n; i++)
					pop_back();
				return (begin() + erasePosition);
			}

			// Swap
			void		swap(vector &x)
			{
				size_type		tmpSize = this->_size;
				size_type		tmpCapacity = this->_capacity;
				pointer			tmpData = this->_data;
				
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_data = x._data;
				x._size = tmpSize;
				x._capacity = tmpCapacity;
				x._data = tmpData;
			}

			// Clear
			void		clear()
			{
				while (this->_size)
					pop_back();
			}

		///////////////
		// ALLOCATOR //
		///////////////

		public:
			// Get allocator
			allocator_type	get_allocator() const
			{
				return (this->_allocator);
			}
			
		////////////////////////////////////
		// EXTRA PRIVATE MEMBER FUNCTIONS //
		////////////////////////////////////

		private:
			void	_addElement(const value_type &val, size_type position)
			{
				_setCapacity(this->_size + 1);
				this->_allocator.construct(&this->_data[position], val);
				this->_size++;
			}

			void	_moveElementsForward(size_type n, size_type position)
			{
				for (size_type i = this->_size + n - 1; i >= position + n; i--)
					this->_data[i] = this->_data[i - n];
			}

			void	_moveElementsBackward(size_type n, size_type position)
			{
				for (size_type i = 0; i <= this->_size - n; i++)
					this->_data[position + i] = this->_data[position + i + n];
			}

			void	_setCapacity(size_type n, bool fixedNb = false)
			{
				if (n <= this->_capacity)
					return ;
				size_type	newCapacity = n;

				if (fixedNb == false)
				{
					if (n > this->_capacity && n < this->_capacity * 2)
						newCapacity = this->_capacity * 2;
				}

				pointer		tmp = this->_allocator.allocate(newCapacity);

				for (size_t i = 0; i < this->_size; i++)
				{
					this->_allocator.construct(&tmp[i], this->_data[i]);
					this->_allocator.destroy(&this->_data[i]);
				}
				this->_allocator.deallocate(this->_data, this->_capacity);
				this->_capacity = newCapacity;
				this->_data = tmp;
			}
	};
		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////

			// Relational operators
			template <class T, class Alloc>
			bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (lhs.size() == rhs.size() &&
						ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			template <class T, class Alloc>
			bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return !(lhs == rhs);
			}

			template <class T, class Alloc>
			bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
							rhs.begin(), rhs.end()));
			}

			template <class T, class Alloc>
			bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return !(rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return !(lhs < rhs);
			}

			// Swap
			template <class T, class Alloc>
			void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
			{
				x.swap(y);
			}
}

#endif

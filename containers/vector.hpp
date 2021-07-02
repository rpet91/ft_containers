/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:55 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/02 14:13:11 by rpet          ########   odam.nl         */
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
				_allocator(alloc), _size(0), _capacity(0), _data(0)
			{
			}

			// Fill constructor
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(n), _capacity(n), _data(0)
			{
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i], val);
			}

			// Range constructor
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, 
				typename ft::iterator_traits<InputIterator>::type* = 0,
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
				clear();
		//		this->_capacity = x._capacity;
		//		this->_data = this->_allocator.allocate(this->_capacity);
				assign(x.begin(), x.end());
			/*	this->_allocator.deallocate(this->_data, this->_capacity);
				this->_allocator = x._allocator;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < x._size; i++)
					this->_allocator.construct(&this->_data[i], x._data[i]);*/
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
				return (reverse_iterator(&this->_data[this->_size]));
			}

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(&this->_data[this->_size]));
			}

			// Rend
			reverse_iterator		rend()
			{
				return (reverse_iterator(this->_data));
			}

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(this->_data));
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
				while (this->_size > n)
					pop_back();
				if (this->_capacity < n)
					this->_capacity = n;
				while (this->_size != n)
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
				if (n <= this->_capacity)
					return ;
				this->_capacity = n;

				pointer		tmp = this->_allocator.allocate(this->_capacity);

				for (size_t i = 0; i < this->_size; i++)
				{
					this->_allocator.construct(&tmp[i], this->_data[i]);
					this->_allocator.destroy(&this->_data[i]);
				}
				this->_allocator.deallocate(this->_data, this->_capacity);
				this->_data = tmp;
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
						typename ft::iterator_traits<InputIterator>::type* = 0)
			{
				reserve(ft::distance(first, last));
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void		assign(size_type n, const value_type &val)
			{
				reserve(n);
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			// Push back
			void		push_back(const value_type &val)
			{
				if (this->_capacity == 0)
					reserve(1);
				else if (this->_size + 1 > this->_capacity)
					reserve(this->_capacity * 2);
				this->_allocator.construct(&this->_data[this->_size], val);
				this->_size++;
			}

			// Pop back
			void	pop_back()
			{
				this->_size--;
				this->_allocator.destroy(&this->_data[this->_size]);
			}

			// Insert
//			iterator	insert(iterator position, const value_type &val)
//			{
//			}

//			void		insert(iterator position, size_type n, const value_type &val)
//			{
//			}

//			template <class InputIterator>
//			void		insert(iterator position, InputIterator first, InputIterator last)
//			{
//			}

			// Erase
//			iterator	erase(iterator position)
//			{
//			}

//			iterator	erase(iterator first, iterator last)
//			{
//			}

			// Swap
			void		swap(vector &x)
			{
				vector	tmp = x;

				x = *this;;
				*this = tmp;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:55 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/28 12:43:58 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "TypeTraits.hpp"
# include <memory>
# include <cstddef>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef ptrdiff_t	difference_type;
			typedef size_t		size_type;

		private:
			allocator_type	_allocator;
			size_type		_size;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:
			// Default constructor
			explicit vector(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
			}

			// Fill constructor
/*			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
				assign(n, val);
			}*/

			// Range constructor
/*			template <class InputIterator>
			vector(InputIterator first, InputIterator last, 
				typename ft::iterator_traits<InputIterator>::type* = 0,
				const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
				assign(first, last);
			}*/

			// Copy constructor
/*			vector(const vector &x) : _size(0)
			{
				*this = x;
			}*/

			// Destructor
			~vector()
			{
				// clear();
			}

			// Assignment operator
/*			vector	&operator=(const vector &x)
			{
				this->_allocator = x._allocator;
				assign(x.begin(), x.end());
				return (*this);
			}*/

		///////////////
		// ITERATORS //
		///////////////

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

	//		void		resize(size_type n, value_type val= value_type())
	//		{
//
//			}

		////////////////////
		// ELEMENT ACCESS //
		////////////////////

		///////////////
		// MODIFIERS //
		///////////////

		///////////////
		// ALLOCATOR //
		///////////////
			
		////////////////////////////////////
		// EXTRA PRIVATE MEMBER FUNCTIONS //
		////////////////////////////////////

	};
		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////

}

#endif

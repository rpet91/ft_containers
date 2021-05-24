/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:17 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/24 14:40:42 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list {
		//////////////////
		// MEMBER TYPES //
		//////////////////
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			&reference;
			typedef typename allocator_type::const_reference	&const_reference; const
			typedef typename allocator_type::pointer			*pointer;
			typedef typename allocator_type::const_pointer		*const_pointer; const
			typedef T											iterator;
			typedef T											const_iterator; const
			typedef T											reverse_iterator;
			typedef T											const_reverse_iterator; const
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:
			Alloc		_allocator;
			size_type	_size;


		//////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & OPERATOR OVERLOAD //
		//////////////////////////////////////////////////
		public:
			// Default constructor
			explicit list(const allocator_type &alloc = allocator_type()) : _allocator(alloc)
			{
			}
			// Fill constructor
			explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _allocator(alloc) 
			{
			}
			// Range constructor
			template <class InputIterator>
				list (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
				{
				}
			// Copy constructor
			list(const list &x)
			{
				*this = x;
			}
			// Destructor
			~list()
			{
			}
			// Operator overload


	
		///////////////
		// ITERATORS //
		///////////////
	
		//////////////
		// CAPACITY //
		//////////////
		
		///////////////////
		// ELEMENT ACCES //
		///////////////////
	
		///////////////
		// MODIFIERS //
		///////////////
	
		////////////////
		// OPERATIONS //
		////////////////

		///////////////
		// OBSERVERS //
		///////////////

		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////

	};

}
#endif

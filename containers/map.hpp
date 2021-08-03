/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:31:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/03 09:40:20 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "ReverseIterator.hpp"
# include "TypeTraits.hpp"
# include "Utils.hpp"
# include "Pair.hpp"
# include <memory>
# include <cstddef>
# include <iostream>

namespace ft
{
	template < class Key,
			 class T,
			 class Compare = ft::less<Key>,
			 class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
/*			typedef MapNode<Key, T>								node;
			typedef	NodeIterator<node, T>						iterator;
			typedef	NodeIterator<const node, const T>			const_iterator;
			typedef ReverseIterator<iterator>					reverse_iterator;
			typedef ReverseIteartor<const_iterator>				const_reverse_iterator;*/
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:
			key_compare		_compare;
			allocator_type	_allocator;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:
			// Default constructor
			explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())	: _compare(comp), _allocator(alloc)
			{
			}

			// Range constructor
		/*	template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())
			{
			}*/

			// Copy constructor
			map(const map &x)
			{
				*this = x;
			}

			// Destructor
			~map()
			{
			}

			// Assignment operator
			map	&operator=(const map &x)
			{
				this->_compare = x._compare;
				this->_allocator = x._allocator;
			}
	};
}
#endif

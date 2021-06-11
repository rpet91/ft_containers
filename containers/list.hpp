/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:17 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/11 10:00:18 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include "ListNode.hpp"
# include "ListIterator.hpp"
# include "ReverseIterator.hpp"
# include "TypeTraits.hpp"
# include <memory>
# include <cstddef>
# include <iostream> //mogelijkweeg

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{

		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ListNode<T>									node;
			typedef ListIterator<node, T>						iterator;
			typedef ListIterator<const node, const T>			const_iterator;
			typedef ReverseIterator<iterator>					reverse_iterator;
//			typedef ReverseIterator<const_iterator>				const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:
			allocator_type	_allocator;
			size_type		_size;
			node			_sentinel;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:
			// Default constructor
			explicit list(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
				this->_sentinel.next = &this->_sentinel;
				this->_sentinel.prev = &this->_sentinel;
				this->_sentinel.data = T();
			}

			// Fill constructor
			explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0) 
			{
				this->_sentinel.next = &this->_sentinel;
				this->_sentinel.prev = &this->_sentinel;
				this->_sentinel.data = T();
				assign(n, val);
			}

			// Range constructor
			template <class InputIterator>
			list(InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::type* = 0,
				const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
				this->_sentinel.next = &this->_sentinel;
				this->_sentinel.prev = &this->_sentinel;
				this->_sentinel.data = T();
				assign(first, last);
			}

			// Copy constructor
			list(const list &x) : _allocator(x._allocator), _size(0)
			{
				*this = x;
			}

			// Destructor
			~list()
			{
				clear();
			}

			// Assignment operator
			list	&operator=(const list &x)
			{
				clear();
				this->_allocator = x._allocator;
				this->_size = x._size;
				this->_sentinel = x._sentinel;
				return (*this);
			}

		///////////////
		// ITERATORS //
		///////////////

		public:
			// Begin
			iterator				begin()
			{
				return (iterator(this->_sentinel.next));
			}

			const_iterator			begin() const
			{
				return (const_iterator(this->_sentinel.next));
			}

			// End
			iterator				end()
			{
				return (iterator(&this->_sentinel));
			}

			const_iterator			end() const
			{
				return (iterator(&this->_sentinel));
			}

			// Rbegin
			reverse_iterator		rbegin()
			{
				return (reverse_iterator(this->_sentinel.prev));
			}
			
		//	const_reverse_iterator	rbegin() const
		//	{
		//		return (reverse_iterator(this->_sentinel.prev));
		//	}
		
			// Rend
		//	reverse_iterator		rend()
		//	{
		//		return (reverse_iterator(&this->_sentinel));
		//	}

		//	const_reverse_iterator	rend() const
		//	{
		//		return (reverse_iterator(&this->_sentinel));
		//	}

		//////////////
		// CAPACITY //
		//////////////

		public:
			// Empty
			bool		empty() const
			{
				return (this->_size == 0);
			}

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
		
		///////////////////
		// ELEMENT ACCES //
		///////////////////
		
		public:
			// Front
			reference		front()
			{
				return (this->_sentinel.next->data);
			}

			const_reference	front() const
			{
				return (this->_sentinel.next->data);
			}

			// Back
			reference		back()
			{
				return (this->_sentinel.prev->data);
			}

			const_reference	back() const
			{
				return (this->_sentinel.prev->data);
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
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void	assign(size_type n, const value_type &val)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}

			// Push front
			void	push_front(const value_type &val)
			{
				ListNode<T>		*newNode = new ListNode<T>(val);
				ListNode<T>		*next = this->_sentinel.next;
				
				next->prev = newNode;
				newNode->next = next;
				this->_sentinel.next = newNode;
				newNode->prev = &this->_sentinel;
				this->_size++;
			}

			// Pop front
			void	pop_front()
			{
				if (this->_size == 0)
					return ;

				ListNode<T>		*newHead = this->_sentinel.next->next;

				newHead->prev = &this->_sentinel;
				delete this->_sentinel.next;
				this->_sentinel.next = newHead;
				this->_size--;
			}

			// Push back
			void	push_back(const value_type &val)
			{
				ListNode<T>		*newNode = new ListNode<T>(val);
				ListNode<T>		*prev = this->_sentinel.prev;

				prev->next = newNode;
				newNode->prev = prev;
				this->_sentinel.prev = newNode;
				newNode->next = &this->_sentinel;
				this->_size++;
			}

			// Pop back
			void	pop_back()
			{
				if (this->_size == 0)
					return ;

				ListNode<T>		*newTail = this->_sentinel.prev->prev;

				newTail->next = &this->_sentinel;
				delete this->_sentinel.prev;
				this->_sentinel.prev = newTail;
				this->_size--;
			}

			// Insert

			// Erase
			
			// Swap
		/*	void	swap(list &x)
			{
				list	tmp = x;

				x = *this;
				*this = tmp;
			}*/
			
			// Resize
			void	resize(size_type n, value_type val = value_type())
			{
				while (this->_size != n)
				{
					if (this->_size < n)
						push_back(val);
					else
						pop_back();
				}
			}

			// Clear
			void	clear()
			{
				while (this->_size)
					pop_back();
			}

		////////////////
		// OPERATIONS //
		////////////////

		///////////////
		// OBSERVERS //
		///////////////

		public:
		//Get allocator
		allocator_type	get_allocator() const
		{
			return (this->_allocator);
		}

		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////

		////////////////////////////////////
		// EXTRA PRIVATE MEMBER FUNCTIONS //
		////////////////////////////////////

			//DEBUGGER
		public:
			void	nodeInfo(ListNode<T> *info)
			{
				if (!info)
					return ;
				std::cout << "Address: " << info << std::endl;
				std::cout << "Value: " << info->data << std::endl;
				std::cout << "Prev: " << info->prev << " & Next: " << info->next << std::endl;
				std::cout <<  std::endl;
			}

			void	debug()
			{
				ListNode<T>		*tmp = this->_sentinel.next;

				std::cout << "Sentinel address: " << &this->_sentinel << std::endl << std::endl;
				for (size_t i = 0; i < this->_size; i++)
				{
					nodeInfo(tmp);
					if (tmp->next)
						tmp = tmp->next;
				}
			}
			//DEBUGGER
	};

}
#endif

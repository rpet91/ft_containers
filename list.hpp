/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:17 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/26 14:50:15 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include "ListNode.hpp"
# include <memory>
# include <iostream> //mogelijkweeg

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
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef T											iterator;
			typedef T											const_iterator;
			typedef T											reverse_iterator;
			typedef T											const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:
			allocator_type	_allocator;
			size_type		_size;
			ListNode<T>		*_head;
			ListNode<T>		*_tail;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:

			// Default constructor
			explicit list(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0), _head(0), _tail(0)
			{
			}

			// Fill constructor
			explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0) 
			{
				assign(n, val);
				std::cout << "Head: " << this->_head << " & Tail: " << this->_tail << std::endl;
			}

			// Range constructor
//			template <class InputIterator>
//				list (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
//				{
//				}

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
				return (*this);
			}

	
		///////////////
		// ITERATORS //
		///////////////

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
				return (this->_head->data);
			}

			const_reference	front() const
			{
				return (this->_head->data);
			}

			// Back
			reference		back()
			{
				return (this->_tail->data);
			}

			const_reference	back() const
			{
				return (this->_tail->data);
			}
	
		///////////////
		// MODIFIERS //
		///////////////

		public:
			// Assign
/*			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last)
			{
			}
*/
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
				if (this->_size == 0)
				{
					this->_head = newNode;
					this->_tail = newNode;
				}
				else
					newNode->next = this->_head;
				this->_head->prev = newNode;
				this->_head = newNode;
				this->_size++;
			}

			// Pop front
			void	pop_front()
			{
				if (this->_size == 0)
					return ;

				ListNode<T>		*newHead = this->_head->next;

				if (this->_size > 1)
					newHead->prev = this->_head->prev;
				delete this->_head;
				this->_head = newHead;
				this->_size--;
			}

			// Push back
			void	push_back(const value_type &val)
			{
				ListNode<T>		*newNode = new ListNode<T>(val);

				if (this->_size == 0)
				{
					this->_head = newNode;
					this->_tail = newNode;
				}
				else
					newNode->prev = this->_tail;
				this->_tail->next = newNode;
				this->_tail = newNode;
				this->_size++;
			}

			// Pop back
			void	pop_back()
			{
				if (this->_size == 0)
					return ;

				ListNode<T>		*newTail = this->_tail->prev;

				if (this->_size > 1)
					newTail->next = this->_tail->next;
				delete this->_tail;
				this->_tail = newTail;
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
				ListNode<T>		*tmp = this->_head;

				std::cout << "Size: " << this->_size << std::endl << std::endl;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:17 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/25 14:48:58 by rpet          ########   odam.nl         */
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
				this->_head = new ListNode<T>(val);
				this->_tail = new ListNode<T>(val);
				std::cout << "Head: " << this->_head << " & Tail: " << this->_tail << std::endl;
				for (size_t i = 0; i < n; i++)
				{
					push_back(val);
				}
			}
			// Range constructor
//			template <class InputIterator>
//				list (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
//				{
//				}
			// Copy constructor
			list(const list &x) : _allocator(x._alllocator), _size(x._size)
			{
				this->_head = new ListNode<T>(0);
				this->_tail = new ListNode<T>(0);
				this->_head->next = this->_tail;
				this->_tail->prev = this->_head;
			}
			// Destructor
			~list()
			{
				delete this->_head;
				delete this->_tail;
			}
			// Assignment operator
			list	&operator=(const list &x)
			{
				delete this->_head;
				delete this->_tail;
				this->_allocator = x._allocator;
				this->_size = x._size;
				this->_head = new ListNode<T>(0);
				this->_tail = new ListNode<T>(0);
				return (*this);
			}

	
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
		public:
			// Assign
/*			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last)
			{
			}
			void	assign(size_type n, const value_type &val)
			{
			}
*/
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

				ListNode<T>		*tmp = this->_tail->prev;
				
				this->_tail = tmp;
				this->_size--;
			}

		////////////////
		// OPERATIONS //
		////////////////

		///////////////
		// OBSERVERS //
		///////////////

		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////

			//DEBUGGER

		public:
			void	nodeInfo(ListNode<T> *info)
			{
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
					tmp = tmp->next;
				}
			}
			//DEBUGGER
	};

}
#endif

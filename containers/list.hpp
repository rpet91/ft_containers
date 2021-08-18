/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:30:17 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/05 13:57:28 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include "ListNode.hpp"
# include "NodeIterator.hpp"
# include "ReverseIterator.hpp"
# include "TypeTraits.hpp"
# include "Utils.hpp"
# include <memory>
# include <cstddef>

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
			typedef NodeIterator<node, T>						iterator;
			typedef NodeIterator<const node, const T>			const_iterator;
			typedef ReverseIterator<iterator>					reverse_iterator;
			typedef ReverseIterator<const_iterator>				const_reverse_iterator;
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
				_constructorSetup();
			}

			// Fill constructor
			explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0) 
			{
				_constructorSetup();
				assign(n, val);
			}

			// Range constructor
			template <class InputIterator>
			list(InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0,
				const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0)
			{
				_constructorSetup();
				assign(first, last);
			}

			// Copy constructor
			list(const list &x) : _allocator(x._allocator), _size(0)
			{
				_constructorSetup();
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
				return (const_iterator(&this->_sentinel));
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
						typename ft::iterator_traits<InputIterator>::iterator_category* = 0)
			{
				difference_type	newAmount = ft::distance(first, last);
				size_type		oldAmount = this->_size;

				for (difference_type i = 0; i < newAmount; i++)
				{
					push_back(*first);
					first++;
				}
				for (size_type i = 0; i < oldAmount; i++)
					pop_front();
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
				_addNode(val, 0);
			}

			// Pop front
			void	pop_front()
			{
				_deleteNode(0);
			}

			// Push back
			void	push_back(const value_type &val)
			{
				_addNode(val, size());
			}

			// Pop back
			void	pop_back()
			{
				if (size() >= 1)
					_deleteNode(size() - 1);
			}

			// Insert
			iterator	insert(iterator position, value_type const &val)
			{
				insert(position, 1, val);
				return (--position);
			}

			void		insert(iterator position, size_type n, value_type const &val)
			{
				difference_type	insertPosition = ft::distance(begin(), position);

				for (size_type i = 0; i < n; i++)
					_addNode(val, insertPosition + i);
			}

			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last,
							typename ft::iterator_traits<InputIterator>::iterator_category* = 0)
			{
				difference_type	insertPosition = ft::distance(begin(), position);

				while (first != last)
					_addNode(*first++, insertPosition++);
			}

			// Erase
			iterator	erase(iterator position)
			{
				difference_type	erasePosition = ft::distance(begin(), position);

				position++;
				_deleteNode(erasePosition);
				return (position);
			}
			
			iterator	erase(iterator first, iterator last)
			{
				difference_type erasePosition = ft::distance(begin(), first);

				while (first != last)
				{
					first++;
					_deleteNode(erasePosition);
				}
				return (last);
			}
			
			// Swap
			void	swap(list &x)
			{
				list	tmp;

				tmp.splice(tmp.begin(), x);
				x.splice(x.begin(), *this);
				splice(begin(), tmp);
			}
			
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

		public:
			// Splice
			void	splice(iterator position, list &x)
			{
				splice(position, x, x.begin(), x.end());
			}

			void	splice(iterator position, list &x, iterator i)
			{
				difference_type		distanceToNode = ft::distance(x.begin(), i);
				difference_type		distanceToAdd = ft::distance(begin(), position);
				ListNode<T>		*removedNode = x._removeFromList(distanceToNode);
				ListNode<T>		*placeNode = this->_sentinel.next;

				for (difference_type i = 0; i < distanceToAdd; i++)
					placeNode = placeNode->next;
				_connectNodes(placeNode->prev, removedNode);
				_connectNodes(removedNode, placeNode);
				this->_size++;
			}

			void	splice(iterator position, list &x, iterator first, iterator last)
			{
				iterator	tmp = first;

				while (first != last)
				{
					tmp = first;
					first++;
					splice(position, x, tmp);
				}
			}

			// Remove
			void	remove(value_type const &val)
			{
				for (iterator it = begin(); it != end(); it++)
					if (*it == val)
						it = erase(it);
			}

			// Remove if
			template <class Predicate>
			void	remove_if(Predicate pred)
			{
				for (iterator it = begin(); it != end(); it++)
					if (pred(*it))
					{
						iterator	removeMe = it;
						--it;
						removeMe = erase(removeMe);
					}
			}

			// Unique
			void	unique()
			{
				unique(ft::isEqual<T>);
			}

			template <class BinaryPredicate>
			void	unique(BinaryPredicate binary_pred)
			{
				iterator	it = begin();

				while (it != end())
				{
					iterator	nextIt = it;

					nextIt++;
					if (binary_pred(*nextIt, *it))
						nextIt = erase(nextIt);
					else
						it++;
				}
			}

			// Merge
			void	merge(list &x)
			{
				merge(x, ft::less<T>);
			}

			template <class Compare>
			void	merge(list &x, Compare comp)
			{	
				if (*this == x)
					return ;

				iterator	it = begin();

				while (it != end() && x.size())
				{
					if (comp(*x.begin(), *it))
						splice(it, x, x.begin());
					else
						it++;
				}
				splice(end(), x);
			}

			// Sort
			void	sort()
			{
				sort(ft::less<T>);
			}

			template <class Compare>
			void	sort(Compare comp)
			{
				if (size() <= 1)
					return ;

				list		halfList;
				iterator	middle = begin();

				for (size_t i = 0; i < size() / 2; i++)
					middle++;
				halfList.splice(halfList.begin(), *this, middle, end());
				sort(comp);
				halfList.sort(comp);
				merge(halfList, comp);
			}

			// Reverse
			void	reverse()
			{
				iterator	it = begin();
				
				while (it != end())
					splice(begin(), *this, it++);
			}

		///////////////
		// OBSERVERS //
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
			void	_constructorSetup()
			{
				this->_sentinel.next = &this->_sentinel;
				this->_sentinel.prev = &this->_sentinel;
				this->_sentinel.data = T();
			}

			void	_addNode(const value_type &val, size_type position)
			{
				ListNode<T>		*nextNode = this->_sentinel.next;
				
				for (size_type i = 0; i < position && i < this->size(); i++)
					nextNode = nextNode->next;

				ListNode<T>		*newNode = new ListNode<T>(val);
				ListNode<T>		*prevNode = nextNode->prev;

				_connectNodes(newNode, nextNode);
				_connectNodes(prevNode, newNode);
				this->_size++;
			}

			void	_deleteNode(size_t position)
			{
				ListNode<T>		*deleteNode = _removeFromList(position);

				if (deleteNode)
					delete deleteNode;
			}

			node	*_removeFromList(size_type position)
			{
				if (this->_size == 0)
					return (0);

				ListNode<T>		*removeNode = this->_sentinel.next;

				for (size_type i = 0; i < position && i < this->size(); i++)
					removeNode = removeNode->next;

				ListNode<T>		*newPrev = removeNode->prev;

				_connectNodes(newPrev, removeNode->next);
				--this->_size;
				return (removeNode);
			}

			void	_connectNodes(node *first, node *second)
			{
				first->next = second;
				second->prev = first;
			}
	};
		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////
		
			// Relational operators
			template <class T, class Alloc>
			bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return (lhs.size() == rhs.size() &&
						ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			template <class T, class Alloc>
			bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return !(lhs == rhs);
			}

			template <class T, class Alloc>
			bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
							rhs.begin(), rhs.end()));
			}

			template <class T, class Alloc>
			bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return !(rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return (rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return !(lhs < rhs);
			}

			// Swap
			template <class T, class Alloc>
			void	swap(list<T, Alloc> &x, list<T, Alloc> &y)
			{
				x.swap(y);
			}
}
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:31:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/26 07:41:28 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "MapNode.hpp"
# include "NodeIterator.hpp"
# include "ReverseIterator.hpp"
# include "TypeTraits.hpp"
# include "Utils.hpp"
# include "Pair.hpp"
# include <memory>
# include <cstddef>

namespace ft
{
	template < class Key,
			 class T,
			 class Compare = ft::less<Key>,
			 class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef MapNode<value_type>								node;
			typedef	NodeIterator<node, value_type>					iterator;
			typedef	NodeIterator<node, const value_type>			const_iterator;
			typedef ReverseIterator<iterator>						reverse_iterator;
			typedef ReverseIterator<const_iterator>					const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;
			typedef typename Alloc::template rebind<node>::other	node_allocator;

		// Value compare class
		public:
			class value_compare : public binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare		comp;
	
					value_compare(Compare c) : comp(c)
					{
					}

				public:
					bool	operator()(const value_type &x, const value_type &y) const
					{
						return (comp(x.first, y.first));
					}
			};

		private:
			key_compare		_compare;
			node_allocator	_allocator;
			size_type		_size;
			node			*_root;
			node			_firstSentinel;
			node			_lastSentinel;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:
			// Default constructor
			explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type())	:
				_compare(comp), _allocator(alloc), _size(0), _root(0)
			{
				_constructorSetup();
			}

			// Range constructor
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0,
				const allocator_type &alloc = allocator_type()) :
				_compare(comp), _allocator(alloc), _size(0), _root(0)
			{
				_constructorSetup();
				insert(first, last);
			}

			// Copy constructor
			map(const map &x) :
				_compare(x._compare), _allocator(x._allocator), _size(0), _root(0)
			{
				_constructorSetup();
				*this = x;
			}

			// Destructor
			virtual ~map()
			{
				clear();
			}

			// Assignment operator
			map	&operator=(const map &x)
			{
				this->_compare = x._compare;
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

		///////////////
		// ITERATORS //
		///////////////

		public:
			// Begin
			iterator				begin()
			{
				return (iterator(this->_firstSentinel.nextNode()));
			}

			const_iterator			begin() const
			{
				return (const_iterator(this->_firstSentinel.nextNode()));
			}

			// End
			iterator				end()
			{
				return (iterator(&this->_lastSentinel));
			}

			const_iterator			end() const
			{
				return (const_iterator(const_cast<node*>(&this->_lastSentinel)));
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

		////////////////////
		// ELEMENT ACCESS //
		////////////////////

		public:
			// Operator[]
			mapped_type	&operator[](const key_type &k)
			{
				return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
			}

		///////////////
		// MODIFIERS //
		///////////////

		public:
			// Insert
			ft::pair<iterator, bool>	insert(const value_type &val)
			{
				size_type	oldSize = this->_size;

				this->_root = _insertNode(val, this->_root, 0);
				if (this->_size == oldSize)
					return (ft::make_pair(find(val.first), false));
				return (ft::make_pair(find(val.first), true));
			}

			iterator	insert(iterator position, const value_type &val)
			{
				(void) position;
				return (insert(val).first);
			}

			template <class InputIterator>
			void		insert(InputIterator first, InputIterator last,
							typename iterator_traits<InputIterator>::iterator_category* = 0)
			{
				while (first != last)
					insert(*(first++));
			}

			// Erase
			void		erase(iterator position)
			{
				this->_root = _eraseNode(position->first, this->_root);
				_updateSentinels();
			}

			size_type	erase(const key_type &k)
			{
				size_type	oldSize = this->_size;

				this->_root = _eraseNode(k, this->_root);
				_updateSentinels();
				return (oldSize - this->_size);
			}

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			// Clear
			void	clear()
			{
				_clearMap(this->_root);
			}

			// Swap
			void	swap(map &other)
			{
				ft::swap(this->_root, other._root);
				ft::swap(this->_allocator, other._allocator);
				ft::swap(this->_compare, other._compare);
				ft::swap(this->_size, other._size);
				_updateSentinels();
				other._updateSentinels();
			}

		///////////////
		// OBSERVERS //
		///////////////

		public:
			// Key comp
			key_compare		key_comp() const
			{
				return (this->_compare);
			}

			value_compare	value_comp() const
			{
				return (value_compare(this->_compare));
			}

		////////////////
		// OPERATIONS //
		////////////////

		public:
			// Find
			iterator		find(const key_type &k)
			{
				node	*findNode = _findNode(k);

				if (!findNode)
					return (end());
				return (iterator(findNode));
			}

			const_iterator	find(const key_type &k) const
			{
				node	*findNode = _findNode(k);

				if (!findNode)
					return (end());
				return (const_iterator(findNode));
			}

			// Count
			size_type		count(const key_type &k) const
			{
				if (_findNode(k))
					return (1);
				return (0);
			}

			// Lower bound
			iterator		lower_bound(const key_type &k)
			{
				iterator	findBound = begin();
				
				while (findBound != end() && this->_compare(findBound->first, k))
					findBound++;
				return (findBound);
			}

			const_iterator	lower_bound(const key_type &k) const
			{
				const_iterator	findBound = begin();
				
				while (findBound != end() && this->_compare(findBound->first, k))
					findBound++;
				return (findBound);
			}

			// Upper bound
			iterator		upper_bound(const key_type &k)
			{
				iterator	findBound = begin();
				
				while (findBound != end() && !this->_compare(k, findBound->first))
					findBound++;
				return (findBound);
			}

			const_iterator	upper_bound(const key_type &k) const
			{
				const_iterator	findBound = begin();
				
				while (findBound != end() && !this->_compare(k, findBound->first))
					findBound++;
				return (findBound);
			}

			// Equal range
			ft::pair<iterator, iterator>				equal_range(const key_type &k)
			{
				return (make_pair(lower_bound(k), upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator>	equal_range(const key_type &k) const
			{
				return (make_pair(lower_bound(k), upper_bound(k)));
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
			// Basic setup for creating a new map
			void	_constructorSetup()
			{
				this->_firstSentinel.first = &this->_firstSentinel;
				this->_firstSentinel.last = &this->_lastSentinel;
				this->_lastSentinel.last = &this->_lastSentinel;
				this->_lastSentinel.first = &this->_firstSentinel;
			}

			// Finds and returns the node in map
			node	*_findNode(const key_type &k) const
			{
				node	*tmp = this->_root;

				while (tmp->data.first != k)
				{
					if (ft::isEqual(tmp->data.first, k) == false)
					{
						if (this->_compare(tmp->data.first, k) && tmp->right)
							tmp = tmp->right;
						else if (tmp->left)
							tmp = tmp->left;
						else
							break ;
					}
					else
						break ;
				}
				if (tmp->data.first != k)
					return (0);
				return (tmp);
			}

			// Finds the node we have to delete if possible
			node	*_eraseNode(const key_type &k, node *current)
			{
				if (!current)
					return (current);
				// Checks if key is on the left or right side of the tree
				if (k < current->data.first)
					current->left = _eraseNode(k, current->left);
				else if (k > current->data.first)
					current->right = _eraseNode(k, current->right);
				else // This is the node we want to delete
					current = _deleteNode(current);
				// Checks if the tree only had one node
				if (!current)
					return (current);
				current->updateHeight();
				// Checks if we need rotation
				if (_rotateNodeErase(current))
					return (current->parent);
				return (current);
			}

			// Deletes the node
			node	*_deleteNode(node *current)
			{
				// Checks if the node has one or no child
				if (!current->left || !current->right)
				{
					node	*tmp = current->left ? current->left : current->right;

					// No child
					if (!current->left && !current->right)
					{
						tmp = current;
						this->_allocator.destroy(tmp);
						this->_allocator.deallocate(tmp, 1);
						current = 0;
						this->_size--;
					}
					else // One child
					{
						tmp->parent = current->parent;

						node	*tmp2 = current;

						current = tmp;
						this->_allocator.destroy(tmp2);
						this->_allocator.deallocate(tmp2, 1);
						this->_size--;
					}
				}
				else // We have two childs
				{
					node	*tmp = current->right;

					while (tmp->left)
						tmp = tmp->left;
					// Connects all the pointers to the correct nodes
					_swapNodes(current, tmp);
					ft::swap(current, tmp);
					current->right = _eraseNode(tmp->data.first, current->right);
				}
				return (current);
			}

			// Inserts a new node if possible
			node	*_insertNode(const value_type &val, node *current, node *parent)
			{
				key_type	key = val.first;

				if (!current)
					return (_createNode(val, parent));
				// Checks if we have to place the node on the left or right side of the tree
				if (this->_compare(key, current->data.first))
					current->left = _insertNode(val, current->left, current);
				else if (this->_compare(current->data.first, key))
					current->right = _insertNode(val, current->right, current);
				else
					return (current);
				current->updateHeight();
				// Checks if we need rotation
				if (_rotateNodeInsert(key, current))
					return (current->parent);
				return (current);
			}

			// Creates a new node for the map
			node	*_createNode(const value_type &val, node *parent)
			{
				node	*newNode = this->_allocator.allocate(1);

				this->_allocator.construct(newNode, val);
				newNode->first = &this->_firstSentinel;
				newNode->last = &this->_lastSentinel;
				newNode->parent = parent;
				this->_size++;
				_updateSentinels();
				return (newNode);
			}

			// Checks if a rotation is necessary after inserting a new node
			bool	_rotateNodeInsert(const key_type &key, node *current)
			{
				// Left left rotate
				if (current->getBalance() > 1 && this->_compare(key, current->left->data.first))
				{
					current->rightRotate();
					return (true);
				}
				// Right right rotate
				if (current->getBalance() < -1 && this->_compare(current->right->data.first, key))
				{
					current->leftRotate();
					return (true);
				}
				// Left right rotate
				if (current->getBalance() > 1 && this->_compare(current->left->data.first, key))
				{
					current->left->leftRotate();
					current->rightRotate();				
					return (true);
				}
				// Right left rotate
				if (current->getBalance() < -1 && this->_compare(key, current->right->data.first))
				{
					current->right->rightRotate();
					current->leftRotate();
					return (true);
				}
				return (false);
			}
			
			// Checks if a rotation is necessary after erasing a node
			bool	_rotateNodeErase(node *current)
			{
				// Left left rotate
				if (current->getBalance() > 1 && current->left->getBalance() >= 0)
				{
					current->rightRotate();
					return (true);
				}
				// Right right rotate
				if (current->getBalance() < -1 && current->right->getBalance() <= 0)
				{
					current->leftRotate();
					return (true);
				}
				// Left right rotate
				if (current->getBalance() > 1 && current->left->getBalance() < 0)
				{
					current->left->leftRotate();
					current->rightRotate();
					return (true);
				}
				// Right left rotate
				if (current->getBalance() < -1 && current->right->getBalance() > 0)
				{
					current->right->rightRotate();
					current->leftRotate();
					return (true);
				}
				return (false);
			}

			// Updates the pointers to the first and last sentinel
			void	_updateSentinels()
			{
				this->_firstSentinel.parent = this->_root;
				this->_lastSentinel.parent = this->_root;
			}

			// Swaps two nodes including all the links with their parent and childs
			void	_swapNodes(node *first, node *second)
			{
				if (first == second)
					return ;
				// Checks if first has a parent and connects the correct child with second
				if (first->parent)
				{
					if (first == first->parent->right)
						first->parent->right = second;
					else
						first->parent->left = second;
				}
				// Checks if second has a parent and connects the correct child with first
				if (second->parent)
				{
					if (second == second->parent->right)
						second->parent->right = first;
					else
						second->parent->left = first;
				}
				ft::swap(first->parent, second->parent);
				// Connects all the child's parents with the correct node
				if (first->left)
					first->left->parent = second;
				if (first->right)
					first->right->parent = second;
				if (second->left)
					second->left->parent = first;
				if (second->right)
					second->right->parent = first;
				ft::swap(first->left, second->left);
				ft::swap(first->right, second->right);
				ft::swap(first->height, second->height);
			}

			// Wipes the entire map without rebalancing
			void	_clearMap(node *current)
			{
				if (!current || !this->_size)
					return ;
				_clearMap(current->left);
				_clearMap(current->right);
				this->_allocator.destroy(current);
				this->_allocator.deallocate(current, 1);
				this->_size--;
				if (current == this->_root)
				   this->_root = 0;
				_updateSentinels();
			}
	};
		///////////////////////////////////
		// NON-MEMBER FUNCTION OVERLOADS //
		///////////////////////////////////

			// Relational operators
			template <class Key, class T, class Compare, class Alloc>
			bool operator==(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
			{
				if (lhs.size() != rhs.size())
					return (false);

				typename ft::map<Key, T, Compare, Alloc>::const_iterator it_lhs = lhs.begin();
				typename ft::map<Key, T, Compare, Alloc>::const_iterator it_rhs = rhs.begin();

				while (it_lhs != lhs.end() && it_rhs != rhs.end())
				{
					if (*it_lhs != *it_rhs)
						return (false);
					it_lhs++;
					it_rhs++;
				}

				return (true);
			}
			
			template <class Key, class T, class Compare, class Alloc>
			bool operator!=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
			{
				return !(lhs == rhs);
			}
			
			template <class Key, class T, class Compare, class Alloc>
			bool operator<(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}
			
			template <class Key, class T, class Compare, class Alloc>
			bool operator<=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
			{
				return !(rhs < lhs);
			}
			
			template <class Key, class T, class Compare, class Alloc>
			bool operator>(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
			{
				return (rhs < lhs);
			}
			
			template <class Key, class T, class Compare, class Alloc>
			bool operator>=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
			{
				return !(lhs < rhs);
			}

			// Swap
			template <class Key, class T, class Compare, class Alloc>
			void	swap(ft::map<Key,T,Compare,Alloc> &lhs, ft::map<Key,T,Compare,Alloc> &rhs)
			{
				lhs.swap(rhs);
			}
}
#endif

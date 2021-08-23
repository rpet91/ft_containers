/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:31:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/23 08:20:25 by rpet          ########   odam.nl         */
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
# include <iostream>
# include <string>
#define CRESET   "\033[0m"
#define CRED     "\033[31m"      /* Red */
#define CGREEN   "\033[32m"      /* Green */
#define CYELLOW  "\033[33m"      /* Yellow */
#define CBLUE    "\033[34m"      /* Blue */

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
			typedef	NodeIterator<const node, const T>				const_iterator;
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
			~map()
			{
				//clear();
			}

			// Assignment operator
			map	&operator=(const map &x)
			{
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
				return (const_iterator(&this->_lastSentinel));
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
				this->_root = _deleteNode(position->first, this->_root);
				_updateSentinels();
			}

			size_type	erase(const key_type &k)
			{
				size_type	oldSize = this->_size;

				this->_root = _deleteNode(k, this->_root);
				this->_updateSentinels();
				return (oldSize - this->_size);
			}

			void		erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			// Clear
			void		clear()
			{
				while (this->_size)
					erase(this->_root->data.first);
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
				return (iterator(_findNode(k)));
			}

			const_iterator	find(const key_type &k) const
			{
				return (const_iterator(_findNode(k)));
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
			node	*_findNode(const key_type &k)
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
				return (tmp);
			}

			// Deletes the node if possible
			node	*_deleteNode(const key_type &k, node *current)
			{
				if (!current)
					return (current);
				// Checks if key is on the left or right side of the tree
				if (k < current->data.first)
					current->left = _deleteNode(k, current->left);
				else if (k > current->data.first)
					current->right = _deleteNode(k, current->right);
				else // This is the node we want to delete
				{
					// Checks if the node has one or no child
					if (!current->left || !current->right)
					{
						node	*tmp = current->left ? current->left : current->right;

						// No child
						if (!current->left && !current->right)
						{
							tmp = current;
							current = 0;
							this->_size--;
							this->_allocator.destroy(tmp);
							this->_allocator.deallocate(tmp, 1);
						}
						else // One child
						{
							tmp->parent = current->parent;

							node	*tmp2 = current;

							current = tmp;
							this->_size--;
							this->_allocator.destroy(tmp2);
							this->_allocator.deallocate(tmp2, 1);
						}
					}
					else // We have two childs
					{
						node	*tmp = current->right;

						while (tmp->left)
							tmp = tmp->left;
						_swapNodes(current, tmp);
						ft::swap(current, tmp);
						current->right = _deleteNode(tmp->data.first, current->right);
					}
				}
				// Checks if the tree only had one node
				if (!current)
					return (current);
				current->updateHeight();
				// Checks if we need rotation
				if (_rotateNodeErase(current))
					return (current->parent);
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
				std::cout << "SWAPNODES" << std::endl;
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

		public:
			void	printshit()
			{
				print_tree();
			}

			void	debug()
			{
				debugRecursive(this->_root);
			}

			void	debugRecursive(node	*root)
			{
				if (!root)
					return ;
				debugRecursive(root->left);
				printdebug(root);
				debugRecursive(root->right);
			}

			void	printdebug(node *node)
			{
				if (node->parent)
					std::cout << "Key: " << node->data.first << " has parent key: "
						<< node->parent->data.first << std::endl;
				else
					std::cout << "Key: " << node->data.first << " has no parent" << std::endl;
			}

		private:
			void	print_node(std::string root_path)
			{
				node	*tmp = this->_root;

				std::cout << ".";
				if (!tmp)
					return ;
				for (int i = 0; root_path[i]; ++i){
					if (root_path[i] == 'L'){
						if (tmp->left == NULL)
							return ;
						tmp = tmp->left;
					}
					if (root_path[i] == 'R'){
						if (tmp->right == NULL)
							return ;
						tmp = tmp->right;
					}
				}
				if (tmp->data.first)
				{
					std::cout << tmp->height << CRED << tmp->data.first << CRESET;
				}
			}

			void	print_tree()
			{
				std::string root_path;
				int	layer = 0;
				root_path = "";
				int starting_tabs = 16;
				int starting_gap = 16;
				while (layer < 5)
				{
					root_path.clear();
					int tmp_tabs = starting_tabs;
					int tmp_gap = starting_gap;
					for (int tmp_layer = layer; tmp_layer; --tmp_layer)
					{
						root_path.append("L");
						tmp_gap = tmp_gap / 2;
						tmp_tabs -= tmp_gap;
					}
					while (root_path.find('L') != std::string::npos)
					{
						if (root_path.find('R') == std::string::npos)
							for (; tmp_tabs; --tmp_tabs)
								std::cout << "   ";
						else 
							for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
								std::cout << "   ";
						print_node(root_path);
						size_t L_found = root_path.find_last_of('L');
						root_path[L_found] = 'R';
						++L_found;
						for (;L_found != root_path.size(); ++L_found){
							root_path[L_found] = 'L';
						}
					}
					if (root_path.find('R') == std::string::npos)
						for (; tmp_tabs; --tmp_tabs)
							std::cout << "   ";
					else 
						for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
							std::cout << "   ";
					print_node(root_path);
					std::cout << std::endl << std::endl << std::endl;
					layer++;
				}
			}
	};
}
#endif

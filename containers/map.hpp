/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:31:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/18 14:40:39 by rpet          ########   odam.nl         */
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
			map(const map &x) : _compare(x._compare), _allocator(x._allocator)
			{
				_constructorSetup();
				*this = x;
			}

			// Destructor
			~map()
			{
			}

			// Assignment operator
			map	&operator=(const map &x)
			{
				this->_size = x._size;
				this->_root = x._root;
				this->_firstSentinel = x._firstSentinel;
				this->_lastSentinel = x._lastSentinel;
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
				return ((*((insert(ft::make_pair(k, mapped_type()))).first)).data.second);
			}

		///////////////
		// MODIFIERS //
		///////////////

		public:

			void	printshit()
			{
				print_tree();
			}

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

			// Inserts a new node if possible
			node	*_insertNode(const value_type &val, node *current, node *parent)
			{
				key_type	key = val.first;

				if (!current)
					return (_createNode(val, parent));
				if (this->_compare(key, current->data.first))
					current->left = _insertNode(val, current->left, current);
				else if (this->_compare(current->data.first, key))
					current->right = _insertNode(val, current->right, current);
				else
					return (current);
				current->updateHeight();
				if (_rotateNode(key, current))
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
				this->_firstSentinel.parent = this->_root;
				this->_lastSentinel.parent = this->_root;
				return (newNode);
			}

			// Checks if a rotation is necessarry
			bool	_rotateNode(const key_type &key, node *current)
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

		private:
			void	print_node(std::string root_path)
			{
				node	*tmp = this->_root;

				std::cout << ".";
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

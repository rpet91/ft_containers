/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/03 09:59:37 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/18 14:36:14 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP
# include <iostream> //shit

namespace ft
{
	template <class T>
	class MapNode
	{
		public:
			MapNode() : parent(0), left(0), right(0), first(0),
			last(0), data(T()), height(1)
			{
			}

			MapNode(T const &data) : parent(0), left(0), right(0), first(0),
			last(0), data(data), height(1)
			{
			}

			~MapNode()
			{
			}

			MapNode(MapNode const &src)
			{
				*this = src;
			}

			MapNode	&operator=(MapNode const &src)
			{
				this->parent = src.parent;
				this->left = src.left;
				this->right = src.right;
				this->first = src.first;
				this->last = src.last;
				this->data = src.data;
				this->height = src.height;
				return (*this);
			}

			MapNode	*nextNode()
			{
				MapNode	*ret = this;

				if (this->right || this == this->first)
				{
					if (this == this->first)
					{
						ret = this->parent;
						if (!ret)
							return (this->last);
					}
					else
						ret = this->right;
					while (ret->left)
						ret = ret->left;
				}
				else
				{
					while (ret->parent && ret->parent->right == ret)
						ret = ret->parent;
					if (ret->parent)
						ret = ret->parent;
					else
						ret = ret->last;
				}
				return (ret);
			}

			MapNode	*prevNode()
			{
				MapNode	*ret = this;

				if (this->left || this == this->last)
				{
					if (this == this->last)
					{
						ret = this->parent;
						if (!ret)
							return (this->first);
					}
					else
						ret = this->left;
					while (ret->right)
						ret = ret->right;
				}
				else
				{
					while (ret->parent && ret->parent->left == ret)
						ret = ret->parent;
					if (ret->parent)
						ret = ret->parent;
					else
						ret = ret->first;
				}
				return (ret);
			}

			// Public member variables
				MapNode		*parent;
				MapNode		*left;
				MapNode		*right;
				MapNode		*first;
				MapNode		*last;
				T			data;
				int			height;

			// Gets the current height of the node
			int		getHeight(MapNode *current)
			{
				if (!current)
					return (0);
				return (current->height);
			}

			// Returns the max height between the left and right node
			int		getMax(int a, int b)
			{
				return ((a > b) ? a : b);
			}

			// Updates the height of the node
			void	updateHeight()
			{
				this->height = 1 + getMax(getHeight(this->left), getHeight(this->right));
			}

			// Returns the difference between the left and right node
			int		getBalance()
			{
				return (getHeight(this->left) - getHeight(this->right));
			}

			// Rotates the left branch to the right
			void	rightRotate()
			{
				MapNode		*leftNode = this->left;
				MapNode		*leftRightNode = this->left->right;

				leftNode->right = this;
				this->left = leftRightNode;
				if (leftRightNode)
					leftRightNode->parent = this;
				leftNode->parent = this->parent;
				this->parent = leftNode;
				if (leftNode->parent)
				{
					if (leftNode->parent->left == this)
						leftNode->parent->left = leftNode;
					else
						leftNode->parent->right = leftNode;
				}
				this->updateHeight();
				leftNode->updateHeight();
			}

			// Rotates the right branch to the left
			void	leftRotate()
			{
				MapNode		*rightNode = this->right;
				MapNode		*rightLeftNode = this->right->left;

				rightNode->left = this;
				this->right = rightLeftNode;
				if (rightLeftNode)
					rightLeftNode->parent = this;
				rightNode->parent = this->parent;
				this->parent = rightNode;
				if (rightNode->parent)
				{
					if (rightNode->parent->left == this)
						rightNode->parent->left = rightNode;
					else
						rightNode->parent->right = rightNode;
				}
				this->updateHeight();
				rightNode->updateHeight();
			}
	};
}

#endif

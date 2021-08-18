/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 09:47:50 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/18 11:58:13 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

namespace ft
{
	template < typename T >
	class ListNode
	{
		public:
			ListNode()
			{
			}

			ListNode(T const &data) : data(data), next(0), prev(0)
			{
			}

			virtual ~ListNode()
			{
			}

			ListNode(ListNode const &src)
			{
				*this = src;
			}

			ListNode	&operator=(ListNode const &src)
			{
				this->next = src.next;
				this->prev = src.prev;
				this->data = src.data;
				return (*this);
			}

			ListNode	*nextNode()
			{
				return (this->next);
			}

			ListNode	*prevNode()
			{
				return (this->prev);
			}

			bool		operator==(ListNode const &src)
			{
				return (this->data == src.data && this->next == src.next
						&& this->prev == src.prev);
			}

			bool		operator!=(ListNode const &src)
			{
				return (this->data != src.data || this->next != src.next
						|| this->prev != src.prev);
			}

		// Public member variables
			T			data;
			ListNode	*next;
			ListNode	*prev;

	};
}

#endif

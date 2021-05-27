/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 09:47:50 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/27 09:06:29 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

namespace ft
{
	template < typename T >
	class ListNode {
		public:
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

			T			data;
			ListNode	*next;
			ListNode	*prev;

		private:
			ListNode()
			{
			}

	};
}

#endif

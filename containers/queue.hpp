/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:31:53 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/25 11:14:40 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP
# include <deque>
# include <cstddef>

namespace ft
{
	template < class T, class Container = std::deque<T> >
	class queue
	{
		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type		c;

		////////////////////////////////////////////////////
		// CONSTRUCTORS, DESTRUCTOR & ASSIGNMENT OPERATOR //
		////////////////////////////////////////////////////

		public:
			// Default constructor
			explicit queue(const container_type &ctnr = container_type()) : c(ctnr)
			{
			}

			// Copy constructor
			queue(const queue &other) : c(other.c)
			{
			}

			// Destructor
			virtual ~queue()
			{
			}

			// Assignment operator
			queue	&operator=(const queue &other)
			{
				this->c = other.c;
				return (*this);
			}

		//////////////
		// CAPACITY //
		//////////////

		public:
			// Empty
			bool		empty() const
			{
				return (this->c.empty());
			}

			// Size
			size_type	size() const
			{
				return (this->c.size());
			}

		////////////////////
		// ELEMENT ACCESS //
		////////////////////

		public:
			// Front
			value_type			&front()
			{
				return (this->c.front());
			}

			const value_type	&front() const
			{
				return (this->c.front());
			}

			// Back
			value_type			&back()
			{
				return (this->c.back());
			}
			
			const value_type	&back() const
			{
				return (this->c.back());
			}

		///////////////
		// MODIFIERS //
		///////////////

		public:
			// Push
			void	push(const value_type &val)
			{
				this->c.push_back(val);
			}

			// Pop
			void	pop()
			{
				this->c.pop_front();
			}

		/////////////////////////
		// FRIEND DECLARATIONS //
		/////////////////////////

		public:
		// ==
		template <class T1, class Container1>
		friend bool operator==(const queue<T1, Container1>& lhs, const queue<T1, Container1>& rhs); 
		
		// <
		template <class T1, class Container1>
		friend bool operator<(const queue<T1, Container1>& lhs, const queue<T1, Container1>& rhs); 
	};

	///////////////////////////////////
	// NON-MEMBER FUNCTION OVERLOADS //
	///////////////////////////////////

	// Relational operators
	template <class T, class Container>
	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	
	template <class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return !(lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return !(rhs.c < lhs.c);
	}

	template <class T, class Container>
	bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (rhs.c < lhs.c);
	}

	template <class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}
}

#endif

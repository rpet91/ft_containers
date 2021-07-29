/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:31:28 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/26 13:07:29 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include <deque>
# include <cstddef>

namespace ft
{
	template < class T, class Container = std::deque<T> >
	class stack
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
			explicit stack(const container_type &ctnr = container_type()) : c(ctnr)
			{
			}

			// Copy constructor
			stack(const stack &other) : c(other.c)
			{
			}

			// Destructor
			~stack()
			{
			}

			// Assignment operator
			stack	&operator=(const stack &other)
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
			// Top
			value_type			&top()
			{
				return (this->c.back());
			}

			const value_type	&top() const
			{
				return (this->c.back());
			}

		///////////////
		// MODIFIERS //
		///////////////

		public:
			// Push
			void				push(const value_type &val)
			{
				this->c.push_back(val);
			}

			// Pop
			void				pop()
			{
				this->c.pop_back();
			}

		/////////////////////////
		// FRIEND DECLARATIONS //
		/////////////////////////

		public:
		// ==
		template <class T1, class Container1>
		friend bool operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

		// <
		template <class T1, class Container1>
		friend bool operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	};

	///////////////////////////////////
	// NON-MEMBER FUNCTION OVERLOADS //
	///////////////////////////////////

	// Relational operators
	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs.c < lhs.c);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs.c < lhs.c);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 14:27:41 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/26 07:44:49 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		//////////////////
		// MEMBER TYPES //
		//////////////////

		public:
			typedef T1		first_type;
			typedef T2		second_type;

		// public member variables
			first_type		first;
			second_type		second;
		
		//////////////////////
		// MEMBER FUNCTIONS //
		//////////////////////

		public:
			// Default constructor
			pair() : first(T1()), second(T2())
			{
			}

			// Copy constructor
			template<class U, class V>
			pair(const pair<U,V> &pr) : first(pr.first), second(pr.second)
			{
			}

			// Initialization constructor
			pair(const first_type &a, const second_type &b) : first(a), second(b)
			{
			}

			// Destructor
			virtual ~pair()
			{
			}

			// Assignment operator
			pair	&operator=(const pair &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
				return (*this);
			}
	};

	///////////////////////////////////
	// NON-MEMBER FUNCTION OVERLOADS //
	///////////////////////////////////
	
		// Relational operators
		template <class T1, class T2>
		bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
		{
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}
		
		template <class T1, class T2>
		bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
		{
			return !(lhs == rhs);
		}
		
		template <class T1, class T2>
		bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
		{
			return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
		}
		
		template <class T1, class T2>
		bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
		{
			return !(rhs < lhs);
		}
		
		template <class T1, class T2>
		bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
		{
			return (rhs < lhs);
		}
		
		template <class T1, class T2>
		bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
		{
			return !(lhs < rhs);
		}

		// Make pair
		template <class T1, class T2>
		pair<T1,T2> make_pair(T1 x, T2 y)
		{
			return (pair<T1,T2>(x, y));
		}
}

#endif

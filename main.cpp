/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/07 13:39:54 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "ListNode.hpp"
#include "ListIterator.hpp"
#include <iostream>
#include <list>

int		main()
{
	ft::list<int>		lst1(5, 10);
	std::list<int>		real(5, 10);

	lst1.push_front(16);
	lst1.push_back(42);
	real.push_front(16);
	real.push_back(42);
	lst1.debug();
	
	ft::list<int>::iterator				it = lst1.begin();
	ft::list<int>::const_iterator		itc = lst1.begin();
	ft::list<int>::iterator				ite = lst1.end();
	ft::list<int>::const_iterator		itce = lst1.end();
	ft::list<int>::reverse_iterator		rit = lst1.rbegin();
	std::list<int>::reverse_iterator	realrit = real.rbegin();

	std::cout << "lst1.begin(): " << *it << std::endl;
	std::cout << "lst1.const_begin(): " << *itc << std::endl;
	std::cout << "lst1.end(): " << *ite << std::endl;
	std::cout << "lst1.const_end(): " << *itce << std::endl;

	rit++;
	realrit++;
	std::cout << "lst1.rbegin(): " << *rit << std::endl;

	std::cout << "real.rbegin(): " << *realrit << std::endl;

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/07 10:55:50 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "ListNode.hpp"
//#include "Iterator.hpp"
//#include "BidirectionalIterator.hpp"
#include "ListIterator.hpp"
#include <iostream>
#include <list>

int		main()
{
	ft::list<int>				lst1(5, 10);
	std::list<int>				real(5, 10);

	lst1.push_front(16);
	lst1.push_back(42);
	lst1.debug();
	real.push_front(16);
	real.push_back(42);
	
	ft::list<int>::iterator		it = lst1.begin();
	ft::list<int>::iterator		ite = lst1.end();
	std::list<int>::iterator	realit = real.begin();
	std::list<int>::iterator	realite = real.end();

	std::cout << "lst1.begin(): " << *it << std::endl;
	std::cout << "real.begin(): " << *realit << std::endl;
	
	ite--;
	realite--;

	std::cout << "lst1.end(): " << *ite << std::endl;
	std::cout << "real.end(): " << *realite << std::endl;

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

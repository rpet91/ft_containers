/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/09 12:45:52 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "ListNode.hpp"
#include "ListIterator.hpp"
#include "BidirectionalIterator.hpp"
#include "Iterator.hpp"
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
	//lst1.debug();
	
	ft::list<int>				test(13, 22);
	ft::list<int>::iterator		it1 = lst1.begin();
	ft::list<int>::iterator		it2 = lst1.end();

	test.assign(it1, it2);

	test.debug();
	

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

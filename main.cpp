/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/16 14:39:46 by rpet          ########   odam.nl         */
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
	ft::list<int>		lst1;
	std::list<int>		real;

	for (size_t i = 0; i <= 20; i+=5)
	{
		lst1.push_back(i);
		real.push_back(i);
	}

	ft::list<int>::iterator			it1 = lst1.begin();
	ft::list<int>::iterator			it2 = it1;
	std::list<int>::iterator		realit1 = real.begin();
	std::list<int>::iterator		realit2 = realit1;

	for (int i = 0; i < 2; i++)
	{
		it2++;
		realit2++;
	}
	std::cout << *lst1.insert(it2, 1337) << std::endl;
	std::cout << *real.insert(realit2, 1337) << std::endl;
	std::cout << *lst1.insert(it2, 1337) << std::endl;
	std::cout << *real.insert(realit2, 1337) << std::endl;

	std::cout << std::endl;
	for (size_t i = 0; i < real.size(); i++)
	{
		std::cout << *realit1 << std::endl;
		realit1++;
	}
	lst1.push_back(69);

	lst1.debug();

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

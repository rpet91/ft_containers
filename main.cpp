/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/27 09:27:30 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "ListNode.hpp"
#include <iostream>
#include <list>

int		main()
{
	ft::list<int>			lst1(6, 13);
	ft::list<int>::iterator	it = lst1.begin();

	lst1.debug();
	std::cout << *it << std::endl;

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

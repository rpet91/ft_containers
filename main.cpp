/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/26 14:46:29 by rpet          ########   odam.nl         */
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
	ft::list<int>	lst1(2, 13);

	lst1.debug();
	lst1.resize(5, 42);
	lst1.debug();

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

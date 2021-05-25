/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/05/25 14:45:47 by rpet          ########   odam.nl         */
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
//	ft::list<int>	lst1;
	ft::list<int>	lst2(5, 13);
	
//	lst1.debug();
	lst2.debug();
	lst2.push_front(1);
	lst2.debug();
	lst2.push_back(1336);
	lst2.debug();
	lst2.push_back(52);
	lst2.debug();
	lst2.pop_back();
	lst2.debug();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 09:31:42 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/02 13:51:30 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>

static void	printHelpList()
{
	std::cout << "For the list functions you can choose the following options:" << std::endl;
	std::cout << "    " << "CONSTRUCTORS:" << std::endl;
	std::cout << "\t" << "- constructor" << std::endl;
	std::cout << "    " << "ITERATORS:" << std::endl;
	std::cout << "\t" << "- begin" << std::endl;
	std::cout << "\t" << "- end" << std::endl;
	std::cout << "\t" << "- rbegin" << std::endl;
	std::cout << "\t" << "- rend" << std::endl;
	std::cout << "    " << "CAPACITY:" << std::endl;
	std::cout << "\t" << "- empty" << std::endl;
	std::cout << "\t" << "- size" << std::endl;
	std::cout << "\t" << "- max_size" << std::endl;
	std::cout << "    " << "ELEMENT ACCESS:" << std::endl;
	std::cout << "\t" << "- front" << std::endl;
	std::cout << "\t" << "- back" << std::endl;
	std::cout << "    " << "MODIFIERS:" << std::endl;
	std::cout << "\t" << "- assign" << std::endl;
	std::cout << "\t" << "- push_front" << std::endl;
	std::cout << "\t" << "- pop_front" << std::endl;
	std::cout << "\t" << "- push_back" << std::endl;
	std::cout << "\t" << "- pop_back" << std::endl;
	std::cout << "\t" << "- insert" << std::endl;
	std::cout << "\t" << "- erase" << std::endl;
	std::cout << "\t" << "- swap" << std::endl;
	std::cout << "\t" << "- resize" << std::endl;
	std::cout << "\t" << "- clear" << std::endl;
	std::cout << "    " << "OPERATIONS:" << std::endl;
	std::cout << "\t" << "- splice" << std::endl;
	std::cout << "\t" << "- remove" << std::endl;
	std::cout << "\t" << "- remove_if" << std::endl;
	std::cout << "\t" << "- unique" << std::endl;
	std::cout << "\t" << "- merge" << std::endl;
	std::cout << "\t" << "- sort" << std::endl;
	std::cout << "\t" << "- reverse" << std::endl;
	std::cout << "    " << "OBSERVERS:" << std::endl;
	std::cout << "\t" << "- get_allocator" << std::endl;
	std::cout << "    " << "NON-MEMBER FUNCTION OVERLOADS:" << std::endl;
	std::cout << "\t" << "- relational_operators" << std::endl;
	std::cout << "\t" << "- swap_overload" << std::endl;
	std::cout << "    " << "ALL FUNCTIONS:" << std::endl;
	std::cout << "\t" << "- all" << std::endl;
}

void	printHelpVector()
{
	std::cout << "For the vector functions you can choose the following options:" << std::endl;
	std::cout << "    " << "CONSTRUCTORS:" << std::endl;
	std::cout << "\t" << "- constructor" << std::endl;
	std::cout << "    " << "ITERATORS:" << std::endl;
	std::cout << "\t" << "- begin" << std::endl;
	std::cout << "\t" << "- end" << std::endl;
	std::cout << "\t" << "- rbegin" << std::endl;
	std::cout << "\t" << "- rend" << std::endl;
	std::cout << "    " << "CAPACITY:" << std::endl;
	std::cout << "\t" << "- size" << std::endl;
	std::cout << "\t" << "- max_size" << std::endl;
	std::cout << "\t" << "- resize" << std::endl;
	std::cout << "\t" << "- capacity" << std::endl;
	std::cout << "\t" << "- empty" << std::endl;
	std::cout << "\t" << "- reserve" << std::endl;
	std::cout << "    " << "ELEMENT ACCESS:" << std::endl;
	std::cout << "\t" << "- operator_subscript" << std::endl;
	std::cout << "\t" << "- at" << std::endl;
	std::cout << "\t" << "- front" << std::endl;
	std::cout << "\t" << "- back" << std::endl;
	std::cout << "    " << "MODIFIERS:" << std::endl;
	std::cout << "\t" << "- assign" << std::endl;
	std::cout << "\t" << "- push_back" << std::endl;
	std::cout << "\t" << "- pop_back" << std::endl;
	std::cout << "\t" << "- insert" << std::endl;
	std::cout << "\t" << "- erase" << std::endl;
	std::cout << "\t" << "- swap" << std::endl;
	std::cout << "\t" << "- clear" << std::endl;
	std::cout << "    " << "ALLOCATOR:" << std::endl;
	std::cout << "\t" << "- get_allocator" << std::endl;
	std::cout << "    " << "NON-MEMBER FUNCTION OVERLOADS:" << std::endl;
	std::cout << "\t" << "- relational_operators" << std::endl;
	std::cout << "\t" << "- swap_overload" << std::endl;
	std::cout << "    " << "ALL FUNCTIONS:" << std::endl;
	std::cout << "\t" << "- all" << std::endl;
}

//void	printHelpMap()
//{
//}

//void	printHelpStack()
//{
//}

//void	printHelpQueue()
//{
//}

void	printHelp()
{
	std::cout << "For the first argument you can choose the following containers:" << std::endl;
	std::cout << "\t- list" << std::endl;
	std::cout << "\t- vector" << std::endl;
	std::cout << "\t- map" << std::endl;
	std::cout << "\t- stack" << std::endl;
	std::cout << "\t- queue" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "\tType \"container_name\" help to see more options." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}

void	printHelpContainer(std::string container)
{
	if (container == "list")
		printHelpList();
	if (container == "vector")
		printHelpVector();
//	if (container == "map")
//		printHelpMap();
//	if (container == "stack")
//		printHelpStack();
//	if (container == "queue")
//		printHelpQueue();
}

void	testContainer(std::string container, std::string function)
{
	if (container == "list")
		testList(function);
	if (container == "vector")
		testVector(function);
//	if (container == "map")
//		testMap(function);
//	if (container == "stack")
//		testStack(function);
//	if (container == "queue")
//		testQueue(function);
}

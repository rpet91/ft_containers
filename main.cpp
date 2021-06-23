/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 07:26:12 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/23 07:20:15 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "tests.hpp"
#include <iostream>
#include <list>

void	checkLeaks()
{
	system("leaks ft_containers");	
}

int		validContainer(std::string choice)
{
	std::string		containers[] = {"list", "vector", "map", "stack", "queue"};

	for (size_t i = 0; i < (sizeof(containers) / sizeof(std::string)); i++)
		if (choice == containers[i])
			return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	atexit(checkLeaks);

	if (argc != 3)
	{
		if (argc == 2 && static_cast<std::string>(argv[1]) == "help")
			printHelp();
		else
			std::cout << "Program needs specific arguments, type \"help\" for more options." << std::endl;
		return (0);
	}
	if (validContainer(argv[1]) && static_cast<std::string>(argv[2]) == "help")
		printHelpContainer(argv[1]);
	else if (validContainer(argv[1]))
		testContainer(argv[1], argv[2]);
	else
		std::cout << "Program needs specific arguments, type \"help\" for more options." << std::endl;

// Testing for leaks and calling destructor manually
//	lst1.~list();
//	while(1);
	return (0);
}

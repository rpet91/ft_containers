/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testList.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 09:37:56 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/18 11:48:18 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <iostream>
#include <map>

static void	constructor()
{
}

static void	begin()
{
}

static void	end()
{
}

void		testList(std::string choice)
{
	typedef void	(*test)();

	std::map<std::string, test>		functions;

	functions["constructor"] = constructor;
	functions["begin"] = begin;
	functions["end"] = end;
//	functions["rbegin"] = rbegin;
//	functions["rend"] = rend;
//	functions["empty"] = empty;
//	functions["size"] = size;
//	functions["max_size"] = max_size;
//	functions["front"] = front;
//	functions["back"] = back;
//	functions["assign"] = assign;
//	functions["push_front"] = push_front;
//	functions["pop_front"] = pop_front;
//	functions["push_back"] = push_back;

	if (functions.find(choice) != functions.end())
		functions[choice]();
	else
	{
		std::cout << "The chosen function does not exist. Type \"list help\"";
   		std::cout << " for a list of valid options." << std::endl;
	}
}

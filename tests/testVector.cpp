/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testVector.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 09:36:54 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/28 09:53:19 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <map>

static void		constructor()
{
}

static void		begin()
{
}

static void		end()
{
}

static void		rbegin()
{
}

static void		rend()
{
}

static void		size()
{
}

static void		max_size()
{
}

static void		resize()
{
}

static void		capacity()
{
}

static void		empty()
{
}

static void		reserve()
{
}

static void		operator_subscript()
{
}

static void		at()
{
}

static void		front()
{
}

static void		back()
{
}

static void		assign()
{
}

static void		push_back()
{
}

static void		pop_back()
{
}

static void		insert()
{
}

static void		erase()
{
}

static void		swap()
{
}

static void		clear()
{
}

static void		get_allocator()
{
}

static void		relational_operators()
{
}

static void		swap_overload()
{
}

static void		vector_bool()
{
}

static void		all()
{
	constructor();
	begin();
	end();
	rbegin();
	rend();
	size();
	max_size();
	resize();
	capacity();
	empty();
	reserve();
	operator_subscript();
	at();
	front();
	back();
	assign();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
	clear();
	get_allocator();
	relational_operators();
	swap_overload();
	vector_bool();
}

void			testVector(std::string choice)
{
	typedef void	(*test)();
	std::map<std::string, test>		functions;

	functions["constructor"] = constructor;
	functions["begin"] = begin;
	functions["end"] = end;
	functions["rbegin"] = rbegin;
	functions["rend"] = rend;
	functions["size"] = size;
	functions["max_size"] = max_size;
	functions["resize"] = resize;
	functions["capacity"] = capacity;
	functions["empty"] = empty;
	functions["reserve"] = reserve;
	functions["operator_subscript"] = operator_subscript;
	functions["at"] = at;
	functions["front"] = front;
	functions["back"] = back;
	functions["assign"] = assign;
	functions["push_back"] = push_back;
	functions["pop_back"] = pop_back;
	functions["insert"] = insert;
	functions["erase"] = erase;
	functions["swap"] = swap;
	functions["clear"] = clear;
	functions["get_allocator"] = get_allocator;
	functions["relational_operators"] = relational_operators;
	functions["swap_overload"] = swap_overload;
	functions["vector_bool"] = vector_bool;
	functions["all"] = all;

	if (functions.find(choice) != functions.end())
		functions[choice]();
	else
	{
		std::cout << "The function \"" << choice <<
			"\" doesn't exist. Type \"vector help\" for a list of options." << std::endl;
	}
}

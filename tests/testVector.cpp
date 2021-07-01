/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testVector.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 09:36:54 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/01 13:53:47 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <map>

// TESTER HELPER FUNCTIONS

template <typename T>
static void		setup(T &vector)
{
	for (size_t i = 1; i < 4; i++)
		vector.push_back(i * 5);
}

template <typename T>
static void		print(T &vector)
{
	typename	T::iterator		cur = vector.begin();

	std::cout << "Current Vector has a size of: " << vector.size() <<
		" and a capacity of: " << vector.capacity() << std::endl;
	for (size_t i = 0; cur != vector.end(); i++, cur++)
		std::cout << "Index [" << i << "]: " << *cur << std::endl;
}

static void		constructor()
{
	std::cout << "\t===CONSTRUCTOR===" << std::endl;
	std::vector<int>		defaultConstructor;
	std::vector<int>		fillConstructor(5, 10);
//	ft::vector<int>		rangeConstructor(fillConstructor.begin(), fillConstructor.end();
//	ft::vector<int>		copyConstructor(fillConstructor);

	std::cout << "Default constructor:" << std::endl;
	print(defaultConstructor);
	std::cout << "Fill constructor:" << std::endl;
	print(fillConstructor);
//	std::cout << "Range constructor:" << std::endl;
//	print(rangeConstructor);
//	std::cout << "Copy constructor:" << std::endl;
//	print(copyConstructor);
	std::cout << std::endl;
}

static void		begin()
{
	std::cout << "\t===BEGIN===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	ft::vector<int>::iterator			itMine = vectorMine.begin();
	ft::vector<int>::const_iterator		itConstMine = vectorMine.begin();
	std::vector<int>::iterator			itReal = vectorReal.begin();
	std::vector<int>::const_iterator	itConstReal = vectorReal.begin();

	std::cout << "Mine: " << *itMine << std::endl;
	std::cout << "Const Mine: " << *itConstMine << std::endl;
	std::cout << "Real: " << *itReal << std::endl;
	std::cout << "Const Real: " << *itConstReal << std::endl;
	std::cout << std::endl;
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
	std::cout << "\t===SIZE===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Mine: " << vectorMine.size() << std::endl;
	std::cout << "Real: " << vectorReal.size() << std::endl;
	std::cout << std::endl;
}

static void		max_size()
{
}

static void		resize()
{
	std::cout << "\t===RESIZE===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

//	std::cout << "Before Mine: " << std::endl;
//	print(vectorMine);
	std::cout << "Before After: " << std::endl;
	print(vectorReal);

//	vectorMine.resize(2);	
	vectorReal.resize(5);	
	
//	std::cout << "Before Mine: " << std::endl;
//	print(vectorMine);
	std::cout << "Before After: " << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		capacity()
{
	std::cout << "\t===CAPACITY===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);
//	ft::vector<int>	vectorMine2(vectorMine);
	std::vector<int>	vectorReal2(vectorReal);

	std::cout << "Mine: " << vectorMine.capacity() << std::endl;
//	std::cout << "Mine2: " << vectorMine2.capacity() << std::endl;
	std::cout << "Real: " << vectorReal.capacity() << std::endl;
	std::cout << "Real2: " << vectorReal2.capacity() << std::endl;
	std::cout << std::endl;
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

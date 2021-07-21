/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testVector.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/28 09:36:54 by rpet          #+#    #+#                 */
/*   Updated: 2021/07/21 12:32:10 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <exception>
#include <cmath>
#include <climits>

// TESTER HELPER FUNCTIONS

template <typename T>
static void		setup(T &vector)
{
	for (size_t i = 1; i < 5; i++)
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

template <typename T>
static void printAddress(T &vector)
{
	typename T::iterator	cur = vector.begin();

	for (size_t i = 0; cur != vector.end(); i++, cur++)
		std::cout << "Index [" << i << "]: " << &*cur << std::endl;
}

static int	getRandomNumber()
{
	return(rand() % 1337);
}

static void		constructor()
{
	std::cout << "\t===CONSTRUCTOR===" << std::endl;
	ft::vector<int>		defaultConstructor;
	ft::vector<int>		fillConstructor(5, 10);
	ft::vector<int>		rangeConstructor(fillConstructor.begin(), fillConstructor.end());
	ft::vector<int>		copyConstructor(fillConstructor);
	std::cout << "Default constructor:" << std::endl;

	print(defaultConstructor);
	std::cout << "Fill constructor:" << std::endl;
	print(fillConstructor);
	std::cout << "Range constructor:" << std::endl;
	print(rangeConstructor);
	std::cout << "Copy constructor:" << std::endl;
	print(copyConstructor);
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

	itMine++;
	itConstMine++;
	itReal++;
	itConstReal++;
	std::cout << "Mine Begin: " << *itMine << std::endl;
	std::cout << "Const Mine Begin: " << *itConstMine << std::endl;
	std::cout << "Real Begin: " << *itReal << std::endl;
	std::cout << "Const Real Begin: " << *itConstReal << std::endl;
	std::cout << std::endl;
}

static void		end()
{
	std::cout << "\t===END===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	ft::vector<int>::iterator			itMine = vectorMine.end();
	ft::vector<int>::const_iterator		itConstMine = vectorMine.end();
	std::vector<int>::iterator			itReal = vectorReal.end();
	std::vector<int>::const_iterator	itConstReal = vectorReal.end();

	itMine--;
	itConstMine--;
	itReal--;
	itConstReal--;
	std::cout << "Mine End: " << *itMine << std::endl;
	std::cout << "Const Mine End: " << *itConstMine << std::endl;
	std::cout << "Real End: " << *itReal << std::endl;
	std::cout << "Const Real End: " << *itConstReal << std::endl;
	std::cout << std::endl;
}

static void		rbegin()
{
	std::cout << "\t===RBEGIN===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	ft::vector<int>::reverse_iterator			itMine = vectorMine.rbegin();
	ft::vector<int>::const_reverse_iterator		itConstMine = vectorMine.rbegin();
	std::vector<int>::reverse_iterator			itReal = vectorReal.rbegin();
	std::vector<int>::const_reverse_iterator	itConstReal = vectorReal.rbegin();

	itMine++;
	itConstMine++;
	itReal++;
	itConstReal++;
	std::cout << "Mine Rbegin: " << *itMine << std::endl;
	std::cout << "Const Mine Rbegin: " << *itConstMine << std::endl;
	std::cout << "Real Rbegin: " << *itReal << std::endl;
	std::cout << "Const Real Rbegin: " << *itConstReal << std::endl;
	std::cout << std::endl;
}

static void		rend()
{
	std::cout << "\t===REND===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	ft::vector<int>::reverse_iterator			itMine = vectorMine.rend();
	ft::vector<int>::const_reverse_iterator		itConstMine = vectorMine.rend();
	std::vector<int>::reverse_iterator			itReal = vectorReal.rend();
	std::vector<int>::const_reverse_iterator	itConstReal = vectorReal.rend();

	itMine--;
	itConstMine--;
	itReal--;
	itConstReal--;
	std::cout << "Mine Rend: " << *itMine << std::endl;
	std::cout << "Const Mine Rend: " << *itConstMine << std::endl;
	std::cout << "Real Rend: " << *itReal << std::endl;
	std::cout << "Const Real Rend: " << *itConstReal << std::endl;
	std::cout << std::endl;
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
	std::cout << "\t===MAX SIZE===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Mine: " << vectorMine.max_size() << std::endl;
	std::cout << "Real: " << vectorReal.max_size() << std::endl;
	std::cout << std::endl;
}

static void		resize()
{
	std::cout << "\t===RESIZE===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Before Mine: " << std::endl;
	print(vectorMine);
	std::cout << "Before Real: " << std::endl;
	print(vectorReal);

	vectorMine.resize(9);	
	vectorReal.resize(9);
	
	std::cout << "After Mine: " << std::endl;
	print(vectorMine);
	std::cout << "After Real: " << std::endl;
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

	std::cout << "Size 3 Mine: " << vectorMine.capacity() << std::endl;
	print(vectorMine);
	std::cout << "Size 3 Real: " << vectorReal.capacity() << std::endl;
	print(vectorReal);

	vectorMine.push_back(1337);
	vectorMine.push_back(1337);
	vectorReal.push_back(1337);
	vectorReal.push_back(1337);
	
	std::cout << "Size 5 Mine: " << vectorMine.capacity() << std::endl;
	print(vectorMine);
	std::cout << "Size 5 Real: " << vectorReal.capacity() << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		empty()
{
	std::cout << "\t===EMPTY===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Empty Mine: " << vectorMine.empty() << std::endl;
	std::cout << "Empty Real: " << vectorMine.empty() << std::endl;

	vectorMine.clear();
	vectorReal.clear();

	std::cout << "Empty Mine: " << vectorMine.empty() << std::endl;
	std::cout << "Empty Real: " << vectorMine.empty() << std::endl;
	std::cout << std::endl;
}

static void		reserve()
{
	std::cout << "\t===RESERVE===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Reserve Before Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Reserve Before Real:" << std::endl;
	print(vectorReal);

	vectorMine.reserve(69);
	vectorReal.reserve(69);
	
	std::cout << "Reserve After Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Reserve After Real:" << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		operator_subscript()
{
	std::cout << "\t===OPERATOR[] (subscript)===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	for (size_t i = 0; i < vectorMine.size(); i++)
	{
		std::cout << "Mine : " << vectorMine[i] << std::endl;
		std::cout << "Real : " << vectorReal[i] << std::endl;
	}
	std::cout << std::endl;
}

static void		at()
{
	std::cout << "\t===AT====" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	for (size_t i = 0; i < vectorMine.size(); i++)
	{
		std::cout << "Inside Array Mine : " << vectorMine[i] << std::endl;
		std::cout << "Inside Array Real : " << vectorReal[i] << std::endl;
	}
	std::cout << "Outside Array Mine:" << std::endl;
	try
	{
		vectorMine.at(5);
	}
	catch (std::exception &e)
	{
		std::cout << "Mine exception error: " << e.what() << std::endl;
	}
	std::cout << "Outside Array Real:" << std::endl;
	try
	{
		vectorReal.at(5);
	}
	catch (std::exception &e)
	{
		std::cout << "Real exception error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

static void		front()
{
	std::cout << "\t===FRONT===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Mine: " << vectorMine.front() << std::endl;
	std::cout << "Real: " << vectorReal.front() << std::endl;
	std::cout << std::endl;
}

static void		back()
{
	std::cout << "\t===BACK===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Mine: " << vectorMine.back() << std::endl;
	std::cout << "Real: " << vectorReal.back() << std::endl;
	std::cout << std::endl;
}

static void		assign()
{
	std::cout << "\t===ASSIGN===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);
	
	vectorMine.assign(++vectorMine.begin(), --vectorMine.end());
	vectorReal.assign(++vectorReal.begin(), --vectorReal.end());

	std::cout << "Range Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Range Real:" << std::endl;
	print(vectorReal);

	vectorMine.assign(5, 1337);
	vectorReal.assign(5, 1337);

	std::cout << std::endl;
	std::cout << "Fill Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Fill Real:" << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		push_back()
{
	std::cout << "\t===PUSH BACK===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);
	
	std::cout << "Before Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Before Real:" << std::endl;
	print(vectorReal);

	vectorMine.push_back(1337);
	vectorReal.push_back(1337);
	
	std::cout << "After Mine:" << std::endl;
	print(vectorMine);
	std::cout << "After Real:" << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		pop_back()
{
	std::cout << "\t===POP BACK===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);
	
	std::cout << "Before Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Before Real:" << std::endl;
	print(vectorReal);

	vectorMine.pop_back();
	vectorReal.pop_back();
	
	std::cout << "After Mine:" << std::endl;
	print(vectorMine);
	std::cout << "After Real:" << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void	insert()
{
	std::cout << "\t===INSERT===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;

	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Single Element Mine:" << std::endl;
	std::cout << "Inserted element: " << *vectorMine.insert(++vectorMine.begin(), 1337) << std::endl;
	print(vectorMine);
	std::cout << "Single Element Real:" << std::endl;
	std::cout << "Inserted element: " << *vectorReal.insert(++vectorReal.begin(), 1337) << std::endl;
	print(vectorReal);

	vectorMine.insert(++vectorMine.begin(), 3, 69);
	vectorReal.insert(++vectorReal.begin(), 3, 69);

	std::cout << std::endl;
	std::cout << "Fill Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Fill Real:" << std::endl;
	print(vectorReal);

	vectorMine.insert(++vectorMine.begin(), ++vectorMine.begin(), --vectorMine.end());
	vectorReal.insert(++vectorReal.begin(), ++vectorReal.begin(), --vectorReal.end());

	std::cout << std::endl;
	std::cout << "Range Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Range Real:" << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void	erase()
{
	std::cout << "\t===ERASE===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Single Element Mine:" << std::endl;
//	std::cout << "Next: " << *vectorMine.erase(++vectorMine.begin()) << std::endl;
	print(vectorMine);
	std::cout << "Single Element Real:" << std::endl;
	std::cout << "Next: " << *vectorReal.erase(++vectorReal.begin()) << std::endl;
	print(vectorReal);

	std::cout << std::endl;
	std::cout << "Range Mine:" << std::endl;
//	std::cout << "Next: " << *vectorMine.erase(++vectorMine.begin(), --vectorMine.end()) << std::endl;
	print(vectorMine);
	std::cout << "Range Real:" << std::endl;
	std::cout << "Next: " << *vectorReal.erase(++vectorReal.begin(), --vectorReal.end()) << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		swap()
{
	std::cout << "\t===SWAP===" << std::endl;
	ft::vector<int> 	vectorMine;
	ft::vector<int> 	vectorMineSwap;
	std::vector<int>	vectorReal;
	std::vector<int>	vectorRealSwap;
	setup(vectorMine);
	setup(vectorReal);

	for (size_t i = 0; i < 7; i++)
	{
		vectorMineSwap.push_back(i * 3);
		vectorRealSwap.push_back(i * 3);
	}

	std::cout << "Before Mine:" << std::endl;
	printAddress(vectorMine);
	std::cout << "Before Real:" << std::endl;
	printAddress(vectorReal);

	vectorMine.swap(vectorMineSwap);
	vectorReal.swap(vectorRealSwap);

	std::cout << std::endl;
	std::cout << "After Mine:" << std::endl;
	printAddress(vectorMine);
	std::cout << "After Real:" << std::endl;
	printAddress(vectorReal);
	std::cout << std::endl;
}

static void		clear()
{
	std::cout << "\t===CLEAR===" << std::endl;
	ft::vector<int> 	vectorMine;
	std::vector<int>	vectorReal;
	setup(vectorMine);
	setup(vectorReal);

	std::cout << "Before Clear Mine:" << std::endl;
	print(vectorMine);
	std::cout << "Before Clear Real:" << std::endl;
	print(vectorReal);
	
	vectorMine.clear();
	vectorReal.clear();
	
	std::cout << "After Clear Mine:" << std::endl;
	print(vectorMine);
	std::cout << "After Clear Real:" << std::endl;
	print(vectorReal);
	std::cout << std::endl;
}

static void		get_allocator()
{
	std::cout << "\t===GET ALLOCATOR===" << std::endl;
	ft::vector<int> 					vectorMine;
	ft::vector<int>::allocator_type		allocator;

	std::cout << "Big Test" << std::endl;
	allocator = vectorMine.get_allocator();
	std::cout << std::endl;
}

static void		relational_operators()
{
	std::cout << "\t===RELATIONAL OPERATORS===" << std::endl;
	ft::vector<int> 	vectorMine1;
	ft::vector<int>		vectorMine2;
	setup(vectorMine1);
	setup(vectorMine2);

	std::cout << "== Operator:" << std::endl;
	if (vectorMine1 == vectorMine2)
		std::cout << "Check" << std::endl;

	vectorMine1.push_back(1337);
	std::cout << "!= Operator:" << std::endl;
	if (vectorMine1 != vectorMine2)
		std::cout << "Check" << std::endl;

	vectorMine2.push_back(1338);
	std::cout << "< Operator:" << std::endl;
	if (vectorMine1 < vectorMine2)
		std::cout << "Check" << std::endl;

	vectorMine1.pop_back();
	vectorMine1.push_back(1337); // 1337 = true, 1338 = true, 1339 = false
	std::cout << "<= Operator:" << std::endl;
	if (vectorMine1 <= vectorMine2)
		std::cout << "Check" << std::endl;

	std::cout << "> Operator:" << std::endl;
	if (vectorMine1 > vectorMine2)
		std::cout << "Check" << std::endl;

	std::cout << ">= Operator:" << std::endl;
	if (vectorMine1 >= vectorMine2)
		std::cout << "Check" << std::endl;
	std::cout << std::endl;
}


static void		swap_overload()
{
	std::cout << "\t===SWAP OVERLOAD===" << std::endl;
	ft::vector<int> 	vectorMine1;
	ft::vector<int> 	vectorMine2;
	std::vector<int>	vectorReal1;
	std::vector<int>	vectorReal2;

	for (size_t i = 0; i < 6; i++)
	{
		int	nb = getRandomNumber();

		vectorMine1.push_back(nb);
		vectorReal1.push_back(nb);
		nb = getRandomNumber();
		vectorMine2.push_back(nb);
		vectorReal2.push_back(nb);
	}

	std::cout << "Before Swap Overload Mine1:" << std::endl;
	print(vectorMine1);
	std::cout << "Before Swap Overload Real1:" << std::endl;
	print(vectorReal1);

	ft::swap(vectorMine1, vectorMine2);
	std::swap(vectorReal1, vectorReal2);

	std::cout << std::endl;
	std::cout << "After Swap Overload Mine1:" << std::endl;
	print(vectorMine1);
	std::cout << "After Swap Overload Real1:" << std::endl;
	print(vectorReal1);
	std::cout << std::endl;
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
	functions["all"] = all;

	if (functions.find(choice) != functions.end())
		functions[choice]();
	else
	{
		std::cout << "The function \"" << choice <<
			"\" doesn't exist. Type \"vector help\" for a list of options." << std::endl;
	}
}

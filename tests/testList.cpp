/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testList.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 09:37:56 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/23 14:11:11 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
#include <map>
#include <climits>
#include <cmath>

template <typename T>
static void	setup(T &list)
{
	for (size_t i = 1; i < 6; i++)
		list.push_back(i * 5);
}

template <typename T>
static void print(T &list)
{
	typename T::iterator	cur = list.begin();

	for (size_t i = 0; cur != list.end(); i++, cur++)
		std::cout << "Index [" << i << "]: " << *cur << std::endl;
}

template <typename T>
static void printAddress(T &list)
{
	typename T::iterator	cur = list.begin();

	for (size_t i = 0; cur != list.end(); i++, cur++)
		std::cout << "Index [" << i << "]: " << &*cur << std::endl;
}

bool	singleArg(int &nb)
{
	return (nb == 15);
}

bool	nearArgs(int &first, int &second)
{
	return (fabs(first - second) < 3);
}

static void	constructor()
{
	std::cout << "\t===CONSTRUCTOR===" << std::endl;
	ft::list<int>	defaultConstructor;
	ft::list<int>	fillConstructor(5, 10);
	ft::list<int>	rangeConstructor(fillConstructor.begin(), fillConstructor.end());
	ft::list<int>	copyConstructor(fillConstructor);

	std::cout << "Default constructor:" << std::endl;	
	print(defaultConstructor);
	std::cout << "Fill constructor:" << std::endl;	
	print(fillConstructor);
	std::cout << "Range constructor:" << std::endl;	
	print(rangeConstructor);
	std::cout << "Copy constructor:" << std::endl;	
	print(copyConstructor);
}

static void	begin()
{
	std::cout << "\t===BEGIN===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	ft::list<int>::iterator			mineIt = listMine.begin();
	std::list<int>::iterator		realIt = listReal.begin();
//	ft::list<int>::const_iterator	mineConstIt = listMine.begin();
//	std::list<int>::const_iterator	realConstIt = listReal.begin();

	std::cout << "Begin Mine: " << *mineIt << std::endl;
	std::cout << "Begin Real: " << *realIt << std::endl;
//	std::cout << "Const Begin Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const Begin Real: " << *realConstIt << std::endl;

	mineIt++;
	realIt++;
//	mineConstIt++;
//	realConstIt++;

	std::cout << std::endl;
	std::cout << "Begin Mine: " << *mineIt << std::endl;
	std::cout << "Begin Real: " << *realIt << std::endl;
//	std::cout << "Const Begin Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const Begin Real: " << *realConstIt << std::endl;
}

static void	end()
{
	std::cout << "\t===END===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	ft::list<int>::iterator			mineIt = listMine.end();
	std::list<int>::iterator		realIt = listReal.end();
//	ft::list<int>::const_iterator	mineConstIt = listMine.end();
//	std::list<int>::const_iterator	realConstIt = listReal.end();

	// End points to the sentinel. The value is undefined. Mine is 0, Real is the size
	std::cout << "End Mine: " << *mineIt << std::endl;
	std::cout << "End Real: " << *realIt << std::endl;
//	std::cout << "Const End Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const End Real: " << *realConstIt << std::endl;
	
	mineIt++;
	realIt++;
//	mineConstIt++;
//	realConstIt++;

	std::cout << std::endl;
	std::cout << "End Mine: " << *mineIt << std::endl;
	std::cout << "End Real: " << *realIt << std::endl;
//	std::cout << "Const End Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const End Real: " << *realConstIt << std::endl;
}

static void rbegin()
{
	std::cout << "\t===RBEGIN===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	ft::list<int>::reverse_iterator			mineIt = listMine.rbegin();
	std::list<int>::reverse_iterator		realIt = listReal.rbegin();
//	ft::list<int>::const_reverese_iterator	mineConstIt = listMine.rbegin();
//	std::list<int>::const_reverse_iterator	realConstIt = listReal.rbegin();

	std::cout << "Rbegin Mine: " << *mineIt << std::endl;
	std::cout << "Rbegin Real: " << *realIt << std::endl;
//	std::cout << "Const Rbegin Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const Rbegin Real: " << *realConstIt << std::endl;
	
	mineIt++;
	realIt++;
//	mineConstIt++;
//	realConstIt++;

	std::cout << std::endl;
	std::cout << "Rbegin Mine: " << *mineIt << std::endl;
	std::cout << "Rbegin Real: " << *realIt << std::endl;
//	std::cout << "Const Rbegin Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const Rbegin Real: " << *realConstIt << std::endl;
}

static void	rend()
{
	std::cout << "\t===REND===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	ft::list<int>::reverse_iterator			mineIt = listMine.rend();
	std::list<int>::reverse_iterator		realIt = listReal.rend();
//	ft::list<int>::const_reverse_iterator	mineConstIt = listMine.rend();
//	std::list<int>::const_reverse_iterator	realConstIt = listReal.rend();

	// End points to the sentinel. The value is undefined. Mine is 0, Real is the size
	std::cout << "Rend Mine: " << *mineIt << std::endl;
	std::cout << "Rend Real: " << *realIt << std::endl;
//	std::cout << "Const Rend Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const Rend Real: " << *realConstIt << std::endl;
	
	mineIt++;
	realIt++;
//	mineConstIt++;
//	realConstIt++;

	std::cout << std::endl;
	std::cout << "Rend Mine: " << *mineIt << std::endl;
	std::cout << "Rend Real: " << *realIt << std::endl;
//	std::cout << "Const Rend Mine: " << *mineConstIt << std::endl;
//	std::cout << "Const Rend Real: " << *realConstIt << std::endl;
}

static void	empty()
{
	std::cout << "\t===EMPTY===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	
	std::cout << "Mine: " << listMine.empty() << std::endl;
	std::cout << "Real: " << listReal.empty() << std::endl;

	setup(listMine);
	setup(listReal);
	
	std::cout << "Mine: " << listMine.empty() << std::endl;
	std::cout << "Real: " << listReal.empty() << std::endl;
}

static void	size()
{
	std::cout << "\t===SIZE===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	std::cout << "Mine: " << listMine.size() << std::endl;
	std::cout << "Real: " << listReal.size() << std::endl;
}

static void max_size()
{
	std::cout << "\t===MAX SIZE===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	std::cout << "Mine: " << listMine.max_size() << std::endl;
	std::cout << "Real: " << listReal.max_size() << std::endl;
}

static void	front()
{
	std::cout << "\t===FRONT===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	std::cout << "Mine: " << listMine.front() << std::endl;
	std::cout << "Real: " << listReal.front() << std::endl;
}

static void back()
{
	std::cout << "\t===BACK===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	std::cout << "Mine: " << listMine.back() << std::endl;
	std::cout << "Real: " << listReal.back() << std::endl;
}

static void	assign()
{
	std::cout << "\t===ASSIGN===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	listMine.assign(++listMine.begin(), --listMine.end());
	listReal.assign(++listReal.begin(), --listReal.end());

	std::cout << "Range Mine:" << std::endl;
	print(listMine);
	std::cout << "Range Real:" << std::endl;
	print(listReal);
	
	listMine.assign(4, 1337);
	listReal.assign(4, 1337);

	std::cout << std::endl;
	std::cout << "Fill Mine:" << std::endl;
	print(listMine);
	std::cout << "Fill Real:" << std::endl;
	print(listReal);
}

static void	push_front()
{
	std::cout << "\t===PUSH FRONT===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	listMine.push_front(1337);
	listReal.push_front(1337);
	
	std::cout << "Mine:" << std::endl;
	print(listMine);
	std::cout << "Real:" << std::endl;
	print(listReal);
}

static void	pop_front()
{
	std::cout << "\t===POP FRONT===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);
	
	listMine.pop_front();
	listReal.pop_front();
	
	std::cout << "Mine:" << std::endl;
	print(listMine);
	std::cout << "Real:" << std::endl;
	print(listReal);
}

static void	push_back()
{
	std::cout << "\t===PUSH BACK===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	listMine.push_back(1337);
	listReal.push_back(1337);
	
	std::cout << "Mine:" << std::endl;
	print(listMine);
	std::cout << "Real:" << std::endl;
	print(listReal);
}

static void	pop_back()
{
	std::cout << "\t===POP BACK===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);
	
	listMine.pop_back();
	listReal.pop_back();
	
	std::cout << "Mine:" << std::endl;
	print(listMine);
	std::cout << "Real:" << std::endl;
	print(listReal);
}

static void	insert()
{
	std::cout << "\t===INSERT===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);
	
	std::cout << "Single Element Mine:" << std::endl;
	std::cout << "Inserted element: " << *listMine.insert(++listMine.begin(), 1337) << std::endl;
	print(listMine);
	std::cout << "Single Element Real:" << std::endl;
	std::cout << "Inserted element: " << *listReal.insert(++listReal.begin(), 1337) << std::endl;
	print(listReal);

	listMine.insert(++listMine.begin(), 3, 69);
	listReal.insert(++listReal.begin(), 3, 69);

	std::cout << std::endl;
	std::cout << "Fill Mine:" << std::endl;
	print(listMine);
	std::cout << "Fill Real:" << std::endl;
	print(listReal);
	
	listMine.insert(++listMine.begin(), ++listMine.begin(), --listMine.end());
	listReal.insert(++listReal.begin(), ++listReal.begin(), --listReal.end());
	
	std::cout << std::endl;
	std::cout << "Range Mine:" << std::endl;
	print(listMine);
	std::cout << "Range Real:" << std::endl;
	print(listReal);
}

static void	erase()
{
	std::cout << "\t===ERASE===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);
	
	std::cout << "Single Element Mine:" << std::endl;
	std::cout << "Next: " << *listMine.erase(++listMine.begin()) << std::endl;
	print(listMine);
	std::cout << "Single Element Real:" << std::endl;
	std::cout << "Next: " << *listReal.erase(++listReal.begin()) << std::endl;
	print(listReal);

	std::cout << std::endl;
	std::cout << "Range Mine:" << std::endl;
	std::cout << "Next: " << *listMine.erase(++listMine.begin(), --listMine.end()) << std::endl;
	print(listMine);
	std::cout << "Range Real:" << std::endl;
	std::cout << "Next: " << *listReal.erase(++listReal.begin(), --listReal.end()) << std::endl;
	print(listReal);
}

static void	swap()
{
	std::cout << "\t===SWAP===" << std::endl;
	ft::list<int> 	listMine;
	ft::list<int> 	listMineSwap;
	std::list<int>	listReal;
	std::list<int>	listRealSwap;
	setup(listMine);
	setup(listReal);

	for (size_t i = 0; i < 7; i++)
	{
		listMineSwap.push_back(i * 3);
		listRealSwap.push_back(i * 3);
	}

	std::cout << "Before Mine:" << std::endl;
	printAddress(listMine);
	std::cout << "Before Real:" << std::endl;
	printAddress(listReal);
	
	listMine.swap(listMineSwap);
	listReal.swap(listRealSwap);

	std::cout << std::endl;
	std::cout << "After Mine:" << std::endl;
	printAddress(listMine);
	std::cout << "After Real:" << std::endl;
	printAddress(listReal);
}

static void	resize()
{
	std::cout << "\t===RESIZE===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	std::cout << "Before Mine:" << std::endl;
	print(listMine);
	std::cout << "Before Real:" << std::endl;
	print(listReal);
	
	listMine.resize(2);
	listReal.resize(2);

	std::cout << std::endl;
	std::cout << "After Mine:" << std::endl;
	print(listMine);
	std::cout << "After Real:" << std::endl;
	print(listReal);
}

static void	clear()
{
	std::cout << "\t===CLEAR===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	std::cout << "Before Mine:" << std::endl;
	print(listMine);
	std::cout << "Before Real:" << std::endl;
	print(listReal);
	
	listMine.clear();
	listReal.clear();

	std::cout << std::endl;
	std::cout << "After Mine:" << std::endl;
	print(listMine);
	std::cout << "After Real:" << std::endl;
	print(listReal);
}

static void	splice()
{
	std::cout << "\t===SPLICE===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	ft::list<int> 	listSpliceMine(3, 13);
	std::list<int>	listSpliceReal(3, 13);
	setup(listMine);
	setup(listReal);

	std::cout << "Before Entire List Mine:" << std::endl;
	printAddress(listMine);
	std::cout << "Before Entire Splice List Mine:" << std::endl;
	printAddress(listSpliceMine);

	listMine.splice(++listMine.begin(), listSpliceMine);

	std::cout << "After Entire List Mine:" << std::endl;
	printAddress(listMine);

	std::cout << std::endl;
	std::cout << "Before Entire List Real:" << std::endl;
	printAddress(listReal);
	std::cout << "Before Entire Splice List Real:" << std::endl;
	printAddress(listSpliceReal);

	listReal.splice(++listReal.begin(), listSpliceReal);

	std::cout << "After Entire List Real:" << std::endl;
	printAddress(listReal);
}

static void	remove()
{
	std::cout << "\t===REMOVE===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	for (size_t i = 0; i < 3; i++)
	{
		listReal.push_back(15);
		listMine.push_back(15);
	}
	listMine.remove(15);
	listReal.remove(15);
	
	std::cout << "Remove Mine:" << std::endl;
	print(listMine);
	std::cout << "Remove Real:" << std::endl;
	print(listReal);
}


static void remove_if()
{
	std::cout << "\t===REMOVE IF===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;
	setup(listMine);
	setup(listReal);

	listMine.remove_if(singleArg);
	listReal.remove_if(singleArg);

	std::cout << "Remove If Mine:" << std::endl;
	print(listMine);
	std::cout << "Remove If Real:" << std::endl;
	print(listReal);
}

static void	unique()
{
	std::cout << "\t===UNIQUE===" << std::endl;
	ft::list<int> 	listMine1;
	ft::list<int> 	listMine2;
	std::list<int>	listReal1;
	std::list<int>	listReal2;
	setup(listMine1);
	setup(listMine2);
	setup(listReal1);
	setup(listReal2);

	for (size_t i = 0; i < 4; i++) // Unique should delete two of them
	{
		listReal1.push_back(69);
		listReal2.push_back(69 + i);
		listMine1.push_back(69);
		listMine2.push_back(69 + i);
	}
	for (size_t i = 0; i < 3; i++) // Unique shouldn't delete any of them
	{
		listMine1.push_back(15);
		listMine1.push_back(1337);
		listMine2.push_back(15);
		listMine2.push_back(1337);
		listReal1.push_back(15);
		listReal1.push_back(1337);
		listReal2.push_back(15);
		listReal2.push_back(1337);
	}
	
	listMine1.unique();
	listReal1.unique();

	std::cout << "Unique No Parameters Mine:" << std::endl;
	print(listMine1);
	std::cout << "Unique No Parameters Real:" << std::endl;
	print(listReal1);
	
	listMine2.unique(nearArgs);
	listReal2.unique(nearArgs);

	std::cout << std::endl;
	std::cout << "Unique Predicate Mine:" << std::endl;
	print(listMine2);
	std::cout << "Unique Predicate Real:" << std::endl;
	print(listReal2);
}

static void	merge()
{
	std::cout << "\t===MERGE===" << std::endl;
	ft::list<int> 	listMine1;
	ft::list<int> 	listMine2;
	std::list<int>	listReal1;
	std::list<int>	listReal2;
	setup(listMine1);
	setup(listReal1);

	for (int i = -3; i < 3; i++)
	{
		listMine2.push_back(i * 7);
		listReal2.push_back(i * 7);
	}

	std::cout << "Before Merge Mine List1" << std::endl;
	print(listMine1);
	std::cout << "Before Merge Mine List2" << std::endl;
	print(listMine2);
	std::cout << "Before Merge Real List1" << std::endl;
	print(listReal1);
	std::cout << "Before Merge Real List2" << std::endl;
	print(listReal2);

	listMine1.merge(listMine2);
	listReal1.merge(listReal2);

	std::cout << std::endl;
	std::cout << "After Merge Mine List1" << std::endl;
	print(listMine1);
	std::cout << "After Merge Mine List2" << std::endl;
	print(listMine2);
	std::cout << "After Merge Real List1" << std::endl;
	print(listReal1);
	std::cout << "After Merge Real List2" << std::endl;
	print(listReal2);

}

static void	sort()
{
	std::cout << "\t===SORT===" << std::endl;
}

static void	reverse()
{
	std::cout << "\t===REVERSE===" << std::endl;
}

static void	get_allocator()
{
	std::cout << "\t===GET ALLOCATOR===" << std::endl;
	ft::list<int> 	listMine;
	std::list<int>	listReal;

	if (listMine.get_allocator() == listReal.get_allocator())
		std::cout << "Mine and Real return the same type of allocator." << std::endl;
}

static void	relational_operators()
{
	std::cout << "\t===RELATIONAL OPERATORS===" << std::endl;
}

static void	all()
{
	constructor();
	begin();
	end();
	rbegin();
	rend();
	empty();
	size();
	max_size();
	front();
	back();
	assign();
	push_front();
	pop_front();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
	resize();
	clear();
	splice();
	remove();
	remove_if();
	unique();
	merge();
	sort();
	reverse();
	get_allocator();
	relational_operators();
}

void		testList(std::string choice)
{
	typedef void	(*test)();
	std::map<std::string, test>		functions;

	functions["constructor"] = constructor;
	functions["begin"] = begin;
	functions["end"] = end;
	functions["rbegin"] = rbegin;
	functions["rend"] = rend;
	functions["empty"] = empty;
	functions["size"] = size;
	functions["max_size"] = max_size;
	functions["front"] = front;
	functions["back"] = back;
	functions["assign"] = assign;
	functions["push_front"] = push_front;
	functions["pop_front"] = pop_front;
	functions["push_back"] = push_back;
	functions["pop_back"] = pop_back;
	functions["insert"] = insert;
	functions["erase"] = erase;
	functions["swap"] = swap;
	functions["resize"] = resize;
	functions["clear"] = clear;
	functions["splice"] = splice;
	functions["remove"] = remove;
	functions["remove_if"] = remove_if;
	functions["unique"] = unique;
	functions["merge"] = merge;
	functions["sort"] = sort;
	functions["reverse"] = reverse;
	functions["get_allocator"] = get_allocator;
	functions["relational_operators"] = relational_operators;
	functions["all"] = all;

	if (functions.find(choice) != functions.end())
		functions[choice]();
	else
	{
		std::cout << "The chosen function does not exist. Type \"list help\"" <<
			" for a list of valid options." << std::endl;
	}
}

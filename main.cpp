/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/22 13:58:38 by rpet          #+#    #+#                 */
/*   Updated: 2021/08/03 09:23:23 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cstddef>
	#include <vector>
#include <exception>
#ifdef USE_STD
	#include <map>
	#include <stack>
	#include <vector>
	#define OFILE_NAME "std_times.txt"
	#define LEAKS_CONTAINER "leaks std_containers"
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#define OFILE_NAME "ft_times.txt"
	#define LEAKS_CONTAINER "leaks ft_containers"
#endif

// Class where all the calculating times are noted in a txt file
class TimeLog
{
	public:
		TimeLog() : _currentTime(clock()), _newTime(0), _totalTime(0)
		{
			std::string		name;

			this->_outputFile.open(OFILE_NAME);
			{
				name = "====== FT TIMES: ======";
				if (OFILE_NAME == "std_times.txt")
					name = "====== STD TIMES: ======";
				this->_outputFile << name << std::endl;
			}
		}
		void	calculateTime(std::string testName)
		{
			this->_newTime = clock();
			this->_outputFile << testName << this->_newTime - this->_currentTime << std::endl;
			this->_totalTime += this->_newTime - this->_currentTime;
			this->_currentTime = this->_newTime;
			std::cout << std::endl << "==============================================" << std::endl;
		}
		void	totalTime()
		{
			this->_outputFile << "Total time elapsed: " << this->_totalTime << std::endl << std::endl;
		}

	private:
		clock_t			_currentTime;
		clock_t			_newTime;
		clock_t			_totalTime;
		std::ofstream	_outputFile;
};

// Check for leaks
void	checkLeaks()
{
	system(LEAKS_CONTAINER);
}

// Print all the content in a stack
template <typename T>
void	printStack(ft::stack<T> &stack)
{
	for (ft::stack<T> dump = stack; !stack.empty(); stack.pop())
		std::cout << stack.top() << std::endl;
}


// Print all the content in a vector
template <typename T>
void	printVector(ft::vector<T> &vector)
{
	typename ft::vector<T>::iterator	cur = vector.begin();

	std::cout << "Current vector has a size of: " << vector.size() <<
		" and a capacity of: " << vector.capacity() << std::endl;
	for (size_t i = 0; cur != vector.end(); i++, cur++)
		std::cout << "Index [" << i << "]: " << *cur << std::endl;
}

// Print the size and capacity of a vector
template <typename T>
void	printVectorCapacity(ft::vector<T> &vector)
{
	std::cout << "Current vector has a size of: " << vector.size() <<
		" and a capacity of: " << vector.capacity() << std::endl;
}

void	vectorTest_constructors()
{
	std::cout << "\t======== Constructors ========" << std::endl << std::endl;
	std::cout << "Default constructor called." << std::endl;
	ft::vector<int>		defaultConstructor;
	std::cout << "Fill constructor called." << std::endl;
	ft::vector<int>		fillConstructor(5, rand());
	std::cout << "Range constructor called." << std::endl;
	ft::vector<int>		rangeConstructor(fillConstructor.begin(), fillConstructor.end());
	std::cout << "Copy constructor called." << std::endl;
	ft::vector<int>		copyConstructor(fillConstructor);

	std::cout << "Default constructor:" << std::endl;
	printVector(defaultConstructor);
	std::cout << "Fill constructor:" << std::endl;
	printVector(fillConstructor);
	std::cout << "Range constructor:" << std::endl;
	printVector(rangeConstructor);
	std::cout << "Copy constructor:" << std::endl;
	printVector(copyConstructor);
}

void	vectorTest_iteratorFunctions()
{
	std::cout << "\t======== Iterator functions ========" << std::endl << std::endl;
	ft::vector<int>							vec;
	ft::vector<int>::iterator				it;
	ft::vector<int>::const_iterator			cit;
	ft::vector<int>::reverse_iterator		rit;
	ft::vector<int>::const_reverse_iterator	crit;

	for (size_t i = 0; i < 15; i++)
		vec.push_back(rand());

	it = vec.begin();
	cit = vec.begin();
	rit = vec.rbegin();
	crit = vec.rbegin();
	std::cout << "Begin: " << *it << std::endl;
	std::cout << "Const begin: " << *cit << std::endl;
	std::cout << "Reverse begin: " << *rit << std::endl;
	std::cout << "Const reverse begin: " << *crit << std::endl;
	
	it = vec.end() - 1;
	cit = vec.end() - 1;
	rit = vec.rend() - 1;
	crit = vec.rend() - 1;
	std::cout << "End: " << *it << std::endl;
	std::cout << "Const end: " << *cit << std::endl;
	std::cout << "Reverse end: " << *rit << std::endl;
	std::cout << "Const reverse end: " << *crit << std::endl;
	printVector(vec);
}

void	vectorTest_iteratorOperators()
{
	std::cout << "\t===== Iterator operators =====" << std::endl;
	ft::vector<std::string>							vec;
	ft::vector<std::string>::iterator				it;
	ft::vector<std::string>::const_iterator			cit;
	ft::vector<std::string>::reverse_iterator		rit;
	ft::vector<std::string>::const_reverse_iterator	crit;

	vec.push_back("Remco");
	vec.push_back("Mark");
	vec.push_back("Jonas");
	vec.push_back("Lars");
	vec.push_back("Ksenia");
	vec.push_back("Laura");

	it = vec.begin();
	cit = vec.begin();
	rit = vec.rend() - 1;
	crit = vec.rend() - 1;
	// *it
	std::cout << "*it: " << *it << " | *cit: " << *cit << " | *rit: " << *rit << " | *crit: " << *crit << std::endl;
	// it->
	std::cout << "->it: " << it->append("->op1") << " | ->cit: " << cit->data() << " | ->rit: " << rit->append("->op2") << " | ->crit: " << crit->data() << std::endl;
	// ++it & --rit
	std::cout << "++it: " << *++it << " | ++cit: " << *++cit << " | --rit: " << *--rit << " | --crit: " << *--crit << std::endl;
	// it++ & rit--
	std::cout << "it++: " << *it++ << " | cit++: " << *cit++ << " | rit--: " << *rit-- << " | crit--: " << *crit-- << std::endl;
	// --it & ++rit
	std::cout << "--it: " << *--it << " | --cit: " << *--cit << " | ++rit: " << *++rit << " | ++crit: " << *++crit << std::endl;
	// it-- & rit++
	std::cout << "it--: " << *it-- << " | cit--: " << *cit-- << " | rit++: " << *rit++ << " | crit++: " << *crit++ << std::endl;
	std::cout << *it << *rit << std::endl;
	// it + n & rit - n
	it = it + 3;
	rit = rit - 3;
	std::cout << "it + n: " << *it << " | rit - n: " << *rit << std::endl;
	// n + it & n + rit
	it = 1 + it;
	rit = 1 + rit;
	std::cout << "n + it: " << *it << " | n + rit: " << *rit << std::endl;
	// it - n & rit + n
	it = it - 2;
	rit = rit + 2;
	std::cout << "it - n: " << *it << " | rit + n: " << *rit << std::endl;
	// it - cit & rit - crit
	std::cout << "it - cit: " << it - cit << " | rit - crit: " << rit - crit << std::endl;
	// it < cit
	std::cout << "it < cit: " << (it < cit) << std::endl;
	// it > cit
	std::cout << "it > cit: " << (it > cit) << std::endl;
	// it <= cit
	std::cout << "it <= cit: " << (it <= cit) << std::endl;
	// it >= cit
	std::cout << "it >= cit: " << (it >= cit) << std::endl;
	// it += n
	it += 1;
	rit -= 1;
	std::cout << "it += n: " << *it << " | rit -= n: " << *rit << std::endl;
	// it -= n
	it -= 1;
	rit += 1;
	std::cout << "it -= n: " << *it << " | rit += n: " << *rit << std::endl;
	// it[n]
	std::cout << "it[n]: " << it[2] << " | cit[n]: " << cit[2] << " | rit[n]: " << rit[-2] << " | crit[n]: " << crit[-2] << std::endl;
	printVector(vec);
}

void	vectorTest_capacityFunctions()
{
	std::cout << "\t===== Capacity functions =====" << std::endl << std::endl;
	ft::vector<int>	vec;

	for (size_t i = 0; i < 15; i++)
		vec.push_back(rand());

	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Resize:" << std::endl;
	vec.resize(1);
	printVectorCapacity(vec);
	vec.resize(33);
	printVectorCapacity(vec);
	vec.resize(38);
	printVectorCapacity(vec);
	vec.resize(4);
	printVectorCapacity(vec);
	vec.resize(89);
	printVectorCapacity(vec);
	std::cout << "Reserve:" << std::endl;
	vec.reserve(7);
	printVectorCapacity(vec);
	vec.reserve(139);
	printVectorCapacity(vec);
	vec.reserve(147);
	printVectorCapacity(vec);
	std::cout << "Empty before clear: " << vec.empty() << std::endl;
	vec.clear();
	std::cout << "Empty after clear: " << vec.empty() << std::endl;
	printVector(vec);
}

void	vectorTest_elementFunctions()
{
	std::cout << "\t===== Element access functions =====" << std::endl << std::endl;
	ft::vector<int>	vec;

	for (size_t i = 0; i < 15; i++)
		vec.push_back(rand());
	std::cout << "Operator[] (subscript):" << std::endl;
	std::cout << "Vector[5]: " << vec[5] << " & Vector[1337]: " << vec[1337] << std::endl;
	try
	{
		std::cout << "At(5): " << vec.at(5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception error" << std::endl;
	}
	try
	{
		std::cout << "At(1337): " << vec.at(1337) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception error" << std::endl;
	}
	std::cout << "Front: " << vec.front() << std::endl;
	std::cout << "Back: " << vec.back() << std::endl;
	printVector(vec);
}

void	vectorTest_modifierFunctions()
{
	std::cout << "\t===== Modifier functions =====" << std::endl << std::endl;
	ft::vector<int>				vec1;
	ft::vector<int>				vec2;
	ft::vector<int>::iterator	it;

	for (size_t i = 0; i < 15; i++)
		vec1.push_back(rand());
	for (size_t i = 0; i < 35; i++)
		vec2.push_back(rand());
	it = vec1.begin() + 4;
	std::cout << "Assign:" << std::endl;
	vec1.assign(it, it + 5);
	printVector(vec1);
	it = vec2.begin();
	vec1.assign(it, it + 33);
	printVector(vec1);
	vec1.assign(it, it);
	printVector(vec1);
	vec1.assign(30, 25);
	printVector(vec1);
	std::cout << "Insert:" << std::endl;
	it = vec1.begin() + 6;
	it = vec1.insert(it, 1337);
	std::cout << "Return value insert single element: " << *it << std::endl;
	vec1.insert(it + 20, 5, 420);
	it = vec2.begin() + 17;
	vec1.insert(vec1.begin() + 10, it, it + 4);
	std::cout << "Erase:" << std::endl;
	printVector(vec1);
	it = vec1.erase(vec1.begin() + 11);
	std::cout << "Return value erase single element: " << *it << std::endl;
	it = vec1.erase(vec1.begin() + 11, vec1.begin() + 31);
	std::cout << "Return value erase range: " << *it << std::endl;
	printVector(vec1);
	printVector(vec2);
	std::cout << "Swap:" << std::endl;
	it = vec1.begin() + 5;
	std::cout << "Iterator value before swap: " << *it << std::endl;
	vec1.swap(vec2);
	std::cout << "Iterator value after swap: " << *it << std::endl;
	printVector(vec1);
	printVector(vec2);
	std::cout << "Clear:" << std::endl;
	vec1.clear();
}

void	vectorTest_nonMemberFunctions()
{
	std::cout << "\t===== Non-member functions =====" << std::endl << std::endl;
	ft::vector<int>				vec1;
	ft::vector<int>				vec2;
	std::string					result;
		
	for (size_t i = 0; i < 8; i++)
		vec1.push_back(rand());

	std::cout << "\tRandom numbers vector (vec1) and an empty vector (vec2)" << std::endl;
	std::cout << "vec1 == vec2: " << std::boolalpha << (vec1 == vec2) << std::endl;
	std::cout << "vec1 != vec2: " << std::boolalpha << (vec1 != vec2) << std::endl;
	std::cout << "vec1 <= vec2: " << std::boolalpha << (vec1 <= vec2) << std::endl;
	std::cout << "vec1 >= vec2: " << std::boolalpha << (vec1 >= vec2) << std::endl;
	std::cout << std::endl << "\tExecuting vec2 = vec1" << std::endl;
	vec2 = vec1;
	std::cout << "vec1 == vec2: " << std::boolalpha << (vec1 == vec2) << std::endl;
	std::cout << "vec1 != vec2: " << std::boolalpha << (vec1 != vec2) << std::endl;
	std::cout << "vec1 <= vec2: " << std::boolalpha << (vec1 <= vec2) << std::endl;
	std::cout << "vec1 >= vec2: " << std::boolalpha << (vec1 >= vec2) << std::endl;
	std::cout << std::endl << "\tExecuting a push_back for vec1" << std::endl;
	vec1.push_back(1337);
	std::cout << "vec1 < vec2: " << std::boolalpha << (vec1 < vec2) << std::endl;
	std::cout << "vec1 > vec2: " << std::boolalpha << (vec1 > vec2) << std::endl;
	std::cout << std::endl << "\tChanging the first index without changing the size" << std::endl;
	vec1[0] = 1;
	vec2[0] = 2;
	std::cout << "vec1 < vec2: " << std::boolalpha << (vec1 < vec2) << std::endl;
	std::cout << "vec1 > vec2: " << std::boolalpha << (vec1 > vec2) << std::endl;
	std::cout << std::endl << "Swap:" << std::endl;
	printVector(vec1);
	printVector(vec2);
	ft::swap(vec1, vec2);
	printVector(vec1);
	printVector(vec2);
}

void	stackTests()
{
	std::cout << "\t======== Stack tests ========" << std::endl << std::endl;
	std::deque<int>		deque(5, 69);
	std::list<int>		list(6, 42);
	ft::vector<int>		vector(7, 1337);
	std::cout << "Default constructor called." << std::endl;
	ft::stack<int>		stack1;
	std::cout << "Copy constructor called." << std::endl;
	ft::stack<int>		stack2 = stack1;
	std::cout << "Assign operator called." << std::endl;
	ft::stack<int>		stack3 = stack1;

	std::cout << "Copy constructor deque called." << std::endl;
	ft::stack<int>						copyConstructorDeque(deque);
	std::cout << "Copy constructor list called." << std::endl;
	ft::stack<int, std::list<int> >		copyConstructorList(list);
	std::cout << "Copy constructor vector called." << std::endl;
	ft::stack<int, ft::vector<int> >	copyConstructorVector(vector);

	std::cout << "Empty: " << std::boolalpha << stack1.empty() << std::endl;
	std::cout << "Empty: " << std::boolalpha << copyConstructorDeque.empty() << std::endl;
	std::cout << "Size: " << copyConstructorList.size() << std::endl;
	std::cout << "Top: " << copyConstructorDeque.top() << std::endl;
	std::cout << "Calling push..." << std::endl;
	copyConstructorDeque.push(99999);
	std::cout << "Top: " << copyConstructorDeque.top() << std::endl;
	std::cout << "Calling pop..." << std::endl;
	copyConstructorDeque.pop();
	std::cout << "Top: " << copyConstructorDeque.top() << std::endl;
	
	std::cout << "stack1 == stack2: " << std::boolalpha << (stack1 == stack2) << std::endl;
	std::cout << "stack1 != stack2: " << std::boolalpha << (stack1 != stack2) << std::endl;
	std::cout << "stack1 < stack2: " << std::boolalpha << (stack1 < stack2) << std::endl;
	std::cout << "stack1 <= stack2: " << std::boolalpha << (stack1 <= stack2) << std::endl;
	std::cout << "stack1 > stack2: " << std::boolalpha << (stack1 > stack2) << std::endl;
	std::cout << "stack1 >= stack2: " << std::boolalpha << (stack1 >= stack2) << std::endl;
}

int		main()
{
	// Turn on or off to check for leaks
//	atexit(checkLeaks);

	TimeLog	time;

	// Vector tests
	vectorTest_constructors();
	time.calculateTime("Vector constructors: ");
	vectorTest_iteratorFunctions();
	time.calculateTime("Vector iterator functions: ");
	vectorTest_iteratorOperators();
	time.calculateTime("Vector iterator operators: ");
	vectorTest_capacityFunctions();
	time.calculateTime("Vector capcity functions: ");
	vectorTest_elementFunctions();
	time.calculateTime("Vector element access functions: ");
	vectorTest_modifierFunctions();
	time.calculateTime("Vector modifier functions: ");
	vectorTest_nonMemberFunctions();
	time.calculateTime("Vector non-member functions: ");

	// Stack tests
	stackTests();
	time.calculateTime("Stack tests: ");

	// Total time
	time.totalTime();
	return (0);
}

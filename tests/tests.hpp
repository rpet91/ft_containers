/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 08:43:37 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/18 11:45:38 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP
# include <string>

void	printHelp();
void	printHelpContainer(std::string container);
void	testContainer(std::string container, std::string function);

void	testList(std::string function);
//void	testVector(std::string function);
//void	testMap(std::string function);
//void	testStack(std::string function);
//void	testQueue(std::string function);

#endif

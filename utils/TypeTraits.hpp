/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TypeTraits.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 13:06:40 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/08 14:11:02 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETRAITS_HPP
# define TYPETRAITS_HPP
# include <iostream>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template < bool B, typename T = void >
	struct enable_if
	{
	};

	template < typename T >
	struct enable_if< true, T >
	{
		typedef T	type;
	};
}

#endif

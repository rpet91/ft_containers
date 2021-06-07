/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Category.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 13:06:40 by rpet          #+#    #+#                 */
/*   Updated: 2021/06/07 13:18:01 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATEGORY_HPP
# define CATEGORY_HPP

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:51:36 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 18:44:33 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}

searchable_array_bag::~searchable_array_bag(){}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : array_bag(other)
{}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other)
	{
		array_bag::operator=(other);
	}
	return (*this);
}

bool searchable_array_bag::has(int x) const
{
	for (int i = 0; i < this->size; ++i)
	{
		if (this->data[i] == x)
			return (true);
	}
	return (false);
}


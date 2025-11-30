/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:48:20 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/29 14:53:05 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}

searchable_array_bag::~searchable_array_bag()
{
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other): array_bag(other)
{
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other)
{
	if (this != &other)
	{
		array_bag::operator=(other);
	}
	return (*this);
}

bool searchable_array_bag::has(int n) const
{
	for (int i = 0; i < this->size; ++i)
	{
		if (this->data[i] == n)
		{
			return (true);
		}
	}
	return (false);
}

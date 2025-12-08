/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 07:35:30 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 09:06:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag()
{}

searchable_array_bag::~searchable_array_bag()
{}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : array_bag(other)
{}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other)
	{
		//array_bag::operator=(other);
		array_bag::operator=(other);
	}
	return (*this);
}

bool searchable_array_bag::has(int x) const
{
	for (int i = 0; i < size; ++i)
	{
		if (data[i] == x)
			return (true);
	}
	return (false);
}

void searchable_array_bag::insert(int x)
{
	array_bag::insert(x);
}


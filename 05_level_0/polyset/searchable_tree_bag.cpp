/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:24:05 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/29 17:59:14 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"
#include <iostream>

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other)
{}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return(*this);
}

bool searchable_tree_bag::has(int n) const
{
	node *current = this->tree;
	while (current)
	{
		if (current->value == n)
		{
			return (true);
		}
		if (current->value < n)
		{
			current = current->r;
		}
		else
		{
			current = current->l;
		}
	}
	return (false);
}



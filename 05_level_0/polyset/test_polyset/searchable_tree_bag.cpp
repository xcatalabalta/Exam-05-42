/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:55:30 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 19:29:39 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return (*this);
}

bool searchable_tree_bag::has(int x) const
{
	node *curr = this->tree;

	while (curr)
	{
		if (curr->value == x)
			return(true);
		if (curr->value > x)
			curr = curr->l;
		else
			curr = curr->r;
	}
	return (false);
}

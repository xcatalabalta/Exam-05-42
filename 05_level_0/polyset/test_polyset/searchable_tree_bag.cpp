/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:21:45 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 09:01:31 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other)
{}

searchable_tree_bag& searchable_tree_bag::operator=(searchable_tree_bag &other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return (*this);
}
/*
void searchable_tree_bag::insert(int x)
{
	tree_bag::insert(x);
}
*/
bool searchable_tree_bag::has(int x) const
{
	node *curr = this->tree;

	while (curr)
	{
		if (x == curr->value)
			return (true);
		if (x < curr->value)
			curr = curr->l;
		else
			curr = curr->r;
	}


	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:21:16 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 09:03:05 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	public:
		searchable_tree_bag();
		virtual ~searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &other);
		searchable_tree_bag& operator=(searchable_tree_bag &other);
		//void insert(int x);
		bool has(int x) const;
};

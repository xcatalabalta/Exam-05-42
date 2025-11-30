/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:20:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/30 08:44:28 by fcatala-         ###   ########.fr       */
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
		searchable_tree_bag(const searchable_tree_bag& other);
		searchable_tree_bag& operator=(const searchable_tree_bag& other);
		bool has(int n) const;
};

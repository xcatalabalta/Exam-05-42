/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:50:50 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 18:59:15 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		virtual ~searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &other);
		searchable_array_bag& operator=(const searchable_array_bag &other);
		bool has(int x) const;
};

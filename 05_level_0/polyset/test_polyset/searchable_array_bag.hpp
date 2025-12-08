/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 07:35:00 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 09:05:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		virtual ~searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &other);
		searchable_array_bag& operator=(const searchable_array_bag &other);
		bool has(int x) const;
		void insert(int x);
};

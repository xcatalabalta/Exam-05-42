/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:17:53 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/30 06:58:05 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag&	m_bag;
	public:
		set() = delete;
		~set();
		set(const set &other) = delete;
		set& operator=(const set &other) = delete;
		set(searchable_bag &other);
		const searchable_bag& get_bag();
		void insert(int n);
		void insert(int *c, int count);
		bool has(int n) const;
		void print() const;
		void clear();
};



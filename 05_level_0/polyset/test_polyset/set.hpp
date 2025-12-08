/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:39:05 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 09:55:04 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& m_bag;
	public:
		set() = delete;
		set(const set &other) = delete;
		set& operator=(const set &other) = delete;
		set(searchable_bag &other);
		void insert(int x);
		void insert(int *x, int c);
		bool has(int x) const;
		void print() const;
		const searchable_bag& get_bag() const;
		void clear();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 06:24:23 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 07:00:59 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"
#include "bag.hpp"

class set
{
	private:
		searchable_bag& m_bag;
	public:
		set() = delete;
		~set();
		set(const set &other) = delete;
		set& operator=(const set &other) = delete;
		set(searchable_bag &other);
		void insert(int);
		void insert(int *, int);
		bool has(int x);
		const searchable_bag& get_bag() const; 
		void print() const;
		void clear();

};

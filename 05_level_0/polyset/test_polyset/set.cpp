/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 06:29:12 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 07:00:55 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::~set() {}

set::set(searchable_bag &other) : m_bag(other) {}

void set::insert(int x)
{
	m_bag.insert(x);
}

void set::insert(int *a, int c)
{
	m_bag.insert(a, c);
}

bool set::has(int x)
{
	return(m_bag.has(x));
}

const searchable_bag& set::get_bag() const
{
	return m_bag;
}


void set::print() const
{
	m_bag.print();
}

void set::clear()
{
	m_bag.clear();
}

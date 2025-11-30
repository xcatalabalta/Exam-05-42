/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 05:18:32 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/30 06:59:14 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::~set(){}

set::set(searchable_bag &other) : m_bag(other) {}

const searchable_bag& set::get_bag()
{
	return (m_bag);
}

void set::insert(int n)
{
	m_bag.insert(n);
}

void set::insert(int *c, int count)
{
	m_bag.insert(c, count);
}


bool set::has(int n) const
{
	return(m_bag.has(n));
}

void set::print() const
{
	m_bag.print();
}

void set::clear()
{
	m_bag.clear();
}

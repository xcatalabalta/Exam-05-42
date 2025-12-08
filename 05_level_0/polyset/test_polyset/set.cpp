/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:39:33 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/03 09:56:10 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag &other) : m_bag(other)
{}

void set::insert(int x)
{
	m_bag.insert(x);
}

void set::insert(int *x, int c)
{
	m_bag.insert(x, c);
}

bool set::has(int x) const
{
	return(m_bag.has(x));
}

void set::print() const
{
	m_bag.print();
}

const searchable_bag& set::get_bag() const
{
	return (m_bag);
}

void set::clear()
{
	m_bag.clear();
}

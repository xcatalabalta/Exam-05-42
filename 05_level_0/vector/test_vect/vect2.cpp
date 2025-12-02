/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:43:03 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 15:37:17 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : m_x(0), m_y(0) {}

vect2::~vect2() {}

vect2::vect2(int x, int y) : m_x(x), m_y(y) {}

vect2::vect2(const vect2 &other) : m_x(other.m_x), m_y(other.m_y) {}

vect2& vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
	}
	return (*this);
}

int& vect2::operator[](int indx)
{
	if (indx == 0)
		return (m_x);
	return (m_y);
}


int vect2::operator[](int indx) const
{
	if (indx == 0)
		return (m_x);
	return (m_y);
}

vect2&	vect2::operator++()
{
	++m_x;
	++m_y;
	return (*this);
}

vect2 	vect2::operator++(int)
{
	vect2 out(*this);
	m_x++;
	m_y++;
	return (out);
}


vect2&	vect2::operator--()
{
	--m_x;
	--m_y;
	return (*this);
}

vect2 	vect2::operator--(int)
{
	vect2 out(*this);
	m_x--;
	m_y--;
	return (out);
}

vect2 	vect2::operator+(const vect2 &other) const
{
	vect2 out(*this);
	out.m_x += other.m_x;
	out.m_y += other.m_y;
	return (out);
}

vect2& 	vect2::operator+=(const vect2 &other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	return (*this);
}

vect2 	vect2::operator-(const vect2 &other) const
{
	vect2 out(*this);
	out.m_x -= other.m_x;
	out.m_y -= other.m_y;
	return (out);
}

vect2& 	vect2::operator-=(const vect2 &other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	return (*this);
}

vect2 	vect2::operator*(const int &scalar) const
{
	vect2 out(*this);
	out.m_x *= scalar;
	out.m_y *= scalar;
	return (out);
}

vect2& 	vect2::operator*=(const int &scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	return (*this);
}

vect2&	vect2::operator-()
{
	m_x = -m_x;
	m_y = -m_y;
	return (*this);
}

bool 	vect2::operator==(const vect2 &other) const
{
	return((m_x == other.m_x) && (m_y == other.m_y));
}

bool 	vect2::operator!=(const vect2 &other) const
{
	return(!((m_x == other.m_x) && (m_y == other.m_y)));
}

std::ostream& operator<<(std::ostream &oss, const vect2 &vect)
{
	oss << "{" << vect[0] << ", " << vect[1] << "}";
	return (oss);
}

vect2 operator*(const int &scalar, const vect2 &other)
{
	vect2 temp = other * scalar;
	return (temp);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:11:58 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/25 18:11:52 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2()
{
	x = 0;
	y = 0;
}

vect2::vect2(int a, int b)
{
	x = a;
	y = b;
}

vect2::vect2(const vect2 &other)
{
	x = other.x;
	y = other.y;
}

vect2& vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

int vect2::getX() const
{
	return (x);
}

int vect2::getY() const
{
	return (y);
}

int& vect2::operator[](int index)
{
	if (index == 0)
	{
		return x;
	}
	else
		return y;
}


int vect2::operator[](int index) const
{
	if (index == 0)
	{
		return x;
	}
	else
		return y;
}


vect2& vect2::operator++()
{
	++x;
	++y;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	this->x += 1;
	this->y += 1;
	return temp;
}


vect2& vect2::operator--()
{
	--x;
	--y;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	this->x -= 1;
	this->y -= 1;
	return temp;
}

vect2& vect2::operator+=(const vect2 &other)
{
	this->x += other.x;
	this->y += other.y;
	return (*this);
}

vect2& vect2::operator-=(const vect2 &other)
{
	this->x -= other.x;
	this->y -= other.y;
	return (*this);
}

vect2 vect2::operator*(const vect2 &other) const
{
	vect2 temp = *this;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	return (temp);

}

vect2 vect2::operator*(int num) const
{
	vect2 temp = *this;

	temp.x = this->x * num;
	temp.y = this->y * num;
	return (temp);
}

vect2& vect2::operator*=(int num)
{
	*this = *this * num;
	return (*this);
}


vect2 vect2::operator+(const vect2 &rh) const
{
	vect2 temp = *this;

	temp.x += rh.x;
	temp.y += rh.y;
	return (temp);

}

vect2 vect2::operator-(const vect2 &rh) const
{
	vect2 temp = *this;

	temp.x -= rh.x;
	temp.y -= rh.y;
	return (temp);

}

vect2& vect2::operator-()
{

	x = -x;
	y = -y;
	return (*this);

}

bool vect2::operator==(const vect2 &other) const
{
	return ((x == other.x) && (y == other.y));
}

bool vect2::operator!=(const vect2 &other) const
{
	return ((x != other.x) && (y != other.y));
}

vect2 operator*(int num, const vect2 &rh)
{
	vect2 temp = rh * num;
	return temp;
}

std::ostream& operator<<(std::ostream& oss, const vect2& vect)
{
	std::cout << "{" << vect.getX() << ", " << vect.getY() << "}";
	return (oss);	
}

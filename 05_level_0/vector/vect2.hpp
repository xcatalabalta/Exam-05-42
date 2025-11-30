/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:06:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/25 18:10:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int a, int b);
		vect2(const vect2 &other);
		vect2& operator=(const vect2 &other);
		int getX() const;
		int getY() const;
		int& operator[](int index);
		int operator[](int index) const;
		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);
		vect2& operator+=(const vect2 &other);
		vect2& operator-=(const vect2 &other);
		vect2 operator*(const vect2 &other) const;
		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 operator*(int num) const;
		vect2& operator*=(int num);
		vect2& operator-();
		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;
};
vect2 operator*(int num, const vect2 &rh);
std::ostream& operator<<(std::ostream& os, const vect2& vect);
#endif

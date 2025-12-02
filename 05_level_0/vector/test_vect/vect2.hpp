/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:42:39 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 15:30:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class vect2
{
	private:
		int m_x;
		int m_y;
	public:
		vect2();
		~vect2();
		vect2(int x, int y);
		vect2(const vect2 &other);
		vect2& 	operator=(const vect2 &other);
		int& 	operator[](int indx);
		int 	operator[](int indx) const;
		vect2&	operator++();
		vect2	operator++(int);
		vect2&	operator--();
		vect2	operator--(int);
		vect2	operator+(const vect2 &other) const;
		vect2&	operator+=(const vect2 &other);
		vect2	operator-(const vect2 &other) const;
		vect2&	operator-=(const vect2 &other);
		vect2	operator*(const int &scalar) const;
		vect2&	operator*=(const int &scalar);
//		vect2	operator*(const vect2 &other) const;
		vect2&	operator-();
		bool 	operator==(const vect2 &other) const;
		bool 	operator!=(const vect2 &other) const;
};

std::ostream& operator<<(std::ostream &oss, const vect2 &vect);
vect2 operator*(const int &scalar, const vect2 &other);


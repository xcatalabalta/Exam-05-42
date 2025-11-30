/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:11 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/25 18:20:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignement name: vect2
Expected files: vect2.cpp, vect2.hpp
-------------------------------------------------------------------------------------------

Create a class vect2 representing a mathematical vector of dimension 2 containing ints.

It must support addition, substraction and multiplication by a scalar (such as the expression (vect2(2,2) * 2 == vect2(4,4)) is true).

the operator [] can be used to access the component of your vector (with 0 and 1), no bound checking is required.

Your function must be printable with the << operator such as:
        std::cout << v << std::endl;
produce the same output as:
        std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;

You will find a main in this directory that must work with your class.
*/
#include "vect2.hpp"
#include <iostream>

int main()
{
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
	const vect2 v3(v2); // 1, 2
	vect2 v4 = v2; // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;

	vect2 test = v4++;
	std::cout << "test = v4++" << test << std::endl;
    //std::cout << v4++ << std::endl; // 2, 3
	std::cout << v4 << std::endl;
	std::cout << ++v4 << std::endl; // 3, 4
	std::cout << "Change v4 to -9,-14\n";
	v4[0] = -9;
	v4[1] = -14;
	std::cout << v4 << std::endl;
    std::cout << "v4 is "<< v4 << " and v4-- is "<< v4-- << " but v4 is now " << v4  << std::endl; // 2, 3
    std::cout << "v4 is "<< v4 << " and --v4 is "<< --v4 << " and v4 is now " << v4  << std::endl; // 2, 3
    //std::cout << --v4 << std::endl; // 1, 2
	std::cout << "v2 is " << v2 << " and v3 is " << v3 << std::endl;
	v2 += v3;
    std::cout << "v2 += v3 makes v2 = " << v2 << " and v3 is " << v3 << std::endl; // 2, 4
    v4++;
	++v4;
	std::cout << "v2 was " << v2;
	v2 += v4;
	std::cout << " v2 += v4 makes v2 = " << v2 << " and v4 is " << v4 << std::endl; // 2, 4
	std::cout << "v1 was " << v1;
    v1 -= v2; // -2, -4
	std::cout << " v1 -= v2 makes v1 = " << v1 << " and v2 is " << v2 << std::endl; // 2, 4
	std::cout << "Given v1 = " << v1 << " and v4 = " << v4 << " v1 * v4 = " << v1 * v4 << std::endl;
	vect2 v7 = v1 * v4;
	std::cout << "Meet v7 (v1 * v4) = " << v7 << std::endl;
	std::cout << "\tMeet  v7 * 2  = " << v7 * 2 << std::endl;
	std::cout << "\tMeet  20 * v7  = " << 20 * v7 << std::endl;
	std::cout << "\tv7 + v7 + v7 = " << v7 + v7 + v7 << std::endl;
	std::cout << "\tv1 = " << v1 << "\n\tv4 = " << v4 << "\n\tv7 = " << v7 <<std::endl;
	std::cout << "\tv1 + v4 - v7 = " << v1 + v4 - v7 << std::endl;
	std::cout << "v2 = " << v2 << " v3 = " << v3 << std::endl;
	std::cout << "v2 = v3 + v3 *2\n"; // 3, 6
    v2 = v3 + v3 *2;
	std::cout << "v2 = " << v2 << std::endl;
    v2 = 3 * v2; // 9, 18
    std::cout << "v2 = 3 * v2 => v2 = "<< v2 << std::endl;; // 9, 18
    v2 += v2 += v3; // 20, 40
    std::cout << "v2 += v2 += v3 => v2 = " << v2 << std::endl; // 20, 40
    std::cout << "If v1 = " << v1 << " then v1 *= 42 \n";
	v1 *= 42; // -84, -168
    v1 = v1 - v1 +v1;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[0]: " << v3[0] << " and  ";//<< v3 << std::endl;
    std::cout << "v3[1]: " << v3[1] << " when v3 is "<< v3 << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;

	return (0);
}

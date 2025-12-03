/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:27:41 by fatkeski          #+#    #+#             */
/*   Updated: 2025/12/02 17:17:39 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

int main(void)
{
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	// base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
//
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "a + d = " << a + d << std::endl;//new
	std::cout << "d + d = " << d + d << std::endl;//new
	bigint ff(9900);//new
	std::cout << "ff + ff = " << ff + ff << " where ff is " << ff << std::endl;//new
	std::cout << "(c += a) = " << (c += a) << std::endl;
	std::cout << "c is = " << c << std::endl;//new

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	
	std::cout << "b = " << b << std::endl;
	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042

	std::cout << "(b << 10) = " << (b << 10) << std::endl;//new
	bigint q(42);
	std::cout << "(b << 10) + 42(as q) = " << ((b << 10) + q) << std::endl;
	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
	std::cout << "d = " << d << std::endl;//new 
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "d = " << d << std::endl;//new 
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 5348

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1
	std::cout << "(a >= a) = " << (a >= a) << std::endl; // (d >= a) = 1
	const bigint buid;
	bigint zero;
	std::cout 	<< "(zero > buid) = " << (zero > buid) << " zero is " 
				<< zero << " and buid is " << buid << std::endl;
	std::cout 	<< "(zero >= buid) = " << (zero >= buid) << " zero is " 
				<< zero << " and buid is " << buid << std::endl;

	std::cout 	<< "(zero == buid) = " << (zero == buid) << " zero is " 
				<< zero << " and buid is " << buid << std::endl;
	std::cout 	<< "(zero != buid) = " << (zero != buid) << " zero is " 
				<< zero << " and buid is " << buid << std::endl;
	// extra
	bigint x(12345678); bigint y(5);
	std::cout << "x = " << x << " and y = " << y << std::endl;
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "last test\n";
	bigint gran(100);
	bigint simple(69);
	bigint test(1234);
	std::cout << "Dona 0? " << (simple >> 4) << std::endl;
	std::cout << "Dona 0? " << (simple >>= 4) << std::endl;
	std::cout << "Dona 0? " << (test >>= gran) << std::endl;
	std::cout << "Dona 0? " << simple << std::endl;
	std::cout << "Dona 100 " << (gran >> simple) << std::endl;
	std::cout << "Dona 100 " << (gran >>= simple) <<  " Gran es " << gran << std::endl;
	std::cout << "Dona 100 " << (gran << simple) << std::endl;
	bigint neg(-1);
	std::cout <<"\nNeg = " << neg << std::endl;
	return (0);
}

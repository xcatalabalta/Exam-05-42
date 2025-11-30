#include "bigint.hpp"

int main(void)
{
	//unsigned int w = +69;
	const bigint a(42);
	bigint b(21), c, d(1337), e(d), ww, z(-1);

	// base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "z = " << z << std::endl;
	//std::vector<int> k;
	//std::cout << "k = " << k.max_size() << std::endl; 
	std::cout << "Breaking b <<= (-1) " << (b <<= z) << std::endl;
	std::cout << "Breaking b << (-1) " << (b << z) << std::endl;
	std::cout << "Breaking d <<= (-1)" << (d << -1) << std::endl;
	std::cout << "Breaking b >>= (-1) " << (b >>= z) << std::endl;
	std::cout << "Breaking b >> (-1) " << (b >> z) << std::endl;


	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "d + a = " << d + a << std::endl;
	std::cout << "a + d = " << a + d << std::endl;
	std::cout << "c + c = " << c + c << std::endl;
	std::cout << "z + z = " << (z + z) << std::endl;
	std::cout << "(z += z) = " << (z += z) << std::endl;
	std::cout << "z = " << z << " z + 2 > a = " << ((z + 2) > a) << std::endl;
	z += 2;
	std::cout << "z value = " << z.getInt() << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b + 13 = " << b + 13 << std::endl;
	std::cout << "(b + 13) << 2 = " << ((b + 13) << 2) << std::endl; 
	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042
	std::cout << "(b << 2) + 42 = " << ((b << 2) + 42) << std::endl;
	std::cout << "(b + 13) << 3 + 12 = " << (((b + 13) << 3) + 12) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "d as Int = " << d.getInt() <<std::endl;
	std::cout << "Should be 2 => " << (const bigint)2 << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b << 2 (from big int) = " << (b << (const bigint)2) << std::endl; 
	std::cout << "b = " << b << std::endl;
	std::cout << "b <<= 2 (from big int) = " << (b <<= (const bigint)2) << " b = " << b << std::endl; 
	std::cout << "(d <<= 2) = " << (d <<= (const bigint)2) << ", d: " << d << std::endl;
	std::cout << "(d >> 4) = " << (d >> 4) << ", d: " << d << std::endl;
	std::cout << "(d >> 400) = " << (d >> 400) << ", d: " << d << std::endl;
	std::cout << "ww = " << ww << " ww <<= 2 " << (ww <<= 2) << std::endl;
	std::cout << "ww = " << ww << " ww >> 7 " << (ww >> 7) << std::endl;
	std::cout << "ww = " << ww << " ww >>= 7 " << (ww >>= 7) << " ww = " << ww << std::endl;
	std::cout << "d += 196 " << (d += 196) << " where d is now  "<< d << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;
	std::cout << "d >>= 125 = " << (d >>= 125) << " d = " << d << std::endl;

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 5348

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

	// extra
	bigint x(12345678); bigint y(5) , neg(-1);
	std::cout << "New fellows aboard: x = " << x << " and y = " << y << std::endl;
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "larger us= " << neg << std::endl;
	std::cout << "(x >> y) = " << (x >> y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x <<= 5 x= " << (x <<= 5) << ", y << 12 y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "Destruction of y: " << y << " after y << neg (where neg = " << neg << ")" << std::endl;
	std::cout << "Destruction of y HERE: " << (y << neg) << std::endl;
	std::cout << "Destruction 2 of y: " << y << " after y <<= neg (where neg = " << neg << ")" << std::endl;
	std::cout << "Destruction 2 of y HERE: " << (y <<= neg) << std::endl;
	std::cout << "Do you know that neg += neg is " << (neg += neg) << std::endl; 
	std::cout << "And y is " << y << " ?" << std::endl;
	std::cout << "Just for fun ((y >>= y) += 42) HERE: " << ((y >>= y) += 42) << " and now y = " << y << std::endl;
	std::cout << "(((const bigint)42) + (const bigint)27) = " << (((const bigint)42) + (const bigint)27) << std::endl;
	std::cout << "(((bigint)42) += (const bigint)27) = " << (((bigint)42) += (const bigint)27) << std::endl;
	std::cout << "(((bigint)42) += (bigint)27) = " << (((bigint)42) += (bigint)27) << std::endl;
	std::cout << "\nThe end?\n";

	return (0);
}

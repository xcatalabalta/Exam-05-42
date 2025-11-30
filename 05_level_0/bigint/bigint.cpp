/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 06:38:25 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/03 15:02:27 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint() : digits(1, 0)
{}

bigint::bigint(unsigned int num)
{
	if (num == 0)
	{
		digits.push_back(0);
		return;
	}
	while (num > 0)
	{
		digits.push_back(num % 10);
		num /= 10;
	}
	return;
}

bigint::bigint(const bigint &other) : digits(other.digits)
{}

bigint::~bigint()
{}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		digits = other.digits;
	}
	return (*this);
}

const std::vector<int>& bigint::getDigits() const
{
	return digits;
}

bigint bigint::operator+(const bigint& rh) const
{
	bigint output;
	output.digits.clear();
	unsigned int carry = 0;
	unsigned int sum = 0;
	size_t top = std::max(digits.size(), rh.digits.size());
	for (size_t i = 0; i < top || carry; ++i)
	{
		sum = carry;
		if (i < digits.size())
		{
			sum += digits[i];
		}
		if (i < rh.digits.size())
		{
			sum += rh.digits[i];
		}
		output.digits.push_back(sum % 10);
		carry = sum /10;
	}
	return output;
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

bigint& bigint::operator++()
{
	return *this += bigint(1);
}

bigint bigint::operator++(int)
{
	bigint temp(*this);
	++(*this);
	return temp;
}

bigint bigint::operator<<(const unsigned int shift) const
{
	if (shift <= 0 || this->getInt() == 0)
	{
		return *this;
	}
	bigint temp(*this);
	try
	{
		temp.digits.insert(temp.digits.begin(), shift, 0);
	}
	catch (const std::exception &e)
	{
		std::cout << "\nUnable to shift " << e.what() << std::endl;
	}
	return temp;
}

bigint bigint::operator<<(const bigint &shift) const
{
	return *this << shift.getInt();
}


bigint& bigint::operator<<=(const unsigned int shift)
{
	if (shift <= 0 || this->getInt() == 0)
	{
		return *this;
	}
	try
	{
		digits.insert(digits.begin(), shift, 0);
	}
	catch (const std::exception &e)
	{
		std::cout << "\nUnable to shift " << e.what() << std::endl;
	}
	return *this;
}

bigint& bigint::operator<<=(const bigint& other)
{
	return *this <<= other.getInt();
}

const unsigned int bigint::getInt() const
{
	unsigned int result = 0;
	int multip = 1;
	size_t top = digits.size();

	for (size_t i = 0; i < top; ++i)
	{
		result += digits[i] * multip;
		multip *= 10;
	}
	return result;
}
bigint bigint::operator>>(const unsigned int shift) const
{
	if (shift <= 0 || this->getInt() == 0)
	{
		return *this;
	}
	if (shift >= digits.size())
	{
		bigint buit(0);
		return buit;
	}
	bigint temp(*this);
	temp.digits.erase(temp.digits.begin(), temp.digits.begin() + shift);
	return temp;
}

bigint bigint::operator>>(const bigint &shift) const
{
	return *this >> shift.getInt();
}

bigint& bigint::operator>>=(const unsigned int shift)
{
	if (shift <= 0 || this->getInt() == 0)
	{
		return *this;
	}
	if (shift >= digits.size())
	{
		digits.clear();
		digits[0] = 0;
	}
	else
		digits.erase(digits.begin(), digits.begin() + shift);
	return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
	return *this >>= other.getInt();
}

bool bigint::operator>(const bigint& other) const
{
	return (this->getDigits() > other.getDigits());
	//return (this->getInt() > other.getInt());
}

bool bigint::operator>=(const bigint& other) const
{
	//return (this->getInt() >= other.getInt());
	return (this->getDigits() >= other.getDigits());
}

bool bigint::operator<(const bigint& other) const
{
	return (this->getInt() < other.getInt());
}

bool bigint::operator<=(const bigint& other) const
{
	return (this->getInt() <= other.getInt());
}

bool bigint::operator==(const bigint& other) const
{
	return (this->getInt() == other.getInt());
}

bool bigint::operator!=(const bigint& other) const
{
	return (this->getInt() != other.getInt());
}


std::ostream& operator<<(std::ostream& os, const bigint& num)
{
	const std::vector<int>& out = num.getDigits();
	if (out.empty())
	{
		os << 0;
		return os;
	}
	for (int i = out.size() -1; i >= 0; --i)
	{
		os << out[i];
	}
	return os;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:05:30 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 16:50:03 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint() : n_num(1,0) {}

bigint::~bigint() {}

bigint::bigint(const bigint &other)
{
	n_num = other.n_num;
}

bigint::bigint(unsigned int val)
{
	
	if (val == 0)
	{
		n_num.push_back(0);
		return;
	}
	while (val > 0)
	{
		n_num.push_back(val % 10);
		val /= 10;
	}
}

bigint& bigint::operator=(const bigint &other)
{
	if (this != &other)
	{
		n_num = other.n_num;
	}
	return (*this);
}

bigint bigint::operator+(const bigint &other) const
{
	bigint out;
	out.n_num.clear();
	int large = std::max(n_num.size(), other.n_num.size());
	int carry = 0;
	int res = 0;
	for (int i = 0; i < large; ++i)
	{
		res = carry;
		if (i < n_num.size())
		{
			res += n_num[i];
		}
		if (i < other.n_num.size())
		{
			res += other.n_num[i];
		}
		out.n_num.push_back(res % 10);
		carry = res / 10;
	}
	if (carry > 0)
	{
		out.n_num.push_back(carry);
	}
	return (out);
}

bigint& bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return (*this);
}

bigint& bigint::operator++()
{
	return (*this += bigint (1));
}

bigint bigint::operator++(int)
{
	bigint temp (*this);
	++(*this);
	return (temp);
}

bigint bigint::operator<<(const unsigned int shift) const
{
	bigint temp(*this);
	temp.n_num.insert(temp.n_num.begin(), shift, 0);
	return(temp);
}

bigint bigint::operator<<(const bigint &other) const
{
	unsigned int shift = other.getNum();
	bigint temp(*this);
	temp.n_num.insert(temp.n_num.begin(), shift, 0);
	return(temp);
}

bigint& bigint::operator<<=(const unsigned int shift)
{
	
	n_num.insert(n_num.begin(), shift, 0);
	return (*this);
}

bigint& bigint::operator<<=(const bigint &other)
{
	
	unsigned int shift = other.getNum();
	n_num.insert(n_num.begin(), shift, 0);
	return (*this);
}

bigint bigint::operator>>(const unsigned int shift) const
{
	if (shift >= n_num.size())
		return(0);
	bigint temp(*this);
	temp.n_num.erase(temp.n_num.begin(), temp.n_num.begin() + shift);
	return(temp);
}

bigint bigint::operator>>(const bigint &other) const
{
	unsigned int shift = other.getNum();
	if (shift >>= n_num.size())
		return (0);
	bigint temp(*this);
	temp.n_num.erase(temp.n_num.begin(), temp.n_num.begin() + shift);
	return(temp);
}

bigint& bigint::operator>>=(const unsigned int shift)
{
	if (shift >= n_num.size())
	{
		n_num.clear();
	}
	else
		n_num.erase(n_num.begin(), n_num.begin() + shift);
	return (*this);
}

bigint& bigint::operator>>=(const bigint &other)
{
	
	unsigned int shift = other.getNum();
	if (shift >>= n_num.size())
	{
		n_num.clear();
	}
	else
		n_num.erase(n_num.begin(), n_num.begin() + shift);
	return (*this);
}

bool bigint::operator>(const bigint &other) const
{
	if (n_num.size() > other.n_num.size())
		return (true);
	if (n_num.size() < other.n_num.size())
		return (false);
	for (int i = 0; i < n_num.size() -1 ; ++i)
	{
		if (n_num[i] > other.n_num[i])
			return (true);
		if (n_num[i] < other.n_num[i])
			return (false);
	}
	return (false);
}

bool bigint::operator>=(const bigint &other) const
{
	if (n_num.size() > other.n_num.size())
		return (true);
	if (n_num.size() < other.n_num.size())
		return (false);
	for (int i = 0; i < n_num.size() -1 ; ++i)
	{
		if (n_num[i] > other.n_num[i])
			return (true);
		if (n_num[i] < other.n_num[i])
			return (false);
	}
	return (true);
}

bool bigint::operator<(const bigint &other) const
{
		return (!(*this > other));
}

bool bigint::operator<=(const bigint &other) const
{
		return (!(*this >= other));
}

bool bigint::operator==(const bigint &other) const
{
	if (n_num == other.n_num)
		return (true);
	return (false);
}

bool bigint::operator!=(const bigint &other) const
{
	return (!(*this == other));
}

const std::vector<int>& bigint::getVect() const
{
	return (n_num);
}

unsigned int bigint::getNum() const
{
	unsigned int shift = 0;
	if (!n_num.empty())
	{
		for (int i = n_num.size() - 1; i >= 0; --i)
		{
			shift *= 10;
			shift += n_num[i];
		}
	}
	return (shift);
}

std::ostream& operator<<(std::ostream &oss, const bigint& big)
{
	std::vector<int> out = big.getVect();
	
	if (out.empty())
	{
		oss << 0;
	}
	else
	{
		for (int i = out.size() -1; i > -1; --i)
			oss << out[i];
	}
	return (oss);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 05:51:40 by fcatala-          #+#    #+#             */
/*   Updated: 2025/11/03 15:44:15 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP
#include <iostream>
#include <vector>
#include <algorithm>
///#include <string>
#include <stdexcept>

class bigint
{
	private:
		std::vector<int> digits;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& other);
		~bigint();
		
		bigint& operator=(const bigint& other);
		const std::vector<int>& getDigits() const;
		bigint operator+(const bigint& rh) const;
		bigint& operator+=(const bigint& other);
		bigint& operator++();
		bigint operator++(int);
		bigint operator<<(const unsigned int shift) const;
		bigint operator<<(const bigint& other) const;
		bigint& operator<<=(const unsigned int shift);
		bigint& operator<<=(const bigint& other);
		bigint operator>>(const unsigned int shift) const;
		bigint operator>>(const bigint& other) const;
		bigint& operator>>=(const unsigned int shift);
		bigint& operator>>=(const bigint& other);
		const unsigned int getInt() const;
		bool operator>(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;


};
std::ostream& operator<<(std::ostream& os, const bigint& num);
#endif

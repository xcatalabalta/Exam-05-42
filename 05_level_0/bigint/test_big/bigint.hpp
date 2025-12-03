/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:56:05 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 16:49:47 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>


class bigint
{
	private:
		std::vector<int> n_num;
	public:
		bigint();
		~bigint();
		bigint(const bigint &other);
		bigint(unsigned int val);
		bigint&	operator=(const bigint &other);
		bigint  operator+(const bigint &other) const;
		bigint& operator+=(const bigint &other);
		bigint& operator++();
		bigint 	operator++(int);
		bigint	operator<<(const unsigned int shift) const; 
		bigint	operator<<(const bigint &other) const; 
		bigint& operator<<=(const unsigned int shift);
		bigint& operator<<=(const bigint &other);
		bigint	operator>>(const unsigned int shift) const; 
		bigint	operator>>(const bigint &other) const; 
		bigint& operator>>=(const unsigned int shift);
		bigint& operator>>=(const bigint &other);
		bool	operator>(const bigint &other) const;
		bool	operator>=(const bigint &other) const;
		bool	operator<(const bigint &other) const;
		bool	operator<=(const bigint &other) const;
		bool	operator==(const bigint &other) const;
		bool	operator!=(const bigint &other) const;
		const std::vector<int>& getVect() const;
		unsigned int getNum() const;
};

std::ostream& operator<<(std::ostream &oss, const bigint& big);

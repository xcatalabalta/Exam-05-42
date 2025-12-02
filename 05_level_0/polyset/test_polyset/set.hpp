/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:40:01 by fcatala-          #+#    #+#             */
/*   Updated: 2025/12/02 19:54:29 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"

class set : public searchable_bag
{
	private:
		searchable_bag& m_bag;
	public:
		set() = delete;
		~set();
		set(const set &other) = delete;
		set& operator=(const set &other) = delete;
		set(searchable_bag &other);
		

};

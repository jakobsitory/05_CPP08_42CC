/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:57:40 by jschott           #+#    #+#             */
/*   Updated: 2024/03/01 09:04:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#define TEXT_NOFORMAT	"\e[0m"
#define TEXT_BOLD		"\e[1m"
#define TEXT_UNDERLINE	"\e[4m"

#define COLOR_STANDARD	"\033[0m"
#define	COLOR_ERROR		"\033[31m"
#define COLOR_WARNING	"\033[33m"
#define COLOR_SUCCESS	"\033[92m"
#define COLOR_FOCUS		"\e[35m"

#include <exception>
#include <algorithm>

class NotFoundExeption : public std::exception {
public:
	virtual const char *what() const throw(){
		return "EasyFind: Integer Not found";
	}
};

template <typename T>
void easyfind(const T& haystack, int num){
	typename T::const_iterator needle;
	needle = find(haystack.begin(), haystack.end(), num);
	if (needle == haystack.end())
		throw NotFoundExeption();
	std::cout << COLOR_SUCCESS << "Found it!" << COLOR_STANDARD << std::endl;
}

#endif
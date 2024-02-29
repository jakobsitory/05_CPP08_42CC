/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:52:43 by jschott           #+#    #+#             */
/*   Updated: 2024/02/29 18:08:50 by jschott          ###   ########.fr       */
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

#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <cstdlib>
#include <iterator>

class Span
{
private:
	std::list<int>	_storage;
	int				_maxSize;

	Span();
public:
	Span(int const N);
	Span(Span & origin);
	Span& operator= (Span & origin);
	~Span();

	void			addNumber(int num);
	int				shortestSpan() const;
	int				longestSpan() const;
	std::list<int>	getStorage() const;
	int				getMaxSize() const;

	class ContainerFullException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Span: Container is full");
			};
	};
	class ContainerEmptyException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Span: Container is empty");
			};
	};
	class ContainerOneElementException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Span: Container only has one element");
			};
	};
	class ContainerUndefinedException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Span: Undefined Exception");
			};
	};
};

std::ostream& operator<<(std::ostream& os, Span const & object);

#endif
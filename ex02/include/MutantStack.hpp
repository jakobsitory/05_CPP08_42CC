/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:26:59 by jschott           #+#    #+#             */
/*   Updated: 2024/03/01 11:29:56 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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
#include <deque>
#include <stack>
#include <iterator>
#include <cstdlib>
#include <iterator>

template <typename T, class Container = std::deque< T > >
class MutantStack : public std::stack<T, Container> 
{
public:
	MutantStack() : std::stack<T>() {};
	MutantStack(MutantStack const & origin) : MutantStack<T, Container>::template stack<T>(origin) {};
	MutantStack & operator=(MutantStack const & origin) {
		if (this == &origin)
			return this;
		this->MutantStack<T, Container>::stack::operator=(origin);
		return this;
	};
	~MutantStack(){};

	typedef typename Container::iterator			iterator;
	typedef typename Container::reverse_iterator	reverse_iterator;
	
	iterator begin() {
		return (this->c.begin());
	};
	
	iterator end() {
		return (this->c.end());
	};
	
	reverse_iterator rbegin() {
		return (this->c.rbegin());
	};
	
	reverse_iterator rend() {
		return (this->c.rend());
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T> & object){
	for (typename MutantStack<T>::iterator it = object.begin();
			it != object.end(); it++)
		os << "[" << *it << "]";
	return os;
}

#endif

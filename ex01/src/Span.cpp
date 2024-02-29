/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:54:02 by jschott           #+#    #+#             */
/*   Updated: 2024/02/29 18:20:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iterator>

Span::Span(){
	this->_maxSize = 0;
	std::list<int> tmp;
	this->_storage = tmp;
}

Span::Span(int const N){
	if (N < 0)
		throw Span::ContainerUndefinedException();
	this->_maxSize = N;
	std::list<int> newlist;
	this->_storage = newlist;
}

Span::Span(Span & origin){
	*this = origin;
}

Span& Span::operator= (Span & origin){
	if (this == &origin)
		return *this;
	this->_maxSize = origin.getMaxSize();
	this->_storage = origin.getStorage();
	return *this;
}

Span::~Span(){
}

void	Span::addNumber(int num){
	if (static_cast<int>(this->_storage.size()) == this->_maxSize)
		throw Span::ContainerFullException();
	else {
		this->_storage.push_back(num);
	}
}

int		Span::shortestSpan() const{
	if (this->_storage.size() == 0)
		throw Span::ContainerEmptyException();	
	else if (this->_storage.size() == 1)
		throw Span::ContainerOneElementException();
	std::list<int> help = this->_storage;
	help.sort();
	int span = std::abs(help.front() - *(++help.begin()));
	for (std::list<int>::iterator it = help.begin();
			it != help.end(); ++it){
		std::list<int>::iterator next = it;
		++next;
		if (next != help.end()){
			int next_span = std::abs(*it - *next);
			span = std::min(next_span, span);
		}
	}
	return (span);
}

int		Span::longestSpan() const{
	if (this->_storage.size() == 0)
		throw Span::ContainerEmptyException();	
	else if (this->_storage.size() == 1)
		throw Span::ContainerOneElementException();	
	int	min = this->_storage.front();
	int max = min;
	for (std::list<int>::const_iterator it = this->_storage.begin(); 
			it != this->_storage.end(); ++it){
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return std::abs(max - min);
}

std::list<int>	Span::getStorage() const{
	return this->_storage;
}
int	Span::getMaxSize() const{
	return this->_maxSize;
}

std::ostream& operator<<(std::ostream& os, Span const & object){
	std::list<int> tmp = object.getStorage();
	for (std::list<int>::iterator it = tmp.begin();
			it != tmp.end(); it++)
		os << "[ " << *it << " ]";
	for (int i = tmp.size(); i < object.getMaxSize(); i++)
	 	os << "[ ]";
	return os;
}
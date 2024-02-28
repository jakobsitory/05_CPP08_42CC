/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:58:10 by jschott           #+#    #+#             */
/*   Updated: 2024/02/28 17:44:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "easyfind.hpp"

int	main(){
	std::vector<int> stuff;

	std::cout << "Welcome to easyfind!" << std::endl;
	std::cout << "Enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << " to exit."<< std::endl;
	std::cout << "Press " << TEXT_BOLD << "ENTER" << TEXT_NOFORMAT << " to start simulation" << std::endl;
	std::string input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){

		input = "";
		
		//ADD VALUES TO VECTOR
		std::cout << std::endl << "Please enter " << TEXT_BOLD 
			<< "integers" << TEXT_NOFORMAT << " (one at a time) to add them to the container." << std::endl;
		std::cout << "When finished enter " << TEXT_BOLD 
			<< "DONE" << TEXT_NOFORMAT << "." << std::endl;
		while (input != "DONE"){
			for (std::vector<int>::iterator pos = stuff.begin(); pos != stuff.end(); pos++){
				std::cout << "[" << *pos << "]";
			}
			std::cout << " ";
			std::getline(std::cin, input);
			if (std::atoi(input.c_str()) || input == "0")
				stuff.push_back(std::atoi(input.c_str()));
		}
		input = "";

		//OUTPUT
		std::cout << std::endl << "Created int container of length " << stuff.size() << std::endl;
		for (std::vector<int>::iterator pos = stuff.begin(); pos != stuff.end(); pos++){
			std::cout << "[" << *pos << "]";
		}
		std::cout << std::endl;

		//EASYFIND
		std::cout << std::endl << "Please enter " << TEXT_BOLD 
			<< "integer" << TEXT_NOFORMAT << " to search in the container" << std::endl;
		std::cout << "When finished enter " << TEXT_BOLD 
			<< "DONE" << TEXT_NOFORMAT << "." << std::endl;
		while (input != "DONE"){
			std::getline(std::cin, input);
			if (std::atoi(input.c_str()) || input == "0"){
				try{
					easyfind(stuff, std::atoi(input.c_str()));
					std::cout << COLOR_SUCCESS << "Found it!" << COLOR_STANDARD << std::endl;
				}
				catch(const std::exception& e){
					std::cerr << COLOR_ERROR << e.what() << COLOR_STANDARD << std::endl;
				}			
			}
		}
		input = "";
		
		std::cout << "Enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << " to exit."<< std::endl;
		std::cout << "Press " << TEXT_BOLD << "ENTER" << TEXT_NOFORMAT << " to restart simulation" << std::endl;
		input = "";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
	}


	return 0;
}
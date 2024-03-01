/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:58:10 by jschott           #+#    #+#             */
/*   Updated: 2024/03/01 09:29:09 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int	main(){
	Span *stuff = NULL;
	int num = 0;
	
	std::cout << "Welcome to Span Calculator!" << std::endl;
	std::cout << "Enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << " to exit."<< std::endl;
	std::cout << "Press " << TEXT_BOLD << "ENTER" << TEXT_NOFORMAT << " to start simulation" << std::endl;
	std::string input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){
		input = "";
		
		//CREATE CONTAINER
		std::cout << std::endl << "Enter " << TEXT_BOLD 
			<< "an integer" << TEXT_NOFORMAT << " to create a container of this size container." << std::endl;
		while (!num && input != "0"){
			input = "";
			std::getline(std::cin, input);
			num = std::atoi(input.c_str());
		}
		try	{
			stuff = new Span(std::atoi(input.c_str()));
			std::cout << COLOR_SUCCESS << "SUCCESS! " << COLOR_STANDARD << *stuff << std::endl;			
			try	{
				
				//FILL CONTAINER
				std::cout << std::endl << "Enter " << TEXT_BOLD 
					<< "a positive integer" << TEXT_NOFORMAT << " fill container with a number of random integers." << std::endl;
				num = 0;
				input = "";
				while ((!num && input != "0")
						|| num < 0){
					input = "";
					std::getline(std::cin, input);
					num = std::atoi(input.c_str());
				}
				srand(time(NULL));
				for (int i = 0; i < num; i++)
					stuff->addNumber((rand() - rand()) % 10000 );
				std::cout << COLOR_SUCCESS << "SUCCESS! " << COLOR_STANDARD << std::endl << *stuff << std::endl;

				// DO CONTAINER OPERATIONS
				std::cout << std::endl << "Enter " << std::endl << TEXT_BOLD 
					<< "\tan integer" << TEXT_NOFORMAT << " to add it to container." << std::endl << TEXT_BOLD 
					<< "\tSHORT" << TEXT_NOFORMAT << " to get shortest span between two container elements." << std::endl << TEXT_BOLD 
					<< "\tLONG" << TEXT_NOFORMAT << " to get shortest span between two container elements." << std::endl << TEXT_BOLD
					<< "\tPRINT" << TEXT_NOFORMAT << " to print the container." << std::endl << TEXT_BOLD
					<< "\tCOPY" << TEXT_NOFORMAT << " to create a copy of the container and print it." << std::endl << TEXT_BOLD
					<< "\tDONE" << TEXT_NOFORMAT << " when you're done testing." << std::endl;
				input = "";
				num = 0;
				while (input != "DONE"){
					input = "";
					num = 0;
					std::getline(std::cin, input);
					num = std::atoi(input.c_str());
					try{
						if (input == "COPY"){
							Span copy(*stuff);
							std::cout << copy << std::endl << COLOR_SUCCESS << "SUCCESS! " << COLOR_STANDARD << std::endl;
						}
						else if (input == "PRINT")
							std::cout << *stuff << std::endl;
						else if (input == "SHORT")
							std::cout << "Shortest Span: " << stuff->shortestSpan() << std::endl;
						else if (input == "LONG")
							std::cout << "Longest Span: " << stuff->longestSpan() << std::endl;
						else if ((num || input != "0") && input != "DONE"){
							stuff->addNumber(num);
							std::cout << num << " added" << std::endl;
						}
					}
					catch(const std::exception& e){
						std::cerr << COLOR_ERROR << e.what() << COLOR_STANDARD << std::endl;
						input = "";
						num = 0;
					}
				}
			}
			catch(const std::exception& e){
				std::cerr << COLOR_ERROR << e.what() << COLOR_STANDARD << std::endl;
			}		
		}
		catch(const std::exception& e){
			std::cerr << COLOR_ERROR << e.what() << COLOR_STANDARD << std::endl;
		}
		
		input = "";
		delete (stuff);
		std::cout << "Enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << " to exit."<< std::endl;
		std::cout << "Press " << TEXT_BOLD << "ENTER" << TEXT_NOFORMAT << " to restart simulation" << std::endl;
		input = "";
		num = 0;
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
	}
	return 0;
}

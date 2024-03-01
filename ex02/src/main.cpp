/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:28:44 by jschott           #+#    #+#             */
/*   Updated: 2024/03/01 11:44:13 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <ctime>
#include <stack>
#include <list>

int	main(){
	// std::list<int> stuff;
	// std::list<int>::iterator it;
	// std::vector<int> stuff;
	// std::vector<int>::iterator it;
	MutantStack<int> stuff;
	MutantStack<int>::iterator it;
	
	
	int num = 0;
	
	std::cout << "Welcome to Mutated Stacks!" << std::endl;
	std::cout << "Enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << " to exit."<< std::endl;
	std::cout << "Press " << TEXT_BOLD << "ENTER" << TEXT_NOFORMAT << " to start simulation" << std::endl;
	std::string input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){
		input = "";
		
		//CREATE CONTAINER
		std::cout << std::endl << "Enter " << TEXT_BOLD 
			<< "an integer" << TEXT_NOFORMAT << " to create a MutantStack of this size and fill it with random integers." << std::endl;
		while (!num && input != "0"){
			input = "";
			std::getline(std::cin, input);
			num = std::atoi(input.c_str());
		}	
		try	{
			
			//FILL CONTAINER
			srand(time(NULL));
			for (int i = 0; i < num; i++)
				stuff.push((rand() - rand()) % 10000);
			std::cout << COLOR_SUCCESS << "SUCCESS! " << COLOR_STANDARD << std::endl
				<< "Created MutantStack of size " << stuff.size() << std::endl;

			// DO CONTAINER OPERATIONS
			std::cout << std::endl << "Enter " << std::endl << TEXT_BOLD 
				<< "\tInteger\t" << TEXT_NOFORMAT << " to add it to MutantStack." << std::endl << TEXT_BOLD 
				<< "\tPOP\t" << TEXT_NOFORMAT << " to remove first element in MutantStack." << std::endl << TEXT_BOLD 
				<< "\tBEGIN\t" << TEXT_NOFORMAT << " to get first element in MutantStack." << std::endl << TEXT_BOLD 
				<< "\tEND\t" << TEXT_NOFORMAT << " to get last element in MutantStack." << std::endl << TEXT_BOLD
				<< "\t++" << TEXT_NOFORMAT << "/" << TEXT_BOLD << "--\t" << TEXT_NOFORMAT << " to iterate through MutantStack." << std::endl << TEXT_BOLD				
				<< "\tPRINT\t" << TEXT_NOFORMAT << " to print the MutantStack." << std::endl << TEXT_BOLD
				<< "\tDONE\t" << TEXT_NOFORMAT << " when you're done testing." << std::endl;

			input = "";
			num = 0;
			it = stuff.begin();
			while (input != "DONE"){
				input = "";
				num = 0;
				std::getline(std::cin, input);
				num = std::atoi(input.c_str());
				if (input == "PRINT") //ONLY WORKS FOR MUTANTSTACK
					std::cout << stuff << std::endl;
					// std::cout << "THIS FEATURE ONLY WORKS ON MUTANTSTACKS" << std::endl;
				else if (input == "POP"){
					std::cout << "Removing: " << *(--stuff.end()) << std::endl;
					stuff.pop();
				}
				else if (input == "BEGIN")
					std::cout << "Frst Element: " << *(it = stuff.begin()) << std::endl;
				else if (input == "END")
					std::cout << "Last Element: " << *(it = stuff.end()) << std::endl;
				else if (input == "++"&& it + 1 != stuff.end())
					std::cout << "Next Element: " << *(++it) << std::endl;
				else if (input == "--" && it != stuff.begin())
					std::cout << "Prev Element: " << *(--it) << std::endl;
				else if (input == "--" || input == "++")
					std::cout << "End of MutantStack reached" << std::endl;
				else if ((num || input == "0") && input != "DONE"){
					stuff.push(num);
					std::cout << num << " added" << std::endl;
				}
			}
		}		
		catch(const std::exception& e){
			std::cerr << COLOR_ERROR << e.what() << COLOR_STANDARD << std::endl;
		}
		
		input = "";
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

int subject()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

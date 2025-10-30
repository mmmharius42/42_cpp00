/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:28:44 by mpapin            #+#    #+#             */
/*   Updated: 2025/10/30 04:52:28 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string     input;
    PhoneBook       phoneBook;

    while(1)
    {
        std::cout << "Write a command (EXIT, ADD, SEARCH): ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Ctrl D catch ehehe" << std::endl;
            exit(1);
        }
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContacts();
    }
    
    return 0;
}
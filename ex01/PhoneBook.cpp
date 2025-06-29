/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:16:47 by mpapin            #+#    #+#             */
/*   Updated: 2025/06/29 05:24:52 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() {
    _nbContacts = 0;
    _curContacts = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact() {
    std::string     input;
    std::string     name;
    std::string     last_name;

    if (_curContacts >= 8) {
        _curContacts = 0;
        std::cout << "The Max Number of Contact have been reached, delete the fisrt one..." << std::endl;
    }
    std::cout << "First Name of the contact you want to add :" << std::endl;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Erreur: champ vide!" << std::endl;
        return;
    }
    this->contacts[_curContacts].setFirstName(input);
    name = input;
    std::cout << "Last Name of " <<  name << ":" << std::endl;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Erreur: champ vide!" << std::endl;
        return; 
    }
    last_name = input;
    this->contacts[_curContacts].setLastName(input);
    std::cout << "Nickname of " << name << ":" << std::endl;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Erreur: champ vide!" << std::endl;
        return;
    }
    this->contacts[_curContacts].setNickname(input);
    std::cout << "The Phone Number of " << input << ":" << std::endl;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Erreur: champ vide!" << std::endl;
        return;
    }
    this->contacts[_curContacts].setPhoneNumber(input);
    std::cout << "The Darkest secret of " << name << " " << last_name << " :" << std::endl;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Erreur: champ vide!" << std::endl;
        return;
    }
    this->contacts[_curContacts].setDarkSecret(input);
    std::cout << "Contact ajouté avec succès!" << std::endl;
    std::cout << std::endl;
    _curContacts = (_curContacts + 1) % 8;
    if (_nbContacts < 8) {
        _nbContacts++;
    }
}

void PhoneBook::searchContacts() {
    std::string     input;
    
    displayAllContacts();
    std::cout << "Who ?";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int index;
    
    if (!(iss >> index) || index < 0 || index >= _nbContacts) {
        std::cout << "Index invalide!" << std::endl;
        return;
    }
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Secret: " << contacts[index].getDarkSecret() << std::endl << std::endl;
}

std::string	truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::displayAllContacts() {
    if (_nbContacts == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    
    for (int i = 0; i < _nbContacts; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << "|"
                  << std::endl;
    }
    std::cout << std::endl;
}

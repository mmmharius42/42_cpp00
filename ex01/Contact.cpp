/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:08:28 by mpapin            #+#    #+#             */
/*   Updated: 2025/06/28 21:15:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string Contact::getFirstName() const {
    return(this->_firstName);
}

std::string Contact::getLastName() const {
    return(this->_lastName);
}

std::string Contact::getNickname() const {
    return(this->_nickname);
}

std::string Contact::getPhoneNumber() const {
    return(this->_phoneNumber);
}

std::string Contact::getDarkSecret() const {
    return(this->_darkSecret);
}

void Contact::setFirstName(std::string name) {
    this->_firstName = name;
}

void Contact::setLastName(std::string name) {
    this->_lastName = name;
}

void Contact::setNickname(std::string last_name) {
    this->_nickname = last_name;
}

void Contact::setPhoneNumber(std::string number) {
    this->_phoneNumber = number;
}

void Contact::setDarkSecret(std::string secret) {
    this->_darkSecret = secret;
}
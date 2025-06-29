/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:28:59 by mpapin            #+#    #+#             */
/*   Updated: 2025/06/29 05:12:18 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <sstream> //istringstream
#include <iomanip> //setw

class Contact {
    private:
        std::string     _firstName;
        std::string     _lastName;
        std::string     _nickname;
        std::string     _phoneNumber;
        std::string     _darkSecret;

    public:

        Contact();
        ~Contact();
        
        std::string     getFirstName() const;
        std::string     getLastName() const;
        std::string     getNickname() const;
        std::string     getPhoneNumber() const;
        std::string     getDarkSecret() const;
        
        void        setFirstName(std::string name);
        void        setLastName(std::string name);
        void        setNickname(std::string nickname);
        void        setPhoneNumber(std::string number); 
        void        setDarkSecret(std::string secret);
        
        bool isEmpty() const;
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     _nbContacts;
        int     _curContacts;

    public:

        PhoneBook();
        ~PhoneBook();
        
        void        addContact();
        void        searchContacts();
        void        displayAllContacts();
};

#endif
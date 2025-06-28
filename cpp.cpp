# Cours C++ Module 00 - Les Bases

## 1. Introduction : Du C au C++

Le C++ est une extension du C avec des fonctionnalités orientées objet. La bonne nouvelle : tout ce que tu sais en C reste valable ! Le C++ ajoute juste des concepts supplémentaires.

### Principales différences avec le C :
- **Classes et objets** (programmation orientée objet)
- **Namespaces** (espaces de noms)
- **Surcharge de fonctions**
- **Références**
- **Streams d'entrée/sortie** (cout, cin au lieu de printf/scanf)

## 2. Compilation et Structure

### Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o programme
```

### Structure des fichiers
- **Header (.hpp)** : Déclarations des classes
- **Source (.cpp)** : Implémentations des méthodes
- **Makefile** : Automatisation de la compilation

## 3. Streams d'entrée/sortie

Remplace `printf()` et `scanf()` par les streams C++ :

```cpp
#include <iostream>
#include <string>

// Sortie
std::cout << "Hello World!" << std::endl;

// Entrée
std::string input;
std::cin >> input;              // Un mot
std::getline(std::cin, input);  // Une ligne complète
```

**Pourquoi std:: ?** C'est le namespace standard. On évite `using namespace std;` dans ce module.

## 4. Classes et Objets - Le Concept Central

Une **classe** est un modèle pour créer des objets. Un **objet** est une instance de classe.

### Structure de base d'une classe

```cpp
// Dans le fichier .hpp
class Contact {
private:    // Accessible seulement dans la classe
    std::string _firstName;
    std::string _lastName;

public:     // Accessible de l'extérieur
    Contact();                          // Constructeur
    ~Contact();                         // Destructeur
    
    void setFirstName(std::string name); // Setter
    std::string getFirstName() const;    // Getter
};
```

```cpp
// Dans le fichier .cpp
#include "Contact.hpp"

Contact::Contact() {
    // Initialisation
}

Contact::~Contact() {
    // Nettoyage
}

void Contact::setFirstName(std::string name) {
    this->_firstName = name;
}

std::string Contact::getFirstName() const {
    return this->_firstName;
}
```

## 5. Concepts Clés

### Public vs Private
- **Private** : Accessible seulement dans la classe (données sensibles)
- **Public** : Accessible de partout (interface de la classe)

### Constructeur et Destructeur
- **Constructeur** : Appelé automatiquement à la création de l'objet
- **Destructeur** : Appelé automatiquement à la destruction de l'objet

### Le mot-clé `const`
- **Fonction const** : Promet de ne pas modifier l'objet
- **Variable const** : Ne peut pas être modifiée après initialisation

### `this`
Pointeur vers l'objet courant. Utile pour distinguer les paramètres des attributs.

## 6. Gestion des Chaînes

```cpp
#include <string>

std::string str = "Hello";
str += " World";                    // Concaténation
str.length();                       // Longueur
str.substr(0, 5);                   // Sous-chaîne
str.find("World");                  // Recherche

// Conversion majuscule
#include <cctype>
for (size_t i = 0; i < str.length(); i++) {
    str[i] = std::toupper(str[i]);
}
```

## 7. Tableaux et Conteneurs

Pour le Module 00, on utilise des tableaux statiques (pas de STL) :

```cpp
class PhoneBook {
private:
    Contact _contacts[8];    // Tableau fixe de 8 contacts
    int _currentIndex;       // Index courant
    int _totalContacts;      // Nombre total de contacts
    
public:
    void addContact(Contact newContact);
    void displayContacts();
};
```

## 8. Formatage d'Affichage

Pour l'exercice du PhoneBook, tu auras besoin de formater l'affichage :

```cpp
#include <iomanip>

// Aligner à droite sur 10 caractères
std::cout << std::setw(10) << std::right << text << "|";

// Tronquer si trop long
std::string truncate(std::string str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}
```

## 9. Gestion des Erreurs et Validation

```cpp
// Vérifier si une chaîne est vide
if (input.empty()) {
    std::cout << "Erreur : champ vide!" << std::endl;
    return false;
}

// Vérifier si c'est un nombre
bool isNumber(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
```

## 10. Structure Type pour un Exercice

### Exercice 00 (Megaphone)
```cpp
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++) {
            std::cout << (char)std::toupper(arg[j]);
        }
    }
    std::cout << std::endl;
    return 0;
}
```

### Exercice 01 (PhoneBook) - Structure
```cpp
// Contact.hpp
class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    void setContact(/* paramètres */);
    void displayContact();
    std::string getFirstName() const;
    // ... autres getters
    bool isEmpty() const;
};

// PhoneBook.hpp
class PhoneBook {
private:
    Contact _contacts[8];
    int _currentIndex;
    int _totalContacts;

public:
    PhoneBook();
    void addContact();
    void searchContact();
    void displayAllContacts();
};
```

## 11. Conseils Pratiques

### Organisation du Code
1. **Sépare la logique** : Une classe = un fichier .hpp + un fichier .cpp
2. **Include guards** : Protège tes headers avec `#ifndef`, `#define`, `#endif`
3. **Nommage** : Classes en UpperCamelCase, attributs privés avec `_`

### Debugging
- Utilise `std::cout` pour déboguer
- Compile souvent avec tous les flags
- Teste les cas limites (entrées vides, indices invalides)

### Bonnes Pratiques
- **Encapsulation** : Garde les données privées, expose des méthodes publiques
- **Const correctness** : Utilise `const` quand une méthode ne modifie pas l'objet
- **Gestion mémoire** : Pas d'allocation dynamique dans ce module, mais attention aux fuites plus tard

## 12. Exemple Complet Minimal

```cpp
// Example.hpp
#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <string>

class Example {
private:
    std::string _name;

public:
    Example();
    Example(std::string name);
    ~Example();
    
    void setName(std::string name);
    std::string getName() const;
    void display() const;
};

#endif

// Example.cpp
#include <iostream>
#include "Example.hpp"

Example::Example() : _name("Default") {
    std::cout << "Constructeur par défaut" << std::endl;
}

Example::Example(std::string name) : _name(name) {
    std::cout << "Constructeur avec paramètre" << std::endl;
}

Example::~Example() {
    std::cout << "Destructeur" << std::endl;
}

void Example::setName(std::string name) {
    this->_name = name;
}

std::string Example::getName() const {
    return this->_name;
}

void Example::display() const {
    std::cout << "Nom: " << this->_name << std::endl;
}
```

---

## Points Clés à Retenir

1. **C++ = C + Classes** : Tu peux réutiliser tes connaissances C
2. **Encapsulation** : Private pour les données, public pour l'interface
3. **Streams** : `std::cout` et `std::cin` remplacent printf/scanf
4. **Pas de STL** : Utilise des tableaux statiques dans ce module
5. **Const correctness** : Utilise `const` pour les méthodes qui ne modifient pas l'objet

Avec ces bases, tu peux maintenant attaquer l'exercice 00 ! N'hésite pas si tu as des questions spécifiques pendant ton implementation.
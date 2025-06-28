/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:45:23 by mpapin            #+#    #+#             */
/*   Updated: 2025/06/28 17:21:56 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i, j;
    for(i = 1; argv[i]; i++) {
        for (j = 0; argv[i][j]; j++) {
            char c = std::toupper(argv[i][j]);
            std::cout << c;
        }
    }
    std::cout << std::endl;
    return (0);
}

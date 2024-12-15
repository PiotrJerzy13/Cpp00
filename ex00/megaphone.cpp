/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotrwojnarowski <piotrwojnarowski@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:03:51 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/12/15 10:13:06 by piotrwojnar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
       std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
		for (int i = 1; i < argc; ++i)
		{
			std::string arg = argv[i];
        	for (size_t j = 0; j < arg.size(); ++j)
       		{
                std::cout << (char)(toupper(arg[j]));
        	}
        	std::cout << std::endl;
		}
    }
    return 0;
}
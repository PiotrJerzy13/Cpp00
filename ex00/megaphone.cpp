/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:03:51 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/11/02 16:32:39 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else
    {
		for (int i = 1; i < argc; ++i)
		{
			std::string arg = argv[i];
        	for (size_t j = 0; j < arg.size(); ++j)
       		{
                std::cout << (char)(std::toupper(arg[j]));
        	}
        	std::cout << "\n";
		}
    }
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:03:51 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/01/15 13:09:34 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string trim(const std::string &str) 
{
    size_t start;
	size_t end;
	
	start = 0;
    while (start < str.size() && std::isspace(str[start]))
	{
        ++start;
    }
	
	end = str.size();
    while (end > start && std::isspace(str[end - 1])) 
	{
        --end;
    }
    return str.substr(start, end - start);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) 
		{
            std::string arg = trim(argv[i]);

            for (size_t j = 0; j < arg.size(); ++j) 
			{
                std::cout << (char)(toupper(arg[j]));
            }
            if (i < argc - 1) 
			{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

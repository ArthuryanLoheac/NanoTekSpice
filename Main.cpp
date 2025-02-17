/*
** EPITECH PROJECT, 2025
** Test
** File description:
** main
*/

#include <iostream>
#include "Parsing.hpp"

static int run(const char *file)
{
    std::string content;
    std::vector<std::string> lines;
    
    try {
        content = parseFile(file);
        lines = parseByLine(content);
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
       throw std::invalid_argument("Usage: ./nanotekspice [file.nts]");
       return 84;
    }
    return run(av[1]);
}
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
    std::vector<std::string> withoutCommentary;
    std::vector<std::string> chipsets;
    std::vector<std::string> links;
    
    try {
        content = parseFile(file);
        lines = parseByLine(content);
        withoutCommentary = removeCommentary(lines);
        chipsets = getPartList(withoutCommentary, ".chipsets:", ".links:");
        links = getPartList(withoutCommentary, ".links:", ".chipsets:");
        std::cout << "- Chipsets:" << std::endl;
        for (size_t i = 0; i < chipsets.size(); i++)
            std::cout << chipsets[i] << std::endl;
        std::cout << "- Links:" << std::endl;
        for (size_t i = 0; i < links.size(); i++)
            std::cout << links[i] << std::endl;
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
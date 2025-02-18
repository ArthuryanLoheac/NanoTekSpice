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
    std::vector<std::string> lines, withoutCommentary, chipsetsRaw, linksRaw;
    std::vector<std::vector<std::string>> chipsets, links;
    
    try {
        content = parseFile(file);
        lines = parseByLine(content);
        withoutCommentary = removeCommentary(lines);
        chipsetsRaw = getPartList(withoutCommentary, ".chipsets:", ".links:");
        linksRaw = getPartList(withoutCommentary, ".links:", ".chipsets:");
        chipsets = ParseBySpaces(chipsetsRaw);
        links = ParseBySpaces(linksRaw);
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
       std::cerr << "Usage: ./nanotekspice [file.nts]" << std::endl;
       return 84;
    }
    return run(av[1]);
}
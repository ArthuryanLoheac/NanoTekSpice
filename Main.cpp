/*
** EPITECH PROJECT, 2025
** Test
** File description:
** main
*/

#include <iostream>
#include "Parsing.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        throw std::invalid_argument("Usage: ./nanotekspice [file.nts]");
        return 84;
    }
    return parseFile(av[1]);
}
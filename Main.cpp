/*
** EPITECH PROJECT, 2025
** Main.cpp
** File description:
** Main.cpp
*/

#include <iostream>
#include "Parsing.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
       std::cerr << "Usage: ./nanotekspice [file.nts]" << std::endl;
       return 84;
    }
    return parse(av[1]);
}

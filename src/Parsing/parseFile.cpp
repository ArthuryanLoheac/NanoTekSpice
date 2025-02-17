/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** parseFile
*/
#include <fstream>
#include <iostream>

int parseFile(char *file)
{
    std::ifstream f(file);
    std::string content;

    if (f.is_open()) {
        content = std::string((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());
        std::cout << content;
        f.close();
        return 0;
    } else {
        throw std::invalid_argument("Error: Unable to open file");
        return 84;
    }
}

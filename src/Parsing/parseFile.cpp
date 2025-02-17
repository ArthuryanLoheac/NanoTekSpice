/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** parseFile
*/
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

std::vector<std::string> parseByLine(std::string content)
{
    std::stringstream stream(content);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::string parseFile(const char *file)
{
    std::ifstream f(file);
    std::string content;

    if (f.is_open()) {
        content = std::string((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());
        f.close();
        return content;
    } else
        throw std::invalid_argument("Error: Unable to open file");
}

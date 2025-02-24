/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** run
*/
#include "Circuit.hpp"

std::vector<std::string> splitString(const std::string& str, const std::string& delimiters) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = 0;

    while ((end = str.find_first_of(delimiters, start)) != std::string::npos) {
        if (end != start)
            result.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    if (start < str.size())
        result.push_back(str.substr(start));
    return result;
}

static int analyseCommand(nts::Circuit &circuit, std::string input)
{
    std::vector<std::string> parts = splitString(input, " \t");

    if (parts.size() <= 0)
        return 0;
    if (parts[0] == "exit")
        return 1;
    if (parts[0] == "display")
        circuit.display();
    return 0;
}

int run(nts::Circuit &circuit)
{
    std::string input;

    printf("> ");
    while(getline(std::cin, input)) {
        if (analyseCommand(circuit, input) == 1)
            return 0;
        printf("> ");
    }
    return 0;
}
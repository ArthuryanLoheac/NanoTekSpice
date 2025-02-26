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

static int loop(nts::Circuit &circuit)
{
    while (1) {
        circuit.simulate(1);
        circuit.display();
    }
    return 0;
}

static int simulateArgs(nts::Circuit &circuit, std::vector<std::string> parts)
{
    int ticks = 1;

    if (parts.size() > 1) {
        try {
            ticks = std::stoi(parts[1]);
        } catch (const std::exception &e) {
            std::cerr << "Invalid  number of ticks" << std::endl;
            return 0;
        }
    }
    circuit.simulate(ticks);
    return 0;
}

static int assignValue(nts::Circuit &circuit, std::vector<std::string> parts)
{
    std::vector<std::string> value = splitString(parts[0], "=");

    if (value.size() != 2)
        return 0;
    if (value[1] == "U")
        circuit.setValue(value[0], nts::Tristate::UNDEFINED);
    if (value[1] == "0")
        circuit.setValue(value[0], nts::Tristate::FALSE);
    if (value[1] == "1")
        circuit.setValue(value[0], nts::Tristate::TRUE);
    return 0;
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
    if (parts[0] == "simulate")
        return simulateArgs(circuit, parts);
    if (parts[0] == "loop")
        loop(circuit);
    if (parts.size() == 1)
        return assignValue(circuit, parts);
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
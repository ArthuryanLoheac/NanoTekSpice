/*
** EPITECH PROJECT, 2025
** Main.cpp
** File description:
** Main.cpp
*/

#include <iostream>
#include <vector>

#include "Circuit.hpp"
#include "Parsing.hpp"
#include "ComponentFactory.hpp"

#include "ComponentInput.hpp"

static int run(nts::Circuit &circuit)
{
    circuit.simulate(1);
    circuit.display();
    return 0;
}

static int init(std::vector<std::vector<std::string>> chipsets,
        std::vector<std::vector<std::string>> links)
{
    nts::Circuit circuit;
    nts::ComponentFactory factory;

    try {
        for (const auto &chipset : chipsets) {
            if (chipset.size() != 2)
                throw std::invalid_argument("Invalid chipset format");
            const std::string &type = chipset[0];
            const std::string &name = chipset[1];
            std::unique_ptr<nts::IComponent> comp = factory.createComponent(type);
            comp->setName(name);
            circuit.addComponent(std::move(comp));
        }
        for (const auto &link : links) {
            if (link.size() != 4)
                throw std::invalid_argument("Invalid link format");
            const std::string &comp1 = link[0];
            std::size_t pin1 = std::stoul(link[1]);
            const std::string &comp2 = link[2];
            std::size_t pin2 = std::stoul(link[3]);
            circuit.getComponent(comp1).setLink(pin1, circuit.getComponent(comp2), pin2);
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return run(circuit);
}

static int parse(const char *file)
{
    std::string content;
    std::vector<std::string> lines, withoutCommentary, chipsetsRaw, linksRaw;
    std::vector<std::vector<std::string>> chipsets, links;

    try {
        content = parseFile(file);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    lines = parseByLine(content);
    withoutCommentary = removeCommentary(lines);
    try {
        chipsetsRaw = getPartList(withoutCommentary, ".chipsets:", ".links:");
        linksRaw = getPartList(withoutCommentary, ".links:", ".chipsets:");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    chipsets = ParseBySpaces(chipsetsRaw);
    links = ParseBySpaces(linksRaw);
    return init(chipsets, links);
}

int main(int ac, char **av)
{
    if (ac != 2) {
       std::cerr << "Usage: ./nanotekspice [file.nts]" << std::endl;
       return 84;
    }
    return parse(av[1]);
}

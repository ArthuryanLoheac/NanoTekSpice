/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Component4081
*/

#include "Component4081.hpp"

nts::Component4081::Component4081(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
}
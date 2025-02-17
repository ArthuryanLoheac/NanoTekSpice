/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Component4071
*/

#include "Component4071.hpp"
#include "ComponentOr.hpp"

nts::Component4071::Component4071(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentOr>(""));
    _internComponents.push_back(std::make_shared<ComponentOr>(""));
    _internComponents.push_back(std::make_shared<ComponentOr>(""));
    _internComponents.push_back(std::make_shared<ComponentOr>(""));
}
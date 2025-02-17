/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Component4030
*/

#include "Component4030.hpp"

nts::Component4030::Component4030(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
}

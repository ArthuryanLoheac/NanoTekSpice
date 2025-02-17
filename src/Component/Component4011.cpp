/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Component4011
*/

#include "Component4011.hpp"

nts::Component4011::Component4011(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentNand>(""));
    _internComponents.push_back(std::make_shared<ComponentNand>(""));
    _internComponents.push_back(std::make_shared<ComponentNand>(""));
    _internComponents.push_back(std::make_shared<ComponentNand>(""));
}
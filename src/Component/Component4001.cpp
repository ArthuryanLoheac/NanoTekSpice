/*
** EPITECH PROJECT, 2025
** Component4001.cpp
** File description:
** Component4001.cpp
*/

#include "Component4001.hpp"
#include "ComponentNor.hpp"

nts::Component4001::Component4001(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentNor>(""));
    _internComponents.push_back(std::make_shared<ComponentNor>(""));
    _internComponents.push_back(std::make_shared<ComponentNor>(""));
    _internComponents.push_back(std::make_shared<ComponentNor>(""));
}

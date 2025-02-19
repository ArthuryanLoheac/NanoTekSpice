/*
** EPITECH PROJECT, 2025
** Component4030.cpp
** File description:
** Component4030.cpp
*/

#include "Component4030.hpp"
#include "ComponentXor.hpp"

nts::Component4030::Component4030(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
    _internComponents.push_back(std::make_shared<ComponentXor>(""));
}

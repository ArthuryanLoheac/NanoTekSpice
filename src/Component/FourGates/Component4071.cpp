/*
** EPITECH PROJECT, 2025
** Component4071.cpp
** File description:
** Component4071.cpp
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
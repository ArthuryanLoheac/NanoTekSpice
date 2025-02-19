/*
** EPITECH PROJECT, 2025
** Component4081.cpp
** File description:
** Component4081.cpp
*/

#include "Component4081.hpp"
#include "ComponentAnd.hpp"

nts::Component4081::Component4081(std::string name)
    : AFourGates(name)
{
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
    _internComponents.push_back(std::make_shared<ComponentAnd>(""));
}
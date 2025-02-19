/*
** EPITECH PROJECT, 2025
** AInput.cpp
** File description:
** AInput.cpp
*/

#include "AInput.hpp"

nts::AInput::AInput(std::string name) : AComponent(name)
{
    _inOuts.push_back(std::make_pair(OUT,
        std::vector<std::pair<IComponent &, std::size_t>>()));
    _ValueComputed = UNDEFINED;
}
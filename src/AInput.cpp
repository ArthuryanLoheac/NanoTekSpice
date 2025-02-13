/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AInput
*/

#include "AInput.hpp"

nts::AInput::AInput(std::string name) : AComponent(name)
{
    _inOuts.push_back(std::make_pair(OUT,
        std::vector<std::pair<IComponent &, std::size_t>>()));
    _internComponents = std::vector<IComponent>();
    _lastValueComputed = UNDEFINED;
}

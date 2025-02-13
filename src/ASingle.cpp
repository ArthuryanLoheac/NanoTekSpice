/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ASingle
*/

#include "ASingle.hpp"

static std::pair<nts::TypePin, std::vector<std::pair<nts::IComponent &,
    std::size_t>>> makePair(nts::TypePin type)
{
    return std::make_pair(type,
        std::vector<std::pair<nts::IComponent &, std::size_t>>());
}

nts::ASingle::ASingle(std::string name) : AComponent(name)
{
    _inOuts.push_back(makePair(IN));
    _inOuts.push_back(makePair(IN));
    _inOuts.push_back(makePair(OUT));
    _lastValueComputed = UNDEFINED;
}
/*
** EPITECH PROJECT, 2025
** AFourGates.cpp
** File description:
** AFourGates.cpp
*/

#include "AFourGates.hpp"

nts::Tristate nts::AFourGates::compute(std::size_t pin)
{
    return _internComponents[pin]->compute(0);
}

size_t nts::AFourGates::pinOutToInternPin(size_t pin)
{
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12)
        return 1;
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13)
        return 2;
    if (pin == 3 || pin == 7 || pin == 10 || pin == 14)
        return 3;
    return 0;
}

void nts::AFourGates::setNotComputed()
{
    _lastValueComputed = NOTCOMPUTED;
    for (const auto &composant : _internComponents)
        composant->setNotComputed();
}

size_t nts::AFourGates::getIdFromPin(size_t pin)
{
    if (pin == 3)
        return 0;
    if (pin == 4)
        return 1;
    if (pin == 10)
        return 2;
    if (pin == 11)
        return 3;
    return 0;
}

static std::pair<nts::TypePin, std::vector<std::pair<nts::IComponent &,
    std::size_t>>> makeEmptyPair(nts::TypePin type)
{
    return std::make_pair(type, std::vector<std::pair<nts::IComponent &, std::size_t>>());
}

nts::AFourGates::AFourGates(std::string name)
    : AComponent(name)
{
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
}

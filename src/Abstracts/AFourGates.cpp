/*
** EPITECH PROJECT, 2025
** AFourGates.cpp
** File description:
** AFourGates.cpp
*/

#include "AFourGates.hpp"

nts::Tristate nts::AFourGates::compute(std::size_t pin)
{
    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        _ValueComputed = _internComponents[pin]->compute(0);
    }
    return safeReturn(pin);
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
    _ValueComputed = NOTCOMPUTED;
    for (auto &composant : _internComponents)
        composant->setNotComputed();
}

size_t nts::AFourGates::getIdFromPin(size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 3)
        return 0;
    if (pin == 4 || pin == 5 || pin == 6)
        return 1;
    if (pin == 8 || pin == 9 || pin == 10)
        return 2;
    if (pin == 11 || pin == 12 || pin == 13)
        return 3;
    throw nts::AComponent::Errors("Pin is not an output");
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

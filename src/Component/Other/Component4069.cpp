/*
** EPITECH PROJECT, 2025
** Component4069.cpp
** File description:
** Component4069.cpp
*/

#include "Component4069.hpp"
#include "ComponentNot.hpp"

nts::Component4069::Component4069(std::string name)
    : AComponent(name)
{
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _internComponents.push_back(std::make_unique<ComponentNot>(""));
    _internComponents.push_back(std::make_unique<ComponentNot>(""));
    _internComponents.push_back(std::make_unique<ComponentNot>(""));
    _internComponents.push_back(std::make_unique<ComponentNot>(""));
    _internComponents.push_back(std::make_unique<ComponentNot>(""));
    _internComponents.push_back(std::make_unique<ComponentNot>(""));
}

nts::Tristate nts::Component4069::compute(std::size_t pin)
{
    _ValueComputed = _internComponents[pin]->compute(0);
    return safeReturn(pin);
}

size_t nts::Component4069::pinOutToInternPin(size_t pin)
{
    if (pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13)
        return 1;
    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
        return 2;
    return 0;
}

void nts::Component4069::setNotComputed()
{
    _ValueComputed = NOTCOMPUTED;
    for (auto &composant : _internComponents)
        composant->setNotComputed();
}

size_t nts::Component4069::getIdFromPin(size_t pin)
{
    if (pin == 1 || pin == 2)
        return 0;
    if (pin == 3 || pin == 4)
        return 1;
    if (pin == 5 || pin == 6)
        return 2;
    if (pin == 8 || pin == 9)
        return 3;
    if (pin == 10 || pin == 11)
        return 4;
    if (pin == 12 || pin == 13)
        return 5;
    throw nts::AComponent::Errors("Pin is not an output");
}

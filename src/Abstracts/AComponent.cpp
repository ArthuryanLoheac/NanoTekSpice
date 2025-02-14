/*
** EPITECH PROJECT, 2025
** AComponent.cpp
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"
#include <iostream>

void nts::AComponent::simulate(std::size_t tick)
{
    tick = tick;
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    pin = pin;
    _ValueComputed = UNDEFINED;
    return _ValueComputed;
}

void nts::AComponent::setLink(std::size_t pinOut, nts::IComponent &other,
                              std::size_t pinIn)
{
    if (_internComponents.size() > 0)
        setLink(pinOut, *_internComponents[getIdFromPin(pinOut)],
            _internComponents[getIdFromPin(pinOut)]->pinOutToInternPin(pinOut));
    if ((pinOut - 1) > _inOuts.size())
        throw nts::AComponent::Errors("PinOut is not a pin");
    if ((pinIn - 1) > other.getInOut().size())
        throw nts::AComponent::Errors("PinIn is is not a pin");
    if (_inOuts[pinOut - 1].first == IN && _inOuts[pinOut - 1].second.size() > 0)
        throw nts::AComponent::Errors("PinOut is already linked");
    if (other.getInOut()[pinIn - 1].first == IN && other.getInOut()[pinIn - 1].second.size() > 0)
        throw nts::AComponent::Errors("PinIn is already linked");
    _inOuts[pinOut - 1].second.push_back(
        std::make_pair(std::ref(other), pinIn));
    other.getInOut()[pinIn - 1].second.push_back(
        std::make_pair(std::ref(*this), pinOut));
}

size_t nts::AComponent::pinOutToInternPin(size_t pin)
{
    return pin;
}

void nts::AComponent::setNotComputed()
{
    _ValueComputed = NOTCOMPUTED;
}

size_t nts::AComponent::getIdFromPin(size_t pin)
{
    pin = pin;
    return 0;
}

std::vector<std::pair<nts::TypePin,
            std::vector<std::pair<nts::IComponent &,
            std::size_t>>>> &nts::AComponent::getInOut()
{
    return _inOuts;
}

std::string nts::AComponent::getName()
{
    return _name;
}

nts::Tristate nts::AComponent::getValueComputed()
{
   return _ValueComputed;
}

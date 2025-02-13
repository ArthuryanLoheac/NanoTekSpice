/*
** EPITECH PROJECT, 2025
** AComponent.cpp
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

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
    if (_internComponents.size() > 0) {
        setLink(pinOut, *_internComponents[getIdFromPin(pinOut)],
            _internComponents[getIdFromPin(pinOut)]->pinOutToInternPin(pinOut));
    }
    _inOuts[pinOut].second.push_back(std::make_pair(std::ref(other), pinIn));
    other.getInOut()[pinIn].second.push_back(std::make_pair(std::ref(*this), pinOut));
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
            std::size_t>>>> nts::AComponent::getInOut()
{
    return _inOuts;
}

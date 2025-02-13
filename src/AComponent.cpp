/*
** EPITECH PROJECT, 2025
** AComponent.cpp
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

nts::AComponent::~AComponent()
{
}

void nts::AComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    _lastValueComputed = UNDEFINED;
    return _lastValueComputed;
}

void nts::AComponent::setLink(std::size_t pinOut, nts::IComponent &other,
                              std::size_t pinIn)
{
    if (_internComponents.size() > 0) {
        setLink(pinOut, _internComponents[getIdFromPin(pinOut)],
            _internComponents[getIdFromPin(pinOut)].pinOutToInternPin(pinOut));
    }
    _inOuts[pinOut].second.push_back(std::make_pair(other, pinIn));
    other.getInOut()[pinIn].second.push_back(
        std::make_pair(dynamic_cast<IComponent &>(*this), pinOut));
}

size_t nts::AComponent::pinOutToInternPin(size_t pin)
{
    return pin;
}

void nts::AComponent::setNotComputed()
{
    _lastValueComputed = NOTCOMPUTED;
}

size_t nts::AComponent::getIdFromPin(size_t pin)
{
    return 0;
}

std::vector<std::pair<nts::TypePin,
            std::vector<std::pair<nts::IComponent,
            std::size_t>>>> nts::AComponent::getInOut()
{
    return _inOuts;
}

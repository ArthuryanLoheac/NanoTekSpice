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

static void handlingErrorsLink(std::size_t pinOut, nts::IComponent &other,
                              std::size_t pinIn, nts::IComponent &my)
{
    if ((pinOut - 1) > my.getInOut().size())
        throw nts::AComponent::Errors("PinOut is out of bound");
    if ((pinIn - 1) > other.getInOut().size())
        throw nts::AComponent::Errors("PinIn is out of bound");
    if (my.getInOut()[pinOut - 1].first == nts::IN &&
        my.getInOut()[pinOut - 1].second.size() > 0)
        throw nts::AComponent::Errors("PinOut is already linked");
    if (other.getInOut()[pinIn - 1].first == nts::IN &&
        other.getInOut()[pinIn - 1].second.size() > 0)
        throw nts::AComponent::Errors("PinIn is already linked");
}

void nts::AComponent::setLink(std::size_t pinOut, nts::IComponent &other,
                              std::size_t pinIn)
{
    if (_internComponents.size() > 0){
        _internComponents[getIdFromPin(pinOut)]->setLink(
            pinOutToInternPin(pinOut), other,
            _internComponents[getIdFromPin(pinOut)]->pinOutToInternPin(pinIn));
        return;
    }
    if (other.getInternComponents().size() > 0){
        other.getInternComponents()[other.getIdFromPin(pinIn)]->setLink(
            other.pinOutToInternPin(pinIn), *this, other.getInternComponents()
                [other.getIdFromPin(pinIn)]->pinOutToInternPin(pinOut));
        return;
    }
    handlingErrorsLink(pinOut, other, pinIn, *this);
    _inOuts[pinOut - 1].second.push_back(
        std::make_pair(std::ref(other), other.getIdFromPin(pinIn)));
    other.getInOut()[pinIn - 1].second.push_back(
        std::make_pair(std::ref(*this), other.getIdFromPin(pinOut)));
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

nts::Tristate nts::AComponent::safeReturn(std::size_t pin)
{
    if (_ValueComputed == nts::COMPUTING)
        return _lastValue[pin];
    _lastValue[pin] = _ValueComputed;
    return _ValueComputed;
}

std::vector<std::shared_ptr<nts::IComponent>> &nts::AComponent::getInternComponents()
{
    return _internComponents;
}

nts::AComponent::AComponent(std::string name)
    : _name(name)
{
    for (size_t i = 0; i < 100; i++) {
        _lastValue[i] = UNDEFINED;
    }
};
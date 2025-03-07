/*
** EPITECH PROJECT, 2025
** ComponentClock.cpp
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"

nts::ComponentClock::ComponentClock(std::string name)
    : AInput(name)
{
    _value = nts::UNDEFINED;
    _valueComputed = nts::UNDEFINED;
}

nts::ComponentClock::~ComponentClock()
{
}

void nts::ComponentClock::simulate(std::size_t tick)
{
    for (size_t i = 0; i < tick; i++) {
        if (_value == nts::UNDEFINED)
           break;
        if (_value == nts::TRUE)
            _value = nts::FALSE;
        else
            _value = nts::TRUE;
    }
}

nts::Tristate nts::ComponentClock::compute(std::size_t pin)
{
    (void)pin;
    _valueComputed = _value;
    return _valueComputed;
}

void nts::ComponentClock::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate nts::ComponentClock::getValueComputed()
{
    return _valueComputed;
}

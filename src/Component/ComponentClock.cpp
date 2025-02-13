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
}

nts::ComponentClock::~ComponentClock()
{
}

void nts::ComponentClock::simulate(std::size_t tick)
{
    (void)tick;
    if (_value == nts::UNDEFINED)
        return;
    if (_value == nts::TRUE)
        _value = nts::FALSE;
    else
        _value = nts::TRUE;
}

nts::Tristate nts::ComponentClock::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

void nts::ComponentClock::setValue(nts::Tristate value)
{
    _value = value;
}

/*
** EPITECH PROJECT, 2025
** ComponentFalse.cpp
** File description:
** ComponentFalse.cpp
*/

#include "ComponentFalse.hpp"

nts::ComponentFalse::ComponentFalse(std::string name)
    : AInput(name)
{
}

nts::ComponentFalse::~ComponentFalse()
{
}

void nts::ComponentFalse::simulate(std::size_t tick)
{
    (void)tick;
    if (_value == UNDEFINED)
        _value = FALSE;
}

nts::Tristate nts::ComponentFalse::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

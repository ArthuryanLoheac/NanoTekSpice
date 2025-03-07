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
    _value = FALSE;
}

nts::ComponentFalse::~ComponentFalse()
{
}

void nts::ComponentFalse::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::ComponentFalse::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

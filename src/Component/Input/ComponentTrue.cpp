/*
** EPITECH PROJECT, 2025
** ComponentTrue.cpp
** File description:
** ComponentTrue.cpp
*/

#include "ComponentTrue.hpp"

nts::ComponentTrue::ComponentTrue(std::string name)
    : AInput(name)
{
    _value = TRUE;
}

nts::ComponentTrue::~ComponentTrue()
{
}

nts::Tristate nts::ComponentTrue::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

void nts::ComponentTrue::simulate(std::size_t tick)
{
    (void)tick;
}

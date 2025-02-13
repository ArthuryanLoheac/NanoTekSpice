/*
** EPITECH PROJECT, 2025
** ComponentInput.cpp
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput(std::string name)
    : AInput(name)
{
    _value = nts::UNDEFINED;
}

nts::ComponentInput::~ComponentInput()
{
}

nts::Tristate nts::ComponentInput::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

void nts::ComponentInput::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate nts::ComponentInput::getValueComputed()
{
    return _value;
}

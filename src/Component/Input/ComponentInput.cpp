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
    _valueComputed = nts::UNDEFINED;
}

nts::ComponentInput::~ComponentInput()
{
}

nts::Tristate nts::ComponentInput::compute(std::size_t pin)
{
    (void)pin;
    _valueComputed = _value;
    return _valueComputed;
}

void nts::ComponentInput::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate nts::ComponentInput::getValueComputed()
{
    return _valueComputed;
}

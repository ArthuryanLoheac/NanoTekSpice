/*
** EPITECH PROJECT, 2025
** ComponentNor.cpp
** File description:
** ComponentNor.cpp
*/

#include "ComponentNor.hpp"

nts::ComponentNor::ComponentNor(std::string name)
    : ASingle(name)
{
}

static nts::Tristate norTristate(nts::Tristate val1, nts::Tristate val2)
{
    if (val1 == nts::TRUE || val2 == nts::TRUE)
        return nts::FALSE;
    if (val1 == nts::UNDEFINED || val2 == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}

nts::Tristate nts::ComponentNor::compute(std::size_t pin)
{
    nts::Tristate val1;
    nts::Tristate val2;

    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        val1 = getVal(0);
        val2 = getVal(1);
        _ValueComputed = norTristate(val1, val2);
    }
    return safeReturn(pin);
}

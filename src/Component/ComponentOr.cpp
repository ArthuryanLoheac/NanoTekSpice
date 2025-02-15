/*
** EPITECH PROJECT, 2025
** ComponentOr.cpp
** File description:
** ComponentOr.cpp
*/

#include "ComponentOr.hpp"

nts::ComponentOr::ComponentOr(std::string name)
    : ASingle(name)
{
}

static nts::Tristate orTristate(nts::Tristate val1, nts::Tristate val2)
{
    if (val1 == nts::TRUE || val2 == nts::TRUE)
        return nts::TRUE;
    if (val1 == nts::UNDEFINED || val2 == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::FALSE;
}

nts::Tristate nts::ComponentOr::compute(std::size_t pin)
{
    nts::Tristate val1;
    nts::Tristate val2;

    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        val1 = getVal(0);
        val2 = getVal(1);
        _ValueComputed = orTristate(val1, val2);
    }
    return safeReturn(pin);
}

/*
** EPITECH PROJECT, 2025
** ComponentAnd.cpp
** File description:
** ComponentAnd.cpp
*/

#include "ComponentAnd.hpp"

nts::ComponentAnd::ComponentAnd(std::string name)
    : ASingle(name)
{
}

static nts::Tristate andTristate(nts::Tristate val1, nts::Tristate val2)
{
    if (val1 == nts::FALSE || val2 == nts::FALSE)
        return nts::FALSE;
    if (val1 == nts::UNDEFINED || val2 == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}

nts::Tristate nts::ComponentAnd::compute(std::size_t pin)
{
    nts::Tristate val1;
    nts::Tristate val2;

    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        val1 = getVal(0);
        val2 = getVal(1);
        _ValueComputed = andTristate(val1, val2);
    }
    return safeReturn(pin);
}

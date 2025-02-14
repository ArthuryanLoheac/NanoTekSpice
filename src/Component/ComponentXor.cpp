/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ComponentXor
*/

#include "ComponentXor.hpp"

nts::ComponentXor::ComponentXor(std::string name)
    : ASingle(name)
{
}

static nts::Tristate xorTristate(nts::Tristate val1, nts::Tristate val2)
{
    if (val1 == nts::UNDEFINED || val2 == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (val1 == val2)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate nts::ComponentXor::compute(std::size_t pin)
{
    nts::Tristate val1;
    nts::Tristate val2;

    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        val1 = getVal(0, _inOuts);
        val2 = getVal(1, _inOuts);
        _ValueComputed = xorTristate(val1, val2);
    }
    return safeReturn(pin);
}

/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ComponentNand
*/

#include "ComponentNand.hpp"

nts::ComponentNand::ComponentNand(std::string name)
    : ASingle(name)
{
}

static nts::Tristate andTristate(nts::Tristate val1, nts::Tristate val2)
{
    if (val1 == nts::FALSE || val2 == nts::FALSE)
        return nts::TRUE;
    if (val1 == nts::UNDEFINED || val2 == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::FALSE;
}

nts::Tristate nts::ComponentNand::compute(std::size_t pin)
{
    nts::Tristate val1;
    nts::Tristate val2;

    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        val1 = getVal(0, _inOuts);
        val2 = getVal(1, _inOuts);
        _ValueComputed = andTristate(val1, val2);
    }
    return safeReturn(pin);
}

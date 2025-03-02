/*
** EPITECH PROJECT, 2025
** ComponentCo.cpp
** File description:
** ComponentCo.cpp
*/

#include "ComponentCo.hpp"

nts::ComponentCo::ComponentCo(std::string name)
    : AComponent(name)
{
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
}

static nts::Tristate coTristate(nts::Tristate val1, nts::Tristate val2, nts::Tristate val3)
{
    int i = 0;

    if (val1 == nts::UNDEFINED || val2 == nts::UNDEFINED || val3 == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (val1 == nts::TRUE)
        i++;
    if (val2 == nts::TRUE)
        i++;
    if (val3 == nts::TRUE)
        i++;
    if (i == 0 || i == 1)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate nts::ComponentCo::getVal(int i)
{
    if (_inOuts[i].second.size() == 0)
        _lastValue[i] = nts::UNDEFINED;
    else{
        _lastValue[i] =  _inOuts[i].second[0].first.compute(i);
    }
    return _lastValue[i];
}

nts::Tristate nts::ComponentCo::compute(std::size_t pin)
{
    nts::Tristate val1, val2, val3;

    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        val1 = getVal(0);
        val2 = getVal(1);
        val3 = getVal(2);
        _ValueComputed = coTristate(val1, val2, val3);
    }
    return safeReturn(pin);
}

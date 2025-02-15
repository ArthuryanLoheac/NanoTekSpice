/*
** EPITECH PROJECT, 2025
** ComponentNot.cpp
** File description:
** ComponentNot.cpp
*/

#include "ComponentNot.hpp"

nts::ComponentNot::ComponentNot(std::string name)
    : AComponent(name)
{
    _inOuts.push_back(std::make_pair(IN, std::vector<std::pair<IComponent &, std::size_t>>()));
    _inOuts.push_back(std::make_pair(OUT, std::vector<std::pair<IComponent &, std::size_t>>()));
    _lastValue[0] = UNDEFINED;
    _ValueComputed = UNDEFINED;
}

nts::ComponentNot::~ComponentNot() {}

nts::Tristate notTristate(nts::Tristate val)
{
    if (val == nts::UNDEFINED)
        return nts::UNDEFINED;
    return (val == nts::TRUE) ? nts::FALSE : nts::TRUE;
}

nts::Tristate nts::ComponentNot::compute(std::size_t pin)
{
    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        if (_inOuts[0].second.size() == 0) {
            _ValueComputed = UNDEFINED;
        } else {
            _ValueComputed = notTristate(_inOuts[0].second[0].first.compute(_inOuts[0].second[0].second));
        }
    }
    return safeReturn(pin);
}

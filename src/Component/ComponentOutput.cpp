/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ComponentOutput
*/

#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput(std::string name) : AComponent(name)
{
    _inOuts.push_back(std::make_pair(IN,
        std::vector<std::pair<IComponent &, std::size_t>>()));
    _lastValue[0] = UNDEFINED;
    _ValueComputed = UNDEFINED;
}

nts::ComponentOutput::~ComponentOutput() {}

nts::Tristate nts::ComponentOutput::compute(std::size_t pin)
{;
    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        if (_inOuts[0].second.size() == 0)
            _ValueComputed = UNDEFINED;
        else
            _ValueComputed = _inOuts[0].second[0].first.compute(_inOuts[0].second[0].second);
    }
    _lastValue[pin] = _ValueComputed;
    return _ValueComputed;
}

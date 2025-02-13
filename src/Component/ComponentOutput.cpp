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
}

nts::ComponentOutput::~ComponentOutput() {}

nts::Tristate nts::ComponentOutput::compute(std::size_t pin)
{
    (void)pin;
    if (_lastValueComputed == NOTCOMPUTED) {
        if (_inOuts[0].second.size() == 0)
            _lastValueComputed = UNDEFINED;
        else
            _lastValueComputed = _inOuts[0].second[0].first.compute(_inOuts[0].second[0].second);
    }
    return _lastValueComputed;
}

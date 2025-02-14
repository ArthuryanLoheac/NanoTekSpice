/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ASingle
*/

#include "ASingle.hpp"

static std::pair<nts::TypePin, std::vector<std::pair<nts::IComponent &,
    std::size_t>>> makePair(nts::TypePin type)
{
    return std::make_pair(type,
        std::vector<std::pair<nts::IComponent &, std::size_t>>());
}

nts::ASingle::ASingle(std::string name) : AComponent(name)
{
    _inOuts.push_back(makePair(IN));
    _inOuts.push_back(makePair(IN));
    _inOuts.push_back(makePair(OUT));
    _ValueComputed = UNDEFINED;
    _lastValue[0] = UNDEFINED;
}

nts::Tristate nts::ASingle::getVal(int i, std::vector<std::pair<
nts::TypePin, std::vector<std::pair<nts::IComponent &, std::size_t>>>> _inOuts)
{
    if (_inOuts[i].second.size() == 0) 
        _ValueComputed = nts::UNDEFINED;
    else{
        _ValueComputed =  _inOuts[i].second[0].first.compute(_inOuts[i].second[0].second);
    }
    return _ValueComputed;
}

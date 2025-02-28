/*
** EPITECH PROJECT, 2025
** ComponentSum.cpp
** File description:
** ComponentSum.cpp
*/

#include "ComponentSum.hpp"
#include "ComponentSum_l.hpp"
#include "ComponentCo.hpp"

nts::ComponentSum::ComponentSum(std::string name)
    : AComponent("Add")
{
    static int i = -1;
    static int j = 0;
    i += 2;
    j += 2;
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _internComponents.push_back(std::make_shared<ComponentCo>(std::to_string(i)));
    _internComponents.push_back(std::make_shared<ComponentSum_l>(std::to_string(j)));
}

nts::Tristate nts::ComponentSum::getVal(int i)
{
    if (_inOuts[i].second.size() == 0)
        _lastValue[i] = nts::UNDEFINED;
    else{
        _lastValue[i] = _inOuts[i].second[0].first.compute(i);
    }
    return _lastValue[i];
}

nts::Tristate nts::ComponentSum::compute(std::size_t pin)
{
    if (pin == 0)
        return _internComponents[0]->compute(0);
    if (pin == 1)
        return _internComponents[1]->compute(0);
    return nts::UNDEFINED;
}

size_t nts::ComponentSum::pinOutToInternPin(size_t pin)
{
    if (pin == 5 || pin == 4)
        return 4;
    if (pin < 4)
        return pin;
    return 0;
}

size_t nts::ComponentSum::getIdFromPin(size_t pin)
{
    if (pin == 4)
        return 0;
    if (pin == 5)
        return 1;
    return 0;
}

void nts::ComponentSum::setNotComputed()
{
    _ValueComputed = NOTCOMPUTED;
    for (auto &composant : _internComponents)
        composant->setNotComputed();
}

void nts::ComponentSum::setLink(std::size_t pinOut, IComponent &other, std::size_t pinIn)
{
    if (_internComponents.size() > 0 && pinOut < 4) {
        //Force set link to both internal components
        _internComponents[0]->setLink(
            pinOutToInternPin(pinOut), other,
            _internComponents[0]->pinOutToInternPin(pinIn));
        _internComponents[1]->setLink(
            pinOutToInternPin(pinOut), other,
            _internComponents[1]->pinOutToInternPin(pinIn));
        return;
    } else if (_internComponents.size() > 0 && pinOut == 4) {
        _internComponents[0]->setLink(
            pinOutToInternPin(pinOut), other,
            _internComponents[0]->pinOutToInternPin(pinIn));
        return;
    } else if (_internComponents.size() > 0 && pinOut == 5) {
        _internComponents[1]->setLink(
            pinOutToInternPin(pinOut), other,
            _internComponents[1]->pinOutToInternPin(pinIn));
        return;
    }
    if (other.getInternComponents().size() > 0){
        other.getInternComponents()[other.getIdFromPin(pinIn)]->setLink(
            other.pinOutToInternPin(pinIn), *this, other.getInternComponents()
                [other.getIdFromPin(pinIn)]->pinOutToInternPin(pinOut));
        return;
    }
    handlingErrorsLink(pinOut, other, pinIn, *this);
    _inOuts[pinOut - 1].second.push_back(
        std::make_pair(std::ref(other), other.getIdFromPin(pinIn)));
    other.getInOut()[pinIn - 1].second.push_back(
        std::make_pair(std::ref(*this), other.getIdFromPin(pinOut)));
}

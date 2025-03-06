/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Composant4040
*/

#include "Component4040.hpp"

nts::Component4040::Component4040(std::string name)
    : AComponent(name), compteur(0),
    lastClock1(nts::UNDEFINED)
{
    for (int i = 0; i < 7; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    for (int i = 0; i < 2; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::IN));
    for (int i = 0; i < 4; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
}

void nts::Component4040::simulate(std::size_t tick)
{
    updated = tick;
}

static void addMax4095(size_t &compteur)
{
    compteur++;
    if (compteur > 4095)
        compteur = 0;
}

void nts::Component4040::updateCompteur(nts::Tristate reset, nts::Tristate clock1)
{
    if (lastClock1 == TRUE && clock1 == FALSE)
        addMax4095(compteur);
    if (reset == nts::TRUE)
        compteur = 0;
    lastClock1 = clock1;
    updated--;
}

static nts::Tristate isActive(size_t compteur, size_t i)
{
    if (compteur & (1 << i))
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate nts::Component4040::compute(std::size_t pin)
{
    nts::Tristate clock1 = getVal(10);
    nts::Tristate reset = getVal(11);
    
    if (clock1 == nts::UNDEFINED || reset == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (updated > 0)
        updateCompteur(reset, clock1);
    switch (pin) {
        case 9:  _ValueComputed = isActive(compteur, 0);
            break;
        case 7:  _ValueComputed = isActive(compteur, 1);
            break;
        case 6:  _ValueComputed = isActive(compteur, 2);
            break;
        case 5:  _ValueComputed = isActive(compteur, 3);
            break;
        case 3:  _ValueComputed = isActive(compteur, 4);
            break;
        case 2:  _ValueComputed = isActive(compteur, 5);
            break;
        case 4:  _ValueComputed = isActive(compteur, 6);
            break;
        case 13: _ValueComputed = isActive(compteur, 7);
            break;
        case 12: _ValueComputed = isActive(compteur, 8);
            break;
        case 14: _ValueComputed = isActive(compteur, 9);
            break;
        case 15: _ValueComputed = isActive(compteur, 10);
            break;
        case 1:  _ValueComputed = isActive(compteur, 11); // Q12 - Bit 11
            break;
        default: _ValueComputed = nts::UNDEFINED;
    }
    return _ValueComputed;
}

size_t nts::Component4040::pinOutToInternPin(size_t pin)
{
    if (pin <= 16)
        return pin;
    return 0;
}

size_t nts::Component4040::getIdFromPin(size_t pin)
{
    if (pin <= 16)
        return pin;
    throw nts::AComponent::Errors("Pin is not an output : " + std::to_string(pin));
}

nts::Tristate nts::Component4040::getVal(int i)
{
    if (_inOuts[i].second.size() == 0)
        _lastValue[i] = nts::UNDEFINED;
    else{
        _lastValue[i] =  _inOuts[i].second[0].first.compute(i);
    }
    return _lastValue[i];
}

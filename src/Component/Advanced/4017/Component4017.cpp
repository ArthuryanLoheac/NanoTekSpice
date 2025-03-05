/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Composant4017
*/

#include "Component4017.hpp"

nts::Component4017::Component4017(std::string name)
    : AComponent(name), compteur(0),
    lastClock1(nts::UNDEFINED), lastClock2(nts::UNDEFINED)
{
    for (int i = 0; i < 12; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    for (int i = 0; i < 3; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::IN));
}

void nts::Component4017::simulate(std::size_t tick)
{
    updated = tick;
}

static void addMax10(size_t &compteur)
{
    compteur++;
    if (compteur == 10)
        compteur = 0;
}

void nts::Component4017::updateCompteur(nts::Tristate reset, nts::Tristate clock1, nts::Tristate clock2)
{
    if ((lastClock1 == FALSE || lastClock1 == UNDEFINED)
        && clock1 == TRUE && (clock2 == FALSE || clock2 == UNDEFINED))
        addMax10(compteur);
    else if (lastClock2 == TRUE && (clock2 == FALSE || clock2 == UNDEFINED) && clock1 == TRUE)
        addMax10(compteur);
    if (reset == nts::TRUE)
        compteur = 0;
    lastClock1 = clock1;
    lastClock2 = clock2;
    updated--;
}

static nts::Tristate isActive(size_t compteur, size_t i)
{
    if (compteur == i)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate nts::Component4017::compute(std::size_t pin)
{
    nts::Tristate clock2 = getVal(12);
    nts::Tristate clock1 = getVal(13);
    nts::Tristate reset = getVal(14);
    
    if (clock1 == nts::UNDEFINED || clock2 == nts::UNDEFINED || reset == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (updated > 0)
        updateCompteur(reset, clock1, clock2);
    switch (pin) {
        case 3: _ValueComputed = isActive(compteur, 0);
            break;
        case 2: _ValueComputed = isActive(compteur, 1);
            break;
        case 4: _ValueComputed = isActive(compteur, 2);
            break;
        case 7: _ValueComputed = isActive(compteur, 3);
            break;
        case 10: _ValueComputed = isActive(compteur, 4);
            break;
        case 1: _ValueComputed = isActive(compteur, 5);
            break;
        case 5: _ValueComputed = isActive(compteur, 6);
            break;
        case 6: _ValueComputed = isActive(compteur, 7);
            break;
        case 9: _ValueComputed = isActive(compteur, 8);
            break;
        case 11: _ValueComputed = isActive(compteur, 9);
            break;
        case 12: _ValueComputed = (compteur < 5) ? nts::TRUE : nts::FALSE;
            break;
        default: _ValueComputed = nts::UNDEFINED;
    }
    return _ValueComputed;
}

size_t nts::Component4017::pinOutToInternPin(size_t pin)
{
    if (pin <= 15)
        return pin;
    return 0;
}

size_t nts::Component4017::getIdFromPin(size_t pin)
{
    if (pin <= 15)
        return pin;
    throw nts::AComponent::Errors("Pin is not an output : " + std::to_string(pin));
}

nts::Tristate nts::Component4017::getVal(int i)
{
    if (_inOuts[i].second.size() == 0)
        _lastValue[i] = nts::UNDEFINED;
    else{
        _lastValue[i] =  _inOuts[i].second[0].first.compute(i);
    }
    return _lastValue[i];
}

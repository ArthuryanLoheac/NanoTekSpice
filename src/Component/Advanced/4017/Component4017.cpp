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

void nts::Component4017::updateCompteur(nts::Tristate reset)
{
    nts::Tristate clock1;
    nts::Tristate clock2;

    clock1 = getVal(12);
    clock2 = getVal(13);
    if ((lastClock1 == nts::FALSE && clock1 == nts::TRUE && clock2 == nts::FALSE) ||
        (lastClock2 == nts::TRUE && clock2 == nts::FALSE && clock1 == nts::TRUE)) {
        compteur++;
        if (compteur == 10)
            compteur = 0;
    }
    if (reset == nts::TRUE)
        compteur = 0;
    lastClock1 = clock1;
    lastClock2 = clock2;
}

static nts::Tristate isActive(size_t compteur, size_t i)
{
    if (compteur == i)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate nts::Component4017::compute(std::size_t pin)
{
    if (_ValueComputed == NOTCOMPUTED) {
        _ValueComputed = COMPUTING;
        updateCompteur(getVal(14));
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
    }
    return safeReturn(pin);
}

size_t nts::Component4017::pinOutToInternPin(size_t pin)
{
    if (pin <= 12)
        return pin;
    return 0;
}

size_t nts::Component4017::getIdFromPin(size_t pin)
{
    if (pin <= 12)
        return 0;
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

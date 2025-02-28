/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Composant4008
*/

#include "Component4008.hpp"

nts::Component4008::Component4008(std::string name)
    : AComponent(name)
{
    _internComponents.push_back(std::make_shared<ComponentSum>(""));
    _internComponents.push_back(std::make_shared<ComponentSum>(""));
    _internComponents.push_back(std::make_shared<ComponentSum>(""));
    _internComponents.push_back(std::make_shared<ComponentSum>(""));
    for (int i = 0; i < 7; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    for (int i = 0; i < 5; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _internComponents[0]->setLink(4, *_internComponents[1], 1);
    _internComponents[1]->setLink(4, *_internComponents[2], 1);
    _internComponents[2]->setLink(4, *_internComponents[3], 1);
}

nts::Tristate nts::Component4008::compute(std::size_t pin)
{
    printf("compute %d\n", pin);
    return nts::FALSE;
}

size_t nts::Component4008::pinOutToInternPin(size_t pin)
{
    if (pin == 9)
        return 1;
    if (pin == 1 || pin == 3 || pin == 5 || pin == 7)
        return 2;
    if (pin == 15 || pin == 2 || pin == 4 || pin == 6)
        return 3;
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13)
        return 4;
    if (pin == 14)
        return 5;
    return 0;
}

size_t nts::Component4008::getIdFromPin(size_t pin)
{
    if (pin == 10)
        return 0;
    if (pin == 11)
        return 1;
    if (pin == 12)
        return 2;
    if (pin == 13 || pin == 14)
        return 3;
    return 0;
}

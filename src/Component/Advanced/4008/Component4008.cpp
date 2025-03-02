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
    _internComponents.push_back(std::make_shared<ComponentSum>("A"));
    _internComponents.push_back(std::make_shared<ComponentSum>("B"));
    _internComponents.push_back(std::make_shared<ComponentSum>("C"));
    _internComponents.push_back(std::make_shared<ComponentSum>("D"));
    for (int i = 0; i < 7; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    for (int i = 0; i < 5; i++)
        _inOuts.push_back(makeEmptyPair(TypePin::OUT));
    _inOuts.push_back(makeEmptyPair(TypePin::IN));
    _inOuts.push_back(makeEmptyPair(TypePin::USELESS));
    _internComponents[0]->setLink(4, *_internComponents[1].get()->getInternComponents()[0], 1);
    _internComponents[0]->setLink(4, *_internComponents[1].get()->getInternComponents()[1], 1);
    _internComponents[1]->setLink(4, *_internComponents[2].get()->getInternComponents()[0], 1);
    _internComponents[1]->setLink(4, *_internComponents[2].get()->getInternComponents()[1], 1);
    _internComponents[2]->setLink(4, *_internComponents[3].get()->getInternComponents()[0], 1);
    _internComponents[2]->setLink(4, *_internComponents[3].get()->getInternComponents()[1], 1);
}

nts::Tristate nts::Component4008::compute(std::size_t pin)
{
    return _internComponents[pin]->compute(pin);
}

size_t nts::Component4008::pinOutToInternPin(size_t pin)
{
    if (pin == 9)
        return 1;
    if (pin == 7 || pin == 5 || pin == 3 || pin == 1)
        return 2;
    if (pin == 6 || pin == 4 || pin == 2 || pin == 15)
        return 3;
    if (pin == 14)
        return 4;
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13)
        return 5;
    return 0;
}

size_t nts::Component4008::getIdFromPin(size_t pin)
{
    if (pin == 9 || pin == 7 || pin == 6 || pin == 10)
        return 0;
    if (pin == 4 || pin == 5 || pin == 11)
        return 1;
    if (pin == 2 || pin == 3 || pin == 12)
        return 2;
    if (pin == 1 || pin == 15 || pin == 13 || pin == 14)
        return 3;
    throw nts::AComponent::Errors("Pin is not an output : " + std::to_string(pin));
}

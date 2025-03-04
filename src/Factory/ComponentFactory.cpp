/*
** EPITECH PROJECT, 2025
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include <stdexcept>

#include "ComponentFactory.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentClock.hpp"
#include "ComponentAnd.hpp"
#include "ComponentOr.hpp"
#include "ComponentXor.hpp"
#include "ComponentNot.hpp"
#include "Component4001.hpp"
#include "Component4011.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4008.hpp"
#include "Component4017.hpp"

nts::ComponentFactory::ComponentFactory()
{
    _factoryMap = {
        {"input", []() { return std::make_unique<nts::ComponentInput>("input"); }},
        {"output", []() { return std::make_unique<nts::ComponentOutput>("output"); }},
        {"true", []() { return std::make_unique<nts::ComponentTrue>("true"); }},
        {"false", []() { return std::make_unique<nts::ComponentFalse>("false"); }},
        {"clock", []() { return std::make_unique<nts::ComponentClock>("clock"); }},
        {"and", []() { return std::make_unique<nts::ComponentAnd>("and"); }},
        {"or", []() { return std::make_unique<nts::ComponentOr>("or"); }},
        {"xor", []() { return std::make_unique<nts::ComponentXor>("xor"); }},
        {"not", []() { return std::make_unique<nts::ComponentNot>("not"); }},
        {"4001", []() { return std::make_unique<nts::Component4001>("4001"); }},
        {"4011", []() { return std::make_unique<nts::Component4011>("4011"); }},
        {"4030", []() { return std::make_unique<nts::Component4030>("4030"); }},
        {"4069", []() { return std::make_unique<nts::Component4069>("4069"); }},
        {"4071", []() { return std::make_unique<nts::Component4071>("4071"); }},
        {"4081", []() { return std::make_unique<nts::Component4081>("4081"); }},
        {"4008", []() { return std::make_unique<nts::Component4008>("4008"); }},
        {"4017", []() { return std::make_unique<nts::Component4017>("4017"); }}
    };<
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type)
{
    auto it = _factoryMap.find(type);
    if (it == _factoryMap.end())
        throw std::invalid_argument("Invalid chipset type");
    return it->second();
}

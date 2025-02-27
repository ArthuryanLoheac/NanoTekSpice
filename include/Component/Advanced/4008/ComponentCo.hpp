/*
** EPITECH PROJECT, 2025
** ComponentCo.hpp
** File description:
** ComponentCo.hpp
*/
#pragma once

#include "AComponent.hpp"

namespace nts
{
    class ComponentCo : public AComponent
    {
    public:
        ComponentCo(std::string name);
        Tristate compute(std::size_t pin) override;
        Tristate getVal(int i);
    };
}


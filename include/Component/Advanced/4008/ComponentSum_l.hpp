/*
** EPITECH PROJECT, 2025
** ComponentSum_l.hpp
** File description:
** ComponentSum_l.hpp
*/
#pragma once

#include "AComponent.hpp"

namespace nts
{
    class ComponentSum_l : public AComponent
    {
    public:
        ComponentSum_l(std::string name);
        Tristate compute(std::size_t pin) override;
        Tristate getVal(int i);
    };
}


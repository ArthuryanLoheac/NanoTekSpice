/*
** EPITECH PROJECT, 2025
** ComponentSum.hpp
** File description:
** ComponentSum.hpp
*/
#pragma once

#include "AComponent.hpp"

namespace nts
{
    class ComponentSum : public AComponent
    {
    public:
        ComponentSum(std::string name);
        Tristate compute(std::size_t pin) override;
        Tristate getVal(int i);
        size_t pinOutToInternPin(size_t pin);
        size_t getIdFromPin(size_t pin);
        void setNotComputed() override;
        void setLink(std::size_t pinOut, IComponent &other, std::size_t pinIn) override;
    };
}


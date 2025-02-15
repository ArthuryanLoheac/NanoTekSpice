/*
** EPITECH PROJECT, 2025
** ComponentOr.hpp
** File description:
** ComponentOr.hpp
*/

#ifndef COMPONENT_OR_HPP
#define COMPONENT_OR_HPP

#include "ASingle.hpp"

namespace nts
{
    class ComponentOr : public ASingle
    {
    public:
        ComponentOr(std::string name);
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_OR_HPP */

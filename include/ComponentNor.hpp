/*
** EPITECH PROJECT, 2025
** ComponentNor.hpp
** File description:
** ComponentNor.hpp
*/

#ifndef COMPONENT_NOR_HPP
#define COMPONENT_NOR_HPP

#include "ASingle.hpp"

namespace nts
{
    class ComponentNor : public ASingle
    {
    public:
        ComponentNor(std::string name);
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_NOR_HPP */

/*
** EPITECH PROJECT, 2025
** ComponentXor.hpp
** File description:
** ComponentXor.hpp
*/

#ifndef COMPONENT_XOR_HPP
#define COMPONENT_XOR_HPP

#include "ASingle.hpp"

namespace nts
{
    class ComponentXor : public ASingle
    {
    public:
        ComponentXor(std::string name);
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_XOR_HPP */

/*
** EPITECH PROJECT, 2025
** ComponentAnd.hpp
** File description:
** ComponentAnd.hpp
*/

#ifndef COMPONENT_TRUE_HPP
#define COMPONENT_TRUE_HPP

#include "ASingle.hpp"

namespace nts
{
    class ComponentAnd : public ASingle
    {
    public:
        ComponentAnd(std::string name);
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_TRUE_HPP */

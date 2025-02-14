/*
** EPITECH PROJECT, 2025
** ComponentNand.hpp
** File description:
** ComponentNand.hpp
*/

#ifndef COMPONENT_NAND_HPP
#define COMPONENT_NAND_HPP

#include "ASingle.hpp"

namespace nts
{
    class ComponentNand : public ASingle
    {
    public:
        ComponentNand(std::string name);
        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_NAND_HPP */

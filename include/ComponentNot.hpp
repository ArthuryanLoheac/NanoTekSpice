/*
** EPITECH PROJECT, 2025
** ComponentNot.hpp
** File description:
** ComponentNot.hpp
*/

#ifndef COMPONENT_NOT_HPP
#define COMPONENT_NOT_HPP

#include "AComponent.hpp"

namespace nts
{
    class ComponentNot : public AComponent
    {
    public:
        ComponentNot(std::string name);
        ~ComponentNot();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_NOT_HPP */

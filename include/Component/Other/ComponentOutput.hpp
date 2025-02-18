/*
** EPITECH PROJECT, 2025
** ComponentOutput.hpp
** File description:
** ComponentOutPut.hpp
*/

#ifndef COMPONENT_OUTPUT_HPP
#define COMPONENT_OUTPUT_HPP

#include "AComponent.hpp"

namespace nts
{
    class ComponentOutput : public AComponent
    {
    public:
        ComponentOutput(std::string name);
        ~ComponentOutput();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_OUTPUT_HPP */

/*
** EPITECH PROJECT, 2025
** ComponentInput.hpp
** File description:
** ComponentInput.hpp
*/

#ifndef COMPONENT_INPUT_HPP
#define COMPONENT_INPUT_HPP

#include "AInput.hpp"

namespace nts
{
    class ComponentInput : public AInput
    {
    public:
        ComponentInput(std::string name);
        ~ComponentInput();
        nts::Tristate compute(std::size_t pin) override;
        void setValue(nts::Tristate value);
        nts::Tristate getValueComputed() override;

    private:
        Tristate _value;
    };
}

#endif /* !COMPONENT_INPUT_HPP */

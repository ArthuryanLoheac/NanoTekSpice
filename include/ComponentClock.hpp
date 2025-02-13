/*
** EPITECH PROJECT, 2025
** ComponentClock.hpp
** File description:
** ComponentClock.hpp
*/

#ifndef COMPONENT_CLOCK_HPP
#define COMPONENT_CLOCK_HPP

#include "AInput.hpp"

namespace nts
{
    class ComponentClock : public AInput
    {
    public:
        ComponentClock(std::string name);
        ~ComponentClock();
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setValue(nts::Tristate value);

    private:
        Tristate _value;
    };
}

#endif /* !COMPONENT_CLOCK_HPP */

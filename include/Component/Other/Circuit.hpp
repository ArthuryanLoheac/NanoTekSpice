/*
** EPITECH PROJECT, 2025
** Circuit.hpp
** File description:
** Circuit.hpp
*/

#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <iostream>
#include <algorithm>
#include <utility>

#include "AComponent.hpp"

namespace nts
{
    class Circuit : public AComponent
    {
    public:
        Circuit();
        void simulate(std::size_t tick);
        void simulate();
        nts::Tristate compute(std::size_t pin);
        void display(void);
        void setValue(std::string const &name, nts::Tristate value);
        void addComponent(std::unique_ptr<IComponent> component);
        IComponent &getComponent(std::string const &name);

    private:
        size_t _ticks_passed;
    };
}

#endif /* !CIRCUIT_HPP */

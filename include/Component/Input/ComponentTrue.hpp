/*
** EPITECH PROJECT, 2025
** ComponentTrue.hpp
** File description:
** ComponentTrue.hpp
*/

#ifndef COMPONENT_TRUE_HPP
#define COMPONENT_TRUE_HPP

#include "AInput.hpp"

namespace nts
{
    class ComponentTrue : public AInput
    {
        private:
            nts::Tristate _value = nts::UNDEFINED;
        public:
            ComponentTrue(std::string name);
            ~ComponentTrue();
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
    };
}

#endif /* !COMPONENT_TRUE_HPP */

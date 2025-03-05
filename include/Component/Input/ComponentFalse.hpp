/*
** EPITECH PROJECT, 2025
** ComponentFalse.hpp
** File description:
** ComponentFalse.hpp
*/

#ifndef COMPONENT_FALSE_HPP
#define COMPONENT_FALSE_HPP

#include "AInput.hpp"

namespace nts
{
    class ComponentFalse : public AInput
    {
        private:
            nts::Tristate _value = nts::UNDEFINED;
        public:
            ComponentFalse(std::string name);
            ~ComponentFalse();
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_FALSE_HPP */

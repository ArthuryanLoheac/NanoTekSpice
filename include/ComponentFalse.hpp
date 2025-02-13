/*
** EPITECH PROJECT, 2025
** ComponentFalse.hpp
** File description:
** ComponentFalse.hpp
*/

#ifndef COMPONENT_FALSE_HPP
#define COMPONENT_FALSE_HPP

#include "AInput.hpp"

namespace nts {
    class ComponentFalse : public AInput
    {
        public:
            ComponentFalse(std::string name);
            ~ComponentFalse();
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_FALSE_HPP */

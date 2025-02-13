/*
** EPITECH PROJECT, 2025
** ComponentTrue.hpp
** File description:
** ComponentTrue.hpp
*/

#ifndef COMPONENT_TRUE_HPP
#define COMPONENT_TRUE_HPP

#include "AInput.hpp"

namespace nts {
    class ComponentTrue : public AInput
    {
        public:
            ComponentTrue(std::string name);
            ~ComponentTrue();
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !COMPONENT_TRUE_HPP */

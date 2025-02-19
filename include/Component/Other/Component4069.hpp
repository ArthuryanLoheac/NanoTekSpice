/*
** EPITECH PROJECT, 2025
** Component4069.hpp
** File description:
** Component4069.hpp
*/

#ifndef COMPONENT_4069_HPP
#define COMPONENT_4069_HPP

#include "AComponent.hpp"

namespace nts
{
    class Component4069 : public AComponent
    {
    public:
        Component4069(std::string name);
        virtual ~Component4069() = default;
        nts::Tristate compute(std::size_t pin) override;
        size_t pinOutToInternPin(size_t pin) override;
        void setNotComputed() override;
        size_t getIdFromPin(size_t pin) override;
    };
}

#endif /* !COMPONENT_4069_HPP */

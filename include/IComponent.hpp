/*
** EPITECH PROJECT, 2025
** IComponent.hpp
** File description:
** IComponent.hpp
*/

#ifndef I_COMPONENT_HPP
#define I_COMPONENT_HPP

#include <cstddef>
#include <utility>

namespace nts
{
    enum Tristate {
        COMPUTING = -3,
        NOTCOMPUTED = -2,
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum TypePin {
        IN,
        OUT,
        USELESS
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pinOut, nts::IComponent &other,
                             std::size_t pinIn) = 0;
        virtual size_t pinOutToInternPin(size_t pin) = 0;
        virtual void setNotComputed() = 0;
        virtual size_t getIdFromPin(size_t pin) = 0;
        virtual std::vector<std::pair<TypePin,
                std::vector<std::pair<IComponent &,
                std::size_t>>>> getInOut() = 0;
    };
}

#endif /* !I_COMPONENT_HPP */

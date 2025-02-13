/*
** EPITECH PROJECT, 2025
** IComponent.hpp
** File description:
** IComponent.hpp
*/

#ifndef I_COMPONENT_HPP
#define I_COMPONENT_HPP

#include <cstddef>
#include <string>
#include <vector>
#include <map>

namespace nts
{
    enum Tristate {
        NOTCOMPUTED = -(true) + (-true),
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

    protected:
        std::string _name;
        std::map<TypePin, std::map<IComponent &, std::size_t>> _inOuts;
        std::vector<IComponent> _internComponents;
        Tristate _lastValueComputed;
    };
}

#endif /* !I_COMPONENT_HPP */

/*
** EPITECH PROJECT, 2025
** AComponent.hpp
** File description:
** AComponent.hpp
*/

#ifndef A_COMPONENT_HPP
#define A_COMPONENT_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>

#include "IComponent.hpp"

namespace nts
{
    class AComponent : public IComponent
    {
    public:
        class Errors : public std::exception
        {
            private:
                std::string _message;
            public:
                Errors(std::string const &message)
                    : _message(message) {};
                const char *what() const noexcept override
                {
                    return _message.c_str();
                }
        };

        virtual ~AComponent() = default;
        virtual void simulate(std::size_t tick) override;
        virtual nts::Tristate compute(std::size_t pin) override;
        virtual void setLink(std::size_t pinOut, nts::IComponent &other,
                            std::size_t pinIn) override;
        virtual size_t pinOutToInternPin(size_t pin) override;
        virtual void setNotComputed() override;
        virtual size_t getIdFromPin(size_t pin) override;
        std::vector<std::pair<TypePin,
            std::vector<std::pair<IComponent &,
            std::size_t>>>> &getInOut() override;
        std::string getName() override;
        virtual Tristate getValueComputed() override;

    protected:
        AComponent(std::string name)
            : _name(name) {};
        std::string _name;
        std::vector<std::pair<TypePin,
            std::vector<std::pair<IComponent &,
            std::size_t>>>> _inOuts;
        std::vector<std::shared_ptr<IComponent>> _internComponents;
        Tristate _ValueComputed;
        std::map<size_t, Tristate> _lastValue;
    };
}

#endif /* !A_COMPONENT_HPP */

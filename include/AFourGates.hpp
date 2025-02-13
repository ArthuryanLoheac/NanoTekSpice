/*
** EPITECH PROJECT, 2025
** AFourGates.hpp
** File description:
** AFourGates.hpp
*/

#ifndef A_FOUR_GATES_HPP
#define A_FOUR_GATES_HPP

#include "AComponent.hpp"

namespace nts
{
    class AFourGates : public AComponent
    {
    public:
        virtual ~AFourGates() = default;
        nts::Tristate compute(std::size_t pin) override;
        size_t pinOutToInternPin(size_t pin) override;
        void setNotComputed() override;
        size_t getIdFromPin(size_t pin) override;

    protected:
        AFourGates(std::string name);
    };
}

#endif /* !A_FOUR_GATES_HPP */

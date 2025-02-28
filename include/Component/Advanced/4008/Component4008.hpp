/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Composant4008
*/

#pragma once
#include "AComponent.hpp"
#include "ComponentSum.hpp"

namespace nts
{
    class Component4008 : public AComponent
    {
        public:
            Component4008(std::string name);
            Tristate compute(std::size_t pin) override;
            size_t pinOutToInternPin(size_t pin) override;
            size_t getIdFromPin(size_t pin) override;
    };
}

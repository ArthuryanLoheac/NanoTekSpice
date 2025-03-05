/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Composant4017
*/

#pragma once
#include "AComponent.hpp"
#include "ComponentSum.hpp"

namespace nts
{
    class Component4017 : public AComponent
    {
        private:
            size_t compteur = 0;
            nts::Tristate lastClock1 = FALSE;
            nts::Tristate lastClock2 = FALSE;
            void updateCompteur(Tristate reset, Tristate clock1, Tristate clock2);
            int updated = 0;

        public:
            Component4017(std::string name);
            void simulate(std::size_t tick) override;
            Tristate compute(std::size_t pin) override;
            size_t pinOutToInternPin(size_t pin) override;
            size_t getIdFromPin(size_t pin) override;
            nts::Tristate getVal(int i);
    };
}

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
            nts::Tristate lastClock1 = UNDEFINED;
            nts::Tristate lastClock2 = UNDEFINED;
            void updateCompteur(Tristate reset);

        public:
            Component4017(std::string name);
            Tristate compute(std::size_t pin) override;
            size_t pinOutToInternPin(size_t pin) override;
            size_t getIdFromPin(size_t pin) override;
            nts::Tristate getVal(int i);
    };
}

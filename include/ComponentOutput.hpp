/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ComponentOutPut
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
    class ComponentOutput : public AComponent {
        public:
            ComponentOutput(std::string name);
            ~ComponentOutput();
            nts::Tristate compute(std::size_t pin) override;
    };
}
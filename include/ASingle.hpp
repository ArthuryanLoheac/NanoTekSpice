/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ASingle
*/

#pragma once
#include "AComponent.hpp"
#include <memory>

namespace nts {
    class ASingle : public AComponent
    {
        protected:
            ASingle(std::string name);
            nts::Tristate getVal(int i, std::vector<std::pair<nts::TypePin,
            std::vector<std::pair<nts::IComponent &, std::size_t>>>> _inOuts);
    };    
}
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
    };    
}
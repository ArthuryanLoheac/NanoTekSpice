/*
** EPITECH PROJECT, 2025
** ASingle.hpp
** File description:
** ASingle.hpp
*/

#ifndef A_SINGLE_HPP
#define A_SINGLE_HPP

#include "AComponent.hpp"

namespace nts
{
    class ASingle : public AComponent
    {
    protected:
        ASingle(std::string name);
        nts::Tristate getVal(int i);
    };
}

#endif /* !A_SINGLE_HPP */

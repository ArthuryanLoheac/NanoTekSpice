/*
** EPITECH PROJECT, 2025
** ComponentAnd.hpp
** File description:
** ComponentAnd.hpp
*/

#ifndef COMPONENT_4011_HPP
#define COMPONENT_4011_HPP

#include "AFourGates.hpp"
#include "ComponentNand.hpp"

namespace nts
{
    class Component4011 : public AFourGates
    {
        public:
            Component4011(std::string name);
    };
}

#endif /* !COMPONENT_4011_HPP */

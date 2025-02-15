/*
** EPITECH PROJECT, 2025
** Test
** File description:
** main
*/

#include <iostream>
#include "Circuit.hpp"
#include "../include/ComponentTrue.hpp"
#include "../include/ComponentFalse.hpp"
#include "../include/ComponentXor.hpp"
#include "../include/ComponentInput.hpp"

int main ( void )
{
    nts::ComponentXor componentXor("and");
    nts::ComponentFalse componentFalse("1");

    componentXor.setLink(3, componentXor, 2);
    componentXor.setLink(1, componentFalse, 1);
    componentXor.setNotComputed();
    printf("ComponentXor: %d ? %d\n", componentXor.compute(0), nts::UNDEFINED);
}

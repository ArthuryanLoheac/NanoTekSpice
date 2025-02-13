/*
** EPITECH PROJECT, 2025
** Test
** File description:
** main
*/

#include <iostream>

#include "ComponentTrue.hpp"
#include "ComponentOutput.hpp"
#include "Circuit.hpp"

int main ( void )
{
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentTrue>("true"));
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("true").setLink(1, circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
}

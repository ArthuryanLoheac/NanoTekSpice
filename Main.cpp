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
#include "../include/Component4081.hpp"

int main() {
    nts::Circuit circuit;

    circuit.addComponent(std::make_unique<nts::ComponentTrue>("true"));
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("true").setLink(1, circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
}
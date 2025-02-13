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
    nts::ComponentInput *a;

    circuit.addComponent(std::make_unique<nts::ComponentInput>("c"));
    circuit.addComponent(std::make_unique<nts::ComponentInput>("a"));
    circuit.addComponent(std::make_unique<nts::ComponentInput>("b"));
    a = dynamic_cast<nts::ComponentInput *>(circuit.getComponent("a").get());
    a->setValue(nts::Tristate::TRUE);
    a = dynamic_cast<nts::ComponentInput *>(circuit.getComponent("b").get());
    a->setValue(nts::Tristate::FALSE);
    a = dynamic_cast<nts::ComponentInput *>(circuit.getComponent("c").get());
    a->setValue(nts::Tristate::TRUE);
    circuit.addComponent(std::make_unique<nts::ComponentOutput>("output"));
    circuit.getComponent("b")->setLink(1, *circuit.getComponent("output"), 1);
    circuit.simulate(1);
    circuit.display();
}

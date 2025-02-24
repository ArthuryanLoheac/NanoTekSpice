/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** run
*/
#include "Circuit.hpp"

int run(nts::Circuit &circuit)
{
    circuit.simulate(1);
    circuit.display();
    return 0;
}
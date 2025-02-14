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
#include "../include/ComponentAnd.hpp"
#include "../include/ComponentInput.hpp"

int main ( void )
{
    nts::ComponentAnd componentAnd("and");
    nts::ComponentAnd componentAnd2("and2");

    componentAnd.setLink(3, componentAnd2, 2);
    componentAnd2.setLink(3, componentAnd, 1);
    componentAnd2.setNotComputed();
    componentAnd.setNotComputed();
    printf("%d ? -1\n", componentAnd.compute(0));
}

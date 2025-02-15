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
    nts::Component4081 component4081("4081");
    nts::Component4081 component4081_2("4081_2");
    nts::ComponentTrue componentTrue("t");

    component4081.setLink(5, componentTrue, 1);
    component4081.setLink(6, componentTrue, 1);
    component4081_2.setLink(2, componentTrue, 1);
    component4081_2.setLink(1, component4081, 4);

    component4081.setNotComputed();
    component4081_2.setNotComputed();
    printf("%d ? %d\n", component4081_2.compute(0), nts::TRUE);
}
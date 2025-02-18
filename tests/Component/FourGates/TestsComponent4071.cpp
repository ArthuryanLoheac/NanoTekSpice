/*
** EPITECH PROJECT, 2025
** TestsComponent4071.cpp
** File description:
** TestsComponent4071.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "Component4071.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Component4071, defaultStat, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::UNDEFINED);
}

Test(Component4071, firstTrue, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    Component4071.setLink(1, componentTrue1, 1);
    Component4071.setLink(2, componentTrue2, 1);

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::TRUE);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::UNDEFINED);
}

Test(Component4071, SecondTrue, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    Component4071.setLink(5, componentTrue1, 1);
    Component4071.setLink(6, componentTrue2, 1);

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::TRUE);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::UNDEFINED);
}
Test(Component4071, ThreeTrue, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    Component4071.setLink(8, componentTrue1, 1);
    Component4071.setLink(9, componentTrue2, 1);

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::TRUE);
    cr_assert_eq(Component4071.compute(3), nts::UNDEFINED);
}
Test(Component4071, FourTrue, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    Component4071.setLink(13, componentTrue1, 1);
    Component4071.setLink(12, componentTrue2, 1);

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::TRUE);
}

Test(Component4071, FourTrueInverted_Sens, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    componentTrue1.setLink(1, Component4071, 13);
    componentTrue2.setLink(1, Component4071, 12);

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::TRUE);
}

Test(Component4071, FourTrueMultiple, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");
    nts::ComponentFalse componentFalse("f1");

    componentTrue1.setLink(1, Component4071, 13);
    componentTrue2.setLink(1, Component4071, 12);
    Component4071.setLink(1, componentTrue1, 1);
    Component4071.setLink(2, componentFalse, 1);

    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::TRUE);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::TRUE);
}

Test(Component4071, SecondTrueNotComputed, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue1("t1");
    nts::ComponentTrue componentTrue2("t2");

    Component4071.setLink(5, componentTrue1, 1);
    Component4071.setLink(6, componentTrue2, 1);

    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::UNDEFINED);
}

Test(Component4071, TwoComponentLinked, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::Component4071 Component4071_2("4071_2");
    nts::ComponentTrue componentTrue("t");

    Component4071.setLink(1, componentTrue, 1);
    Component4071.setLink(2, componentTrue, 1);
    Component4071_2.setLink(2, componentTrue, 1);
    Component4071_2.setLink(1, Component4071, 3);

    Component4071.setNotComputed();
    Component4071_2.setNotComputed();
    cr_assert_eq(Component4071_2.compute(0), nts::TRUE);
}

Test(Component4071, TwoComponentLinked_two, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::Component4071 Component4071_2("4071_2");
    nts::ComponentTrue componentTrue("t");

    Component4071.setLink(5, componentTrue, 1);
    Component4071.setLink(6, componentTrue, 1);
    Component4071_2.setLink(2, componentTrue, 1);
    Component4071_2.setLink(1, Component4071, 4);

    Component4071.setNotComputed();
    Component4071_2.setNotComputed();
    cr_assert_eq(Component4071_2.compute(0), nts::TRUE);
}

Test(Component4071, TwoComponentLinked_output, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::Component4071 Component4071_2("4071_2");
    nts::ComponentTrue componentTrue("t");
    nts::ComponentOutput componentOutput("output");

    Component4071.setLink(5, componentTrue, 1);
    Component4071.setLink(6, componentTrue, 1);
    Component4071_2.setLink(8, componentTrue, 1);
    Component4071_2.setLink(9, Component4071, 4);
    componentOutput.setLink(1, Component4071_2, 10);

    Component4071.setNotComputed();
    Component4071_2.setNotComputed();
    componentOutput.setNotComputed();
    cr_assert_eq(componentOutput.compute(0), nts::TRUE);
}

Test(Component4071, PinOut_and_PinIn_are_both_IN, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue("t1");

    Component4071.setLink(5, componentTrue, 1);
    cr_assert_throw(Component4071.setLink(6, Component4071, 1), nts::AComponent::Errors);
}

Test(Component4071, PinOut_and_PinIn_are_both_OUT, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue("t1");

    Component4071.setLink(5, componentTrue, 1);
    cr_assert_throw(Component4071.setLink(3, Component4071, 4), nts::AComponent::Errors);
}

Test(Component4071, autoLink, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue("t1");

    Component4071.setLink(5, componentTrue, 1);
    Component4071.setLink(6, Component4071, 4);
    Component4071.setNotComputed();
    cr_assert_eq(Component4071.compute(0), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(1), nts::TRUE);
    cr_assert_eq(Component4071.compute(2), nts::UNDEFINED);
    cr_assert_eq(Component4071.compute(3), nts::UNDEFINED);
}

Test(Component4071, linkToNoOutput, .init=redirect_all_std)
{
    nts::Component4071 Component4071("4071");
    nts::ComponentTrue componentTrue("t1");

    Component4071.setLink(5, componentTrue, 1);
    cr_assert_throw(Component4071.setLink(7, Component4071, 4), nts::AComponent::Errors);
}

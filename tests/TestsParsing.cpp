/*
** EPITECH PROJECT, 2025
** TestsComponentTrue.cpp
** File description:
** TestsComponentTrue.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Parsing.hpp"
#include <iostream>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parseFile, valid, .init=redirect_all_std)
{
    std::cout << parseFile("tests/Exemple/nts_single/xor.nts");
    fflush(stdout);
    cr_assert_stdout_eq_str(
        "# Basic XOR logic gate\n"
        "#\n"
        "# in_1  -1-+---\\\n"
        "#          |xor |-3- out\n"
        "# in_2  -2-+---/\n"
        "\n"
        ".chipsets:\n"
        "input in_1\n"
        "input in_2\n"
        "output out\n"
        "xor gate\n"
        "\n"
        ".links:\n"
        "in_1:1 gate:1\n"
        "in_2:1 gate:2\n"
        "out:1 gate:3\n");
}

Test(parseFile, Invalid, .init=redirect_all_std)
{
    cr_assert_throw(parseFile("invalid_file"), std::invalid_argument);
}

Test(parseByLine, valid, .init=redirect_all_std)
{
    std::vector<std::string> lines = parseByLine("line1\nline2\nline3\n");

    cr_assert_eq(lines.size(), 3);
    cr_assert_str_eq(lines[0].c_str(), "line1");
    cr_assert_str_eq(lines[1].c_str(), "line2");
    cr_assert_str_eq(lines[2].c_str(), "line3");
}

Test(parseByLine, empty, .init=redirect_all_std)
{
    std::vector<std::string> lines = parseByLine("");

    cr_assert_eq(lines.size(), 0);
}
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
        "in_1:1 gate:1 #commentary\n"
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

Test(removeCommentary, xor, .init=redirect_all_std)
{
    std::string a = parseFile("tests/Exemple/nts_single/xor.nts");
    std::vector<std::string> b = parseByLine(a);
    std::vector<std::string> c = removeCommentary(b);

    cr_assert_eq(c.size(), 9);
    cr_assert_str_eq(c[0].c_str(), ".chipsets:");
    cr_assert_str_eq(c[1].c_str(), "input in_1");
    cr_assert_str_eq(c[2].c_str(), "input in_2");
    cr_assert_str_eq(c[3].c_str(), "output out");
    cr_assert_str_eq(c[4].c_str(), "xor gate");
    cr_assert_str_eq(c[5].c_str(), ".links:");
    cr_assert_str_eq(c[6].c_str(), "in_1:1 gate:1");
    cr_assert_str_eq(c[7].c_str(), "in_2:1 gate:2");
    cr_assert_str_eq(c[8].c_str(), "out:1 gate:3");
}

Test(removeCommentary, xor_formated, .init=redirect_all_std)
{
    std::string a = parseFile("tests/Exemple/nts_single/xor_formated.nts");
    std::vector<std::string> b = parseByLine(a);
    std::vector<std::string> c = removeCommentary(b);

    cr_assert_eq(c.size(), 9);
    cr_assert_str_eq(c[0].c_str(), ".chipsets:");
    cr_assert_str_eq(c[1].c_str(), "input in_1");
    cr_assert_str_eq(c[2].c_str(), "input in_2");
    cr_assert_str_eq(c[3].c_str(), "output out");
    cr_assert_str_eq(c[4].c_str(), "xor gate");
    cr_assert_str_eq(c[5].c_str(), ".links:");
    cr_assert_str_eq(c[6].c_str(), "in_1:1 gate:1");
    cr_assert_str_eq(c[7].c_str(), "in_2:1 gate:2");
    cr_assert_str_eq(c[8].c_str(), "out:1 gate:3");
}

Test(getPartList, xor, .init=redirect_all_std)
{
    std::string a = parseFile("tests/Exemple/nts_single/xor.nts");
    std::vector<std::string> b = parseByLine(a);
    std::vector<std::string> c = removeCommentary(b);
    std::vector<std::string> chip = getPartList(c, ".chipsets:", ".links:");
    std::vector<std::string> link = getPartList(c, ".links:", ".chipsets:");

    cr_assert_eq(chip.size(), 4);
    cr_assert_str_eq(chip[0].c_str(), "input in_1");
    cr_assert_str_eq(chip[1].c_str(), "input in_2");
    cr_assert_str_eq(chip[2].c_str(), "output out");
    cr_assert_str_eq(chip[3].c_str(), "xor gate");
    cr_assert_eq(link.size(), 3);
    cr_assert_str_eq(link[0].c_str(), "in_1:1 gate:1");
    cr_assert_str_eq(link[1].c_str(), "in_2:1 gate:2");
    cr_assert_str_eq(link[2].c_str(), "out:1 gate:3");
}

Test(getPartList, noPart, .init=redirect_all_std)
{
    std::string a = parseFile("tests/Exemple/nts_single/xor.nts");
    std::vector<std::string> b = parseByLine(a);
    std::vector<std::string> c = removeCommentary(b);

    cr_assert_throw(getPartList(c, ".nohere:", ".links:"), std::exception);
}

Test(ParseBySpaces, valid, .init=redirect_all_std)
{
    std::vector<std::string> lines = parseByLine("line1 line2 line3\nline4 line5\n");
    std::vector<std::vector<std::string>> newLines = ParseBySpaces(lines);

    cr_assert_eq(newLines.size(), 2);
    cr_assert_eq(newLines[0].size(), 3);
    cr_assert_str_eq(newLines[0][0].c_str(), "line1");
    cr_assert_str_eq(newLines[0][1].c_str(), "line2");
    cr_assert_str_eq(newLines[0][2].c_str(), "line3");
    cr_assert_eq(newLines[1].size(), 2);
    cr_assert_str_eq(newLines[1][0].c_str(), "line4");
    cr_assert_str_eq(newLines[1][1].c_str(), "line5");
}

Test(ParseBySpaces, validWithTab, .init=redirect_all_std)
{
    std::vector<std::string> lines = parseByLine("  line1          line2\tline3\nline4 line5      \n");
    std::vector<std::vector<std::string>> newLines = ParseBySpaces(lines);

    cr_assert_eq(newLines.size(), 2);
    cr_assert_eq(newLines[0].size(), 3);
    cr_assert_str_eq(newLines[0][0].c_str(), "line1");
    cr_assert_str_eq(newLines[0][1].c_str(), "line2");
    cr_assert_str_eq(newLines[0][2].c_str(), "line3");
    cr_assert_eq(newLines[1].size(), 2);
    cr_assert_str_eq(newLines[1][0].c_str(), "line4");
    cr_assert_str_eq(newLines[1][1].c_str(), "line5");
}

Test(ParseBySpaces, xorChip, .init=redirect_all_std)
{
    std::string a = parseFile("tests/Exemple/nts_single/xor.nts");
    std::vector<std::string> b = parseByLine(a);
    std::vector<std::string> c = removeCommentary(b);
    std::vector<std::string> chip = getPartList(c, ".chipsets:", ".links:");
    std::vector<std::vector<std::string>> newChip = ParseBySpaces(chip);
    
    cr_assert_eq(newChip.size(), 4);
    cr_assert_eq(newChip[0].size(), 2);
    cr_assert_str_eq(newChip[0][0].c_str(), "input");
    cr_assert_str_eq(newChip[0][1].c_str(), "in_1");
    cr_assert_eq(newChip[1].size(), 2);
    cr_assert_str_eq(newChip[1][0].c_str(), "input");
    cr_assert_str_eq(newChip[1][1].c_str(), "in_2");
    cr_assert_eq(newChip[2].size(), 2);
    cr_assert_str_eq(newChip[2][0].c_str(), "output");
    cr_assert_str_eq(newChip[2][1].c_str(), "out");
    cr_assert_eq(newChip[3].size(), 2);
    cr_assert_str_eq(newChip[3][0].c_str(), "xor");
    cr_assert_str_eq(newChip[3][1].c_str(), "gate");
}

Test(ParseBySpaces, xorLink, .init=redirect_all_std)
{
    std::string a = parseFile("tests/Exemple/nts_single/xor.nts");
    std::vector<std::string> b = parseByLine(a);
    std::vector<std::string> c = removeCommentary(b);
    std::vector<std::string> link = getPartList(c, ".links:", ".chipsets:");
    std::vector<std::vector<std::string>> newLink = ParseBySpaces(link);
    
    cr_assert_eq(newLink.size(), 3);
    cr_assert_eq(newLink[0].size(), 2);
    cr_assert_str_eq(newLink[0][0].c_str(), "in_1:1");
    cr_assert_str_eq(newLink[0][1].c_str(), "gate:1");
    cr_assert_eq(newLink[1].size(), 2);
    cr_assert_str_eq(newLink[1][0].c_str(), "in_2:1");
    cr_assert_str_eq(newLink[1][1].c_str(), "gate:2");
    cr_assert_eq(newLink[2].size(), 2);
    cr_assert_str_eq(newLink[2][0].c_str(), "out:1");
    cr_assert_str_eq(newLink[2][1].c_str(), "gate:3");
}

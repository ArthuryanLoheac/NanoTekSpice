/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Parsing
*/

#pragma once
#include <vector>

std::string parseFile(const char *file);
std::vector<std::string> parseByLine(std::string content);
std::vector<std::string> removeCommentary(std::vector<std::string> content);
std::vector<std::string> getPartList(std::vector<std::string> lines,
    std::string start, std::string stop);
std::vector<std::vector<std::string>> ParseBySpaces(
    std::vector<std::string> lines);

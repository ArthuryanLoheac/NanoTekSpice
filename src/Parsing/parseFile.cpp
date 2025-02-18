/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** parseFile
*/
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

static std::string without_left_spaces_and_tab(const std::string& str) {
    auto it = std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
    return std::string(it, str.end());
}

static std::string without_right_spaces_and_tab(const std::string& str) {
    auto it = std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
    return std::string(str.begin(), it.base());
}

std::vector<std::string> getPartList(std::vector<std::string> lines,
    std::string start, std::string stop)
{
    long int pos = -1;
    std::vector<std::string> linesInPart;

    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i] == start){
            pos = i;
            continue;
        }
        if (pos != -1 && (long int)i > pos) {
            if (lines[i] == stop)
                break;
            linesInPart.push_back(lines[i]);
        }
    }
    if (pos == -1)
        throw std::invalid_argument("Error: Unable to find " + start);
    return linesInPart;
}

std::vector<std::string> removeCommentary(std::vector<std::string> content)
{
    std::vector<std::string> lines;
    std::string line;

    for (size_t i = 0; i < content.size(); i++) {
        line = without_left_spaces_and_tab(content[i]);
        if (line.find("#") != std::string::npos)
            line = line.substr(0, line.find("#"));
        if (line.size() > 0)
            lines.push_back(without_right_spaces_and_tab(line));
    }
    return lines;
}

std::vector<std::string> parseByLine(std::string content)
{
    std::stringstream stream(content);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::string parseFile(const char *file)
{
    std::ifstream f(file);
    std::string content;

    if (f.is_open()) {
        content = std::string((std::istreambuf_iterator<char>(f)),
            std::istreambuf_iterator<char>());
        f.close();
        return content;
    } else
        throw std::invalid_argument("Error: Unable to open file");
}

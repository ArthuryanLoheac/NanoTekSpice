/*
** EPITECH PROJECT, 2025
** Parsing.cpp
** File description:
** Parsing.cpp
*/

#include <fstream>
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

static std::vector<std::string> ParseByColon(const std::string &str)
{
    std::vector<std::string> parts;
    std::stringstream stream(str);
    std::string part;

    while (std::getline(stream, part, ':')) {
        parts.push_back(part);
    }
    return parts;
}

static void ParseBySpacesAndTab(std::stringstream &stream, std::string &word,
    std::vector<std::string> &newLine)
{
    std::stringstream stream2;
    std::string word2;

    word.clear();
    newLine.clear();
    while (std::getline(stream, word, ' ')){
        word2.clear();
        stream2 = std::stringstream(word);
        while (std::getline(stream2, word2, '\t')){
            std::vector<std::string> parts = ParseByColon(word2);
            newLine.insert(newLine.end(), parts.begin(), parts.end());
        }
    }
}

std::vector<std::vector<std::string>> ParseBySpaces(
    std::vector<std::string> lines)
{
    std::vector<std::vector<std::string>> newLines;
    std::vector<std::string> newLine;
    std::stringstream stream;
    std::string word;

    for (std::string line : lines) {
        stream = std::stringstream(line);
        ParseBySpacesAndTab(stream, word, newLine);
        newLines.push_back(newLine);
    }
    return newLines;
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

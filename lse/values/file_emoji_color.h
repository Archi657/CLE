#ifndef FILE_COLORS_H
#define FILE_COLORS_H

#include "colors.h"  // Colors for text
#include "emojis.h"  // List of emojis to display

#include <unordered_map>
#include <string>

// Ensure all color and emoji constants are std::string
const std::unordered_map<std::string, std::string> fileColors = {
    {".c", std::string(BLUE) + std::string(C)}, 
    {".cpp", std::string(BLUE) + std::string(C)}, 
    {".py", std::string(BLUE) + std::string(PY)}, 
    {".txt", std::string(YELLOW) + std::string(TEXT)}
};

#endif // FILE_COLORS_H

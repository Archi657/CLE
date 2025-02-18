#ifndef FUNCTIONS_HPP
#define MATH_UTILS_HPP
#include "colors.h" // colors for text
#include "emojis.h" // list of emojis to display
#include <dirent.h>
#include <iostream>
#include <string> // Required for std::string

using namespace std;

inline bool endsWith(const std::string &fullString, const std::string &ending) {
  if (ending.size() > fullString.size())
    return false;
  return fullString.compare(fullString.size() - ending.size(), ending.size(),
                            ending) == 0;
}

inline int listFiles(std::string path_, bool showHidden, bool longFormat) {

  const char *path = path_.c_str();
  DIR *dir = opendir(path);
  if (!dir) {
    cerr << "Error: Could not open directory " << path << endl;
    return -1;
  }
  std::cout << "Listing: " << path << "\n";
  struct dirent *entry;
  string space = " ";
  if (longFormat) {
    space = "\n";
  }
  while ((entry = readdir(dir)) != nullptr) {
    if (entry->d_type == DT_UNKNOWN) {
      cout << RED << "N/A " << entry->d_name << space << RESET;
    } else if (entry->d_type == DT_DIR) {
      cout << MAGENTA << HIDDEN << entry->d_name << space << RESET;
    } else if (endsWith(entry->d_name, ".c") ||
               endsWith(entry->d_name, ".cpp")) {
      cout << BLUE << C << entry->d_name << space << RESET;
    } else if (endsWith(entry->d_name, ".py")) {
      cout << BLUE << PY << entry->d_name << space << RESET;
    } else if (endsWith(entry->d_name, ".txt")) {
      cout << YELLOW << TEXT << entry->d_name << space << RESET;
    } else {
      cout << TEXT << entry->d_name << space;
    }
    // cout << entry->d_name << "\n";
  }
  closedir(dir);
  return 0;
}

#endif

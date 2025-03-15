#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "./values/colors.h"    // Colors for text
#include "./values/emojis.h"    // Emojis for file types
#include "./values/file_emoji_color.h" // File extension to color mapping

#include <dirent.h>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

inline bool endsWith(const std::string &fullString, const std::string &ending) {
    if (ending.size() > fullString.size()) return false;
    return fullString.compare(fullString.size() - ending.size(), ending.size(), ending) == 0;
}

inline int listFiles(std::string path_, bool showHidden, bool longFormat) {
  const char *path = path_.c_str();
  DIR *dir = opendir(path);
  
  if (!dir) {
      cerr << "Error: Could not open directory " << path << endl;
      return -1;
  }

  cout << "Listing: " << path << "\n";

  struct dirent *entry;
  string space = longFormat ? "\n" : " ";

  while ((entry = readdir(dir)) != nullptr) {
      string fileName = entry->d_name;

      // Ignore hidden files if showHidden is false
      if (!showHidden && fileName[0] == '.') continue;

      // Get file extension safely
      size_t dotPos = fileName.find_last_of(".");
      string fileExtension = (dotPos != string::npos) ? fileName.substr(dotPos) : "";

      if (entry->d_type == DT_UNKNOWN) {
          cout << RED << "N/A " << fileName << space << RESET;
      } else if (entry->d_type == DT_DIR) {
          cout << MAGENTA << HIDDEN << fileName << space << RESET;
      } else {
          // Check if the file extension exists in fileColors
          if (fileColors.find(fileExtension) != fileColors.end()) {
              cout << fileColors.at(fileExtension) << fileName << space << RESET;
          } else {
              cout << TEXT << fileName << space;
          }
      }
  }
  closedir(dir);
  return 0;
}


#endif // FUNCTIONS_HPP

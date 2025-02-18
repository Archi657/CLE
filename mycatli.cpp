#include <dirent.h>
#include <iostream>

#include "colors.h"
#include "emojis.h"
using namespace std;

bool endsWith(const string &fullString, const string &ending) {
    if (ending.size() > fullString.size())
      return false;
  
    return fullString.compare(fullString.size() - ending.size(), ending.size(),
                              ending) == 0;
  }

int main() {
  const char *path = "./test_dir";
  DIR *dir = opendir(path);

  if (!dir) {
    cerr << "Error: Could not open directory " << path << endl;
    return 1;
  }

  struct dirent *entry;

  while ((entry = readdir(dir)) != nullptr) {
    if (entry->d_type == DT_UNKNOWN) {
      cout << RED << "N/A " << entry->d_name << " " << RESET;
    } else if (entry->d_type == DT_DIR  ) {
      cout << MAGENTA << HIDDEN << entry->d_name << " " << RESET;
    } else if (endsWith(entry->d_name, ".c") || endsWith(entry->d_name, ".cpp")){
        cout << BLUE << C << entry->d_name << " " << RESET;
    } else if(endsWith(entry->d_name, ".py")){
        cout << BLUE << PY << entry->d_name << " " << RESET;
    }else if(endsWith(entry->d_name, ".txt")){
      cout << YELLOW << TEXT << entry->d_name << " " << RESET;
  }
    // cout << entry->d_name << "\n";
  }

  closedir(dir);
  return 0;
}


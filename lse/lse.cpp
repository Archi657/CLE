#include <dirent.h> // information of the directory
#include <limits.h> // for PATH_MAX also for directory
#include <unistd.h> // for getcwd() for the directory

#include "functions.hpp" // useful functions like to get the extension of a file

using namespace std;

int main(int argc, char **argv) {

  char cwd[PATH_MAX];
  string path_ = ".";

  bool showHidden = false, longFormat = false;

  // Parse command-line arguments
  for (int i = 1; i < argc; i++) {
    string arg = argv[i];

    if (arg == "-a") {
      showHidden = true;
    } else if (arg == "-l") {
      longFormat = true;
    } else if (arg == "-la" || arg == "-al") {
      showHidden = true;
      longFormat = true;
    } else {
      path_ = arg; // Assume it's a directory path
    }

    if(longFormat){
      //listLongFormat();
    }
    listFiles(path_, showHidden, longFormat);

    return 0;
  }
}
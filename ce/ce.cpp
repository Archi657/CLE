#include <stdio.h>
#include <unistd.h>  // For chdir() on Linux/macOS
#include <limits.h>  // For PATH_MAX

using namespace std;

int main(int argc, char **argv) {

    if (chdir(argv[1]) != 0) {
        perror("chdir failed");
        return 1;
    }
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        chdir(argv[1]);
        printf("Current directory: %s\n", cwd);
    } else {
        perror("getcwd failed");
        return 1;
    }

    return 0;
}
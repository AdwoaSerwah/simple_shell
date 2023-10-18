#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) {
    if (name == NULL) {
        return -1; // Invalid input
    }

    char **env = environ;
    char **src = env;
    char **dst = env;

    while (*src != NULL) {
        if (strncmp(*src, name, strlen(name)) == 0 && (*src)[strlen(name)] == '=') {
            // Found the variable to delete, skip it
            free(*src);
            src++;
        } else {
            // Copy the remaining variables to the new position
            *dst = *src;
            dst++;
            src++;
        }
    }

    *dst = NULL; // Mark the end of the new environment array

    // Update environ to reflect the removal
    environ = (char **)realloc(env, (dst - env + 1) * sizeof(char *));

    if (environ == NULL) {
        perror("_unsetenv");
        return -1; // Memory allocation failed
    }

    return 0;
}
int main() {
    _unsetenv("MY_VARIABLE");
    _unsetenv("ANOTHER_VARIABLE");
    _unsetenv("YET_ANOTHER");

    // Print the modified environment
    char **env = environ;
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}


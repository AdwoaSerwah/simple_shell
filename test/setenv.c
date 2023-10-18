#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || value == NULL) {
        return -1; // Invalid input
    }

    char **env = environ;
    while (*env != NULL) {
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=') {
            if (overwrite) {
                // Update the value
                free(*env);
                *env = (char *)malloc(strlen(name) + strlen(value) + 2);
                if (*env == NULL) {
                    perror("_setenv");
                    return -1; // Memory allocation failed
                }
                sprintf(*env, "%s=%s", name, value);
                return 0;
            }
            return 0; // Environment variable already exists
        }
        env++;
    }

    // If the variable does not exist, add it to environ
    char **new_environ = (char **)malloc((env - environ + 2) * sizeof(char *));
    if (new_environ == NULL) {
        perror("_setenv");
        return -1; // Memory allocation failed
    }

    int i = 0;
    for (char **old = environ; *old != NULL; old++, i++) {
        new_environ[i] = *old;
    }
    new_environ[i] = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (new_environ[i] == NULL) {
        perror("_setenv");
        return -1; // Memory allocation failed
    }
    sprintf(new_environ[i], "%s=%s", name, value);
    new_environ[i + 1] = NULL;

    free(environ);
    environ = new_environ;

    return 0;
}
int main() {
    _setenv("MY_VARIABLE", "new_value", 1);
    _setenv("ANOTHER_VARIABLE", "value", 0);
    _setenv("YET_ANOTHER", "new_value", 1);

    // Print the modified environment
    char **env = environ;
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}


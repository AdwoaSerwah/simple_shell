#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *env[]) {
	printf("Address of env: %p\n", (void*)env);
	char **ptr = environ;
	while (*ptr != NULL)
	{
		printf("Address of environ: %s\n", *ptr);
		ptr++;
	}
	printf("same thing using env[] in main\n\n\n");
	for (int i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }

	return 0;
}


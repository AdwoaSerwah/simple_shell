#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t parent_pid = getppid();
    pid_t current_pid = getpid();

    printf("Parent Process PID (getppid): %d\n", parent_pid);
    printf("Current Process PID (getpid): %d\n", current_pid);

    return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <sys/wait.h>

static void prog_timeout(int sig)
{
    exit(1);
}

__attribute__((constructor))
static void enable_timeout_cons(void)
{
    signal(SIGALRM, prog_timeout);
    alarm(60);
}

static unsigned int read_uint(void)
{
    unsigned int value;

    fflush(stdout);
    scanf("%u", &value);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return value;
}

int main(void)
{
    pid_t child;
    int status;
    long syscall;
    char shellcode[128] = {0};

    child = fork();

    if (child)
    {
        while (1)
        {
            wait(&status);
            if (WIFEXITED(status) || WIFSIGNALED(status))
            {
                puts("child is exiting...");
                return 0;
            }

            /*
             * Inspect child's registers.
             * Offset 44 in USER area == ORIG_EAX on 32-bit x86.
             */
            syscall = ptrace(PTRACE_PEEKUSER, child, 44, 0);

        } while (syscall != 11);

        puts("no exec() for you");
        kill(child, SIGKILL);
    } else {
        prctl(PR_SET_PDEATHSIG, 1);

        ptrace(PTRACE_TRACEME, 0, 0, 0);

        puts("Give me some shellcode, k");

        gets(shellcode);      // intentionally vulnerable
    }

    return 0;
}
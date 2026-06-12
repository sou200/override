#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <unistd.h>

void timeout_handler()
{
    exit(1);
}

void setup_timeout()
{
    signal(SIGALRM, timeout_handler);
    alarm(60);
}

void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int authenticate(char *login, int serial)
{
    int len;
    int hash;
    int i;

    // Remove trailing newline from fgets()
    login[strcspn(login, "\n")] = '\0';

    len = strnlen(login, 32);

    // Username must be longer than 5 chars
    if (len <= 5)
        return 0;

    // Anti-debugging check
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        puts("\x1B[32m.---------------------------.");
        puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
        puts("\x1B[32m'---------------------------'");
        return 0;
    }

    hash = (login[3] ^ 0x1337) + 6221293;

    for (i = 0; i < len; i++)
    {
        // Reject non-printable characters
        if (login[i] <= 31)
            return 0;

        hash += (hash ^ login[i]) % 0x539;
    }

    printf("%d", hash); ////////////

    return serial == hash;
}

int main()
{
    char login[32];
    int serial;

    setup_timeout();

    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");

    printf("-> Enter Login: ");
    fgets(login, sizeof(login), stdin);

    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");

    printf("-> Enter Serial: ");
    scanf("%d", &serial);

    if (!authenticate(login, serial))
        return 1;

    puts("Authenticated!");
    system("/bin/sh");

    return 0;
}
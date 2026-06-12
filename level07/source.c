#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void clear_stdin(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

static unsigned int get_unum(void)
{
    unsigned int value = 0;

    fflush(stdout);
    scanf("%u", &value);
    clear_stdin();

    return value;
}

static int store_number(unsigned int *data)
{
    unsigned int number;
    unsigned int index;

    printf(" Number: ");
    number = get_unum();

    printf(" Index: ");
    index = get_unum();

    /*
     * Some slots are reserved.
     * Also reject numbers whose most significant byte is 0xB7.
     */
    if ((index % 3 == 0) || ((number >> 24) == 0xB7))
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");

        return 1;
    }

    data[index] = number;
    return 0;
}

static int read_number(unsigned int *data)
{
    unsigned int index;

    printf(" Index: ");
    index = get_unum();

    printf(" Number at data[%u] is %u\n", index, data[index]);

    return 0;
}

int main(int argc, char **argv, char **envp)
{
    unsigned int data[100];
    char command[20];
    int result;

    memset(data, 0, sizeof(data));

    /* Wipe argv strings */
    for (char **p = argv; *p; p++)
        memset(*p, 0, strlen(*p));

    /* Wipe environment strings */
    for (char **p = envp; *p; p++)
        memset(*p, 0, strlen(*p));

    puts(
        "----------------------------------------------------\n"
        "  Welcome to wil's crappy number storage service!   \n"
        "----------------------------------------------------\n"
        " Commands:                                          \n"
        "    store - store a number into the data storage    \n"
        "    read  - read a number from the data storage     \n"
        "    quit  - exit the program                        \n"
        "----------------------------------------------------\n"
        "   wil has reserved some storage :>                 \n"
        "----------------------------------------------------\n"
    );

    while (1)
    {
        printf("Input command: ");

        result = 1;

        if (!fgets(command, sizeof(command), stdin))
            break;

        command[strcspn(command, "\n")] = '\0';

        if (!memcmp(command, "store", 5))
        {
            result = store_number(data);
        }
        else if (!memcmp(command, "read", 4))
        {
            result = read_number(data);
        }
        else if (!memcmp(command, "quit", 4))
        {
            return 0;
        }

        if (result)
            printf(" Failed to do %s command\n", command);
        else
            printf(" Completed %s command successfully\n", command);

        memset(command, 0, sizeof(command));
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

static int decrypt(unsigned char key)
{
    char encrypted[] = "Q}|u`sfg~sf{}|a3";
    size_t len = strlen(encrypted);

    for (size_t i = 0; i < len; i++)
        encrypted[i] ^= key;

    if (strcmp(encrypted, "Congratulations!") == 0)
        return system("/bin/sh");

    puts("\nInvalid Password");
    return 0;
}

static int test(int user_input, int target)
{
    int diff = target - user_input;

    switch (diff)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            return decrypt((unsigned char)diff);

        default:
            return decrypt((unsigned char)rand());
    }
}

int main(void)
{
    int password;

    srand(time(NULL));

    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");

    printf("Password:");
    scanf("%d", &password);

    test(password, 322424845);

    return 0;
}
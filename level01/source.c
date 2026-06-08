#include <stdio.h>
#include <string.h>

char username[100];

int verify_username(void)
{
    puts("verifying username....\n");
    return memcmp(username, "dat_wil", 7) != 0;
}

int verify_password(const char *password)
{
    return memcmp(password, "admin", 5) != 0;
}

int main(void)
{
    char password[64] = {0};
    int invalid = 0;

    puts("********* ADMIN LOGIN PROMPT *********");

    printf("Enter Username: ");
    fgets(username, 256, stdin);

    invalid = verify_username();

    if (invalid)
    {
        puts("nope, incorrect username...\n");
    }
    else
    {
        puts("Enter Password: ");
        fgets(password, 100, stdin); // vulnerable buffer overflow

        invalid = verify_password(password);

        puts("nope, incorrect password...\n");
    }

    return 1;
}
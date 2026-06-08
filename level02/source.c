#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char username[96];
    char password[96];
    char stored_password[48];

    FILE *fp;
    int bytes_read;

    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
    memset(stored_password, 0, 41);

    fp = fopen("/home/users/level03/.pass", "r");
    if (!fp)
    {
        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
    }

    bytes_read = fread(stored_password, 1, 41, fp);
    stored_password[strcspn(stored_password, "\n")] = '\0';

    if (bytes_read != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);

        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);

        exit(1);
    }

    fclose(fp);

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");

    printf("--[ Username: ");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("--[ Password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';

    puts("*****************************************");

    if (strncmp(stored_password, password, 41))
    {
        printf(username);   // vulnerable format string
        puts(" does not have access!");
        exit(1);
    }

    printf("Greetings, %s!\n", username);

    system("/bin/sh");

    return 0;
}
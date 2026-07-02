#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void secret_backdoor(void)
{
    char command[128];

    fgets(command, sizeof(command), stdin);
    system(command);
}

void set_username(char *data)
{
    char username[128];
    int i;

    memset(username, 0, sizeof(username));

    puts(">: Enter your username");
    printf(">>: ");

    fgets(username, sizeof(username), stdin);

    for (i = 0; i <= 40 && username[i] != '\0'; i++)
    {
        data[140 + i] = username[i];
    }

    printf(">: Welcome, %s", data + 140);
}

void set_msg(char *data)
{
    char message[1024];

    memset(message, 0, sizeof(message));

    puts(">: Msg @Unix-Dude");
    printf(">>: ");

    fgets(message, sizeof(message), stdin);
    printf("%d\n", *(int *)(data + 180));
    strncpy(data, message, *(int *)(data + 180));
}

void handle_msg(void)
{
    struct
    {
        char msg[140];
        char username[40];
        int msg_len;
    } user_data;

    memset(&user_data, 0, sizeof(user_data));

    user_data.msg_len = 140;

    set_username((char *)&user_data);
    set_msg((char *)&user_data);

    puts(">: Msg sent!");
}

int main(void)
{
    puts(
        "--------------------------------------------\n"
        "|   ~Welcome to l33t-m$n ~    v1337        |\n"
        "--------------------------------------------"
    );

    handle_msg();

    return 0;
}
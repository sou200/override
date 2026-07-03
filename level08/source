#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void log_wrapper(FILE *logfile, const char *message, const char *user_input)
{
    char buffer[264];

    strcpy(buffer, message);

    snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), user_input);

    buffer[strcspn(buffer, "\n")] = '\0';

    fprintf(logfile, "LOG: %s\n", buffer);
}

int main(int argc, char *argv[])
{
    FILE *log_file;
    FILE *source_file;

    int backup_fd;
    char c;
    char backup_path[104];

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    log_file = fopen("./backups/.log", "w");

    if (!log_file)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }

    log_wrapper(log_file, "Starting back up: ", argv[1]);

    source_file = fopen(argv[1], "r");

    if (!source_file)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    strcpy(backup_path, "./backups/");

    strncat(backup_path, argv[1], sizeof(backup_path) - strlen(backup_path) - 1);

    backup_fd = open(backup_path, O_WRONLY | O_CREAT | O_APPEND, 0660);

    if (backup_fd < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]
        );

        exit(1);
    }

    while ((c = fgetc(source_file)) != EOF)
    {
        write(backup_fd, &c, 1);
    }

    log_wrapper(log_file,"Finished back up ",argv[1]);

    fclose(source_file);

    fclose(log_file);

    close(backup_fd);

    return 0;
}
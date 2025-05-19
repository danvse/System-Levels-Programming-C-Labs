#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_NUM_LEN 10

void create_data_file(const char *filename) {
    FILE *file = fopen(filename, "w");

    for (int i = 32; i <= 126; ++i) {
        fprintf(file, "%d\n", i); 
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    const char *filename = argv[1];

    create_data_file(filename);

    int fd = open(filename, O_RDONLY);

    char ch;
    char num_buffer[MAX_NUM_LEN];
    int index = 0;
    ssize_t bytes_read;

    while ((bytes_read = read(fd, &ch, 1)) > 0) {
        if (ch >= '0' && ch <= '9') {
            if (index < MAX_NUM_LEN - 1) {
                num_buffer[index++] = ch;
            }
        } else if (ch == '\n' || ch == ' ') {
            if (index > 0) {
                num_buffer[index] = '\0'; 
                int num = atoi(num_buffer);  
                char num_str[16];
                int length = snprintf(num_str, sizeof(num_str), "%d", num);  
                write(STDOUT_FILENO, num_str, length); 

                if (num >= 32 && num <= 126) {
                    char output[4] = " ";
                    output[1] = (char)num;
                    output[2] = '\n';
                    output[3] = '\0';
                    write(STDOUT_FILENO, output, strlen(output));
                } else {
                    write(STDOUT_FILENO, "\n", 1);
                }

                index = 0;
            }
        }
    }

    close(fd);
    return 0;
}


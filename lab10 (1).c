#include <stdio.h>
#include <string.h>

void StringCompare(char str[], const char* str1, const char* str2) {
    char temp[1024];
    int i = 0, j = 0;
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);

    while (str[i] != '\0') {
        if (strncmp(&str[i], str1, str1Len) == 0) {
            strcpy(&temp[j], str2);
            j += str2Len;
            i += str1Len;
        } else {
            temp[j] = str[i];
            i++;
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char str[1024], str1[100], str2[100];

    printf("Enter the string: ");
    scanf("%[^\n]", str);
    getchar();

    printf("Enter the string to replace: ");
    scanf("%[^\n]", str1);
    getchar();

    printf("Enter the string to replace with: ");
    scanf("%[^\n]", str2);

    printf("-----------------------\n");
    printf("%s\n", str);
    StringCompare(str, str1, str2);
    printf("%s\n", str);

    return 0;
}


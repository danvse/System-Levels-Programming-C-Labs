#include <stdio.h>
#include <string.h>

#define length 21 

int main() {
//initialize the strings
    char word[length];
    char smallest[length]; 
    char largest[length]; 
//user input
    printf("Enter word: ");
    scanf("%20s", word);
//comparing the strings based on ascii value
    strcpy(smallest, word);
    strcpy(largest, word);
//creates a loop to repeat asking for word input if the user input is not 4 characters, and if it is 4 characters, it exits the loop
    while (strlen(word) != 4) {
        printf("Enter word: ");
        scanf("%20s", word);

        if (strlen(word) == 4) {
            break;
        }
//compares the current inputted word with the word that we store previous in the first iteration, and take the smaller word based on ascii value of the character. Same logic for largest.
        if (strcmp(word, smallest) < 0) {
            strcpy(smallest, word);
        }

        if (strcmp(word, largest) > 0) {
            strcpy(largest, word);
        }
    }
//results
    printf("\nSmallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}


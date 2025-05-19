#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int myarray[10]; 
    
    printf("Enter ten integers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &myarray[i]);
    }

    for (int i = 0; i < 100; i++) {
        int random_number = rand() % 10; 
        myarray[random_number]++;
    }

    printf("Updated Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");

    return 0;
}


#include <stdio.h>

// reverse using pointers
void reverse(int arr[], int *beg, int *end) {
    while (beg < end) {
        //store our value into a temporay variable to perform a swap  between pointer 1 and pointer 2
        int temp = *beg;
        *beg = *end;
        *end = temp;
        beg++;
        end--;
    }
}


void rotateRight(int arr[], int n, int k) {
   //this is the actual reverse functions we k is our range end
   //n is our array size  
    k = k % n; // find the remainder value for when range end modulus array size. this is predefines our the size of elements being reversed 

    reverse(arr, &arr[0], &arr[n-1]); // reverses first element

    reverse(arr, &arr[0], &arr[k-1]); //reverse second element

    reverse(arr, &arr[k], &arr[n-1]); //reverse the rest of rnage
}
//our inputs for user for array size, elements of array and reverse steps from range(0,user_inputed)
int main() {
    int n, k;
    
    printf("Array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Given array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("How many steps?: ");
    scanf("%d", &k);

    rotateRight(arr, n, k);
//prints out each element of our rotated array
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


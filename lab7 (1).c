#include <stdio.h>

void f(int a[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

int main() {
    int n;
    printf("How many integers: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    int a[n];
    for (int i = 0; i < n; i++) {
	scanf("%d", &a[i]);
    }
    f(a, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
	printf("%d ", a[i]);
    }
    return 0;
}


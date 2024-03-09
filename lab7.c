#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    int totalSwaps = 0;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[j]++;
                swaps[j + 1]++;
                temp = swaps[j];
                swaps[j] = swaps[j + 1];
                swaps[j + 1] = temp;
                totalSwaps++;
            }
        }
    }
    printf("The total number of swaps: %d\n", totalSwaps);
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    int totalSwaps = 0;

    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            swaps[i] = 1;
            totalSwaps++;
        } else {
            swaps[i] = 0;
        }
    }
    printf("The total number of swaps: %d\n", totalSwaps);
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int swaps_bubble1[n], swaps_bubble2[n];
    int swaps_selection[n];

    printf("Array 1 with Bubble Sorting\n");
    bubbleSort(arr1, n, swaps_bubble1);
    
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", arr1[i], swaps_bubble1[i]);
    printf("\n");

    int arr2[] = {90,80,70,60,50,40,30,20,10};
    bubbleSort(arr2, n, swaps_bubble2);

    for (int i = 0; i < n; i++)
        printf("%d: %d\n", arr2[i], swaps_bubble2[i]);
    printf("\n");
    
    return 0;   
}
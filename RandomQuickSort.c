#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot at end
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized partition
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    // Swap random element with last element (pivot)
    swap(&arr[randomIndex], &arr[high]);

    return partition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Seed random number generator
    srand(time(0));

    // Measure CPU time
    clock_t start, end;
    double cpu_time;

    start = clock();

    randomizedQuickSort(arr, 0, n - 1);

    end = clock();

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCPU Execution Time: %f seconds\n", cpu_time);

    return 0;
}
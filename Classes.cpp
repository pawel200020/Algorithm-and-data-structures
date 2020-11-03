#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Classes.h"

void HEAP_SORT_CLASS::heapify(int *array, int size, int i) {
    int largest = i;
    int left_i = 2 * i + 1;
    int right_i = 2 * i + 2;

    if (left_i < size && array[left_i] > array[largest]) {
        largest = left_i;
    }
    if (right_i < size && array[right_i] > array[largest]) {
        largest = right_i;
    }
    if (largest != i) {
        std::swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}


void HEAP_SORT_CLASS::bulid_heap(int size, int *array) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}


void HEAP_SORT_CLASS::heapSort(int *array, int size) {
    bulid_heap(size, array);
    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}


void MERGE_SORT_CLASS::merge(int arr[], int left, int divide, int right) {
    int array1size = divide - left + 1;
    int array2size = right - divide;
    int *Left = new int[array1size];
    int *Right = new int[array2size];

    for (int i = 0; i < array1size; i++)
        Left[i] = arr[left + i];
    for (int i = 0; i < array2size; i++)
        Right[i] = arr[divide + 1 + i];

    int firstbegin = 0;

    int secbegin = 0;

    int k = left;

    while (firstbegin < array1size && secbegin < array2size) {
        if (Left[firstbegin] <= Right[secbegin]) {
            arr[k] = Left[firstbegin];
            firstbegin++;
        } else {
            arr[k] = Right[secbegin];
            secbegin++;
        }
        k++;
    }

    while (firstbegin < array1size) {
        arr[k] = Left[firstbegin];
        firstbegin++;
        k++;
    }
    while (secbegin < array2size) {
        arr[k] = Right[secbegin];
        secbegin++;
        k++;
    }
    delete[] Left;
    delete[] Right;
}


void MERGE_SORT_CLASS::mergeSort(int *array, int left, int right) {
    if (left < right) {
        int divide = left + (right - left) / 2;
        mergeSort(array, left, divide);
        mergeSort(array, divide + 1, right);
        merge(array, left, divide, right);
    }
}


void INSERTION_SORT_CLASS::sort(int *array, int size) {
    for (int j = 1; j < size; j++) {
        int i = j - 1;
        int elem = array[j];
        while (i >= 0 && array[i] > elem) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = elem;
    }
}


TEST_CLASS::TEST_CLASS(int numberOfTests, int sizeOfArray) {
    this->numberOfTests = numberOfTests;
    this->sizeOfArray = sizeOfArray;
}


void TEST_CLASS::displayArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}

void TEST_CLASS::test(char algorithm) {
    srand(time(nullptr));
    int **HugeTestArray = new int *[numberOfTests];
    for (int i = 0; i < numberOfTests; i++) {
        HugeTestArray[i] = new int[sizeOfArray];
        for (int j = 0; j < sizeOfArray; j++) {
            HugeTestArray[i][j] = rand() % 100;
        }

    }
    switch (algorithm) {
        case 'h': {
            printf("Heap sort algortihm\n");
            HEAP_SORT_CLASS h1;
            for (int i = 0; i < numberOfTests; i++) {
                printf("Test id: %d \n", i);
                displayArray(HugeTestArray[i], sizeOfArray);
                h1.heapSort(HugeTestArray[i], sizeOfArray);
                displayArray(HugeTestArray[i], sizeOfArray);
                printf("\n");
            }
            case 'i': {
                printf("Insertion sort algortihm\n");
                INSERTION_SORT_CLASS i1;
                for (int i = 0; i < numberOfTests; i++) {
                    printf("Test id: %d \n", i);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    i1.sort(HugeTestArray[i], sizeOfArray);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    printf("\n");
                }
            }
            case 'm': {
                printf("Merge sort algortihm\n");
                MERGE_SORT_CLASS m1;
                for (int i = 0; i < numberOfTests; i++) {
                    printf("Test id: %d \n", i);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    m1.mergeSort(HugeTestArray[i], 0, sizeOfArray-1);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    printf("\n");
                }
            }
        }


    }

}




#ifndef INC_2020_10_13_HOMEWORK_CLASSES_H
#define INC_2020_10_13_HOMEWORK_CLASSES_H

class HEAP_SORT_CLASS {
    void heapify(int *, int, int);

    void bulid_heap(int, int *);

public:
    void heapSort(int *, int);
};

class MERGE_SORT_CLASS {
    void merge(int *, int, int, int);

public:
    void mergeSort(int *array, int left, int right);
};

class INSERTION_SORT_CLASS {

public:
    void sort(int *, int);
};

class TEST_CLASS {
public:
    int numberOfTests;
    int sizeOfArray;

    TEST_CLASS(int numberOfTests, int sizeOfArray);

private:
    void displayArray(int *, int);

public:
    void test(char);

};

#endif

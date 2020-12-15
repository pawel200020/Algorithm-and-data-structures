#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Classes.h"

int HEAP_CLASS::findSon(int i, int which) {
    if (which == 0) {
        return 2 * i + 1;
    } else {
        return 2 * i + 2;
    }
}

int HEAP_CLASS::findParent(int a) {
    return (a - 1) / 2;
}

void HEAP_CLASS::heapify(int *array, int size, int i) {
    int largest = i;
    int left_i = findSon(i, 0);
    int right_i = findSon(i, 1);

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


void HEAP_CLASS::bulid_heap(int size, int *array) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}


void SORT_CLASS::heapSort(int *array, int size) {
    HEAP_CLASS *heap = new HEAP_CLASS;
    heap->bulid_heap(size, array);
    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heap->heapify(array, i, 0);
    }
    delete heap;

}


void SORT_CLASS::merge(int arr[], int left, int divide, int right) {
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


void SORT_CLASS::mergeSort(int *array, int left, int right) {
    if (left < right) {
        int divide = left + (right - left) / 2;
        mergeSort(array, left, divide);
        mergeSort(array, divide + 1, right);
        merge(array, left, divide, right);
    }
}


void SORT_CLASS::InsertionSort(int *array, int size) {
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

//////////////////
BST_TREE_CLASS::node *BST_TREE_CLASS::makeEmpty(BST_TREE_CLASS::node *t) {
    if (t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

BST_TREE_CLASS::node *BST_TREE_CLASS::insert(int x, node *t) {
    if (t == NULL) {
        t = new node;
        t->data = x;
        t->left = t->right = NULL;
    } else if (x < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);
    return t;
}

BST_TREE_CLASS::node *BST_TREE_CLASS::findMin(BST_TREE_CLASS::node *t) {
    if (t == NULL) { return NULL; }
    else if (t->left == NULL) { return t; }
    else { findMin(t->left); }
}

BST_TREE_CLASS::node *BST_TREE_CLASS::findMax(BST_TREE_CLASS::node *t) {
    if (t == NULL) { return NULL; }
    else if (t->right == NULL) { return t; }
    else { findMin(t->right); }
}

BST_TREE_CLASS::node *BST_TREE_CLASS::remove(int x, node *t) {
    node *temp;
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        t->left = remove(x, t->left);
    else if (x > t->data)
        t->right = remove(x, t->right);
    else if (t->left && t->right) {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    } else {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}
void BST_TREE_CLASS::inorder(node* t) {
    if(t == NULL)
        return;
    inorder(t->left);
    printf("%d%c", t->data," ");
    inorder(t->right);
}
BST_TREE_CLASS::node* BST_TREE_CLASS::find(node* t, int x) {
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        return find(t->left, x);
    else if(x > t->data)
        return find(t->right, x);
    else
        return t;
}
BST_TREE_CLASS::BST_TREE_CLASS() {
    root = NULL;
}

BST_TREE_CLASS::~BST_TREE_CLASS() {
    root = makeEmpty(root);
}

void BST_TREE_CLASS::insert(int x) {
    root = insert(x, root);
}

void  BST_TREE_CLASS::remove(int x) {
    root = remove(x, root);
}

void  BST_TREE_CLASS::display() {
    inorder(root);
    printf("\n");
}

void  BST_TREE_CLASS::search(int x) {
    root = find(root, x);
}
//////////////////

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
    SORT_CLASS *t1 = new SORT_CLASS;
    switch (algorithm) {
        case 'h': {
            printf("Heap sort algortihm\n");

            for (int i = 0; i < numberOfTests; i++) {
                printf("Test id: %d \n", i);
                displayArray(HugeTestArray[i], sizeOfArray);
                t1->heapSort(HugeTestArray[i], sizeOfArray);
                displayArray(HugeTestArray[i], sizeOfArray);
                printf("\n");
            }
            case 'i': {
                printf("Insertion sort algortihm\n");

                for (int i = 0; i < numberOfTests; i++) {
                    printf("Test id: %d \n", i);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    t1->InsertionSort(HugeTestArray[i], sizeOfArray);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    printf("\n");
                }
            }
            case 'm': {
                printf("Merge sort algortihm\n");
                for (int i = 0; i < numberOfTests; i++) {
                    printf("Test id: %d \n", i);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    t1->mergeSort(HugeTestArray[i], 0, sizeOfArray - 1);
                    displayArray(HugeTestArray[i], sizeOfArray);
                    printf("\n");
                }
            }
        }
    }
    delete t1;
    for (int i = 0; i < numberOfTests; i++) {
        delete[] HugeTestArray[i];
    }
    delete[] HugeTestArray;
}




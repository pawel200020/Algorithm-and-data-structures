#ifndef INC_2020_10_13_HOMEWORK_CLASSES_H
#define INC_2020_10_13_HOMEWORK_CLASSES_H

class HEAP_CLASS;

class TEST_CLASS;

class SORT_CLASS;

class HEAP_CLASS {
public:
    void heapify(int *, int, int);

    void bulid_heap(int, int *);

    int findParent(int a);

    int findSon(int, int);

};

class SORT_CLASS {

    void merge(int *, int, int, int);

public:
    void mergeSort(int *array, int left, int right);

    void InsertionSort(int *, int);

    void heapSort(int *, int);

};

class BST_TREE_CLASS {
    struct node {
        int data;
        node *left;
        node *right;
    };

    node *root;

    node *makeEmpty(node *t);

    node *insert(int x, node *t);

    node *findMin(node *t);

    node *findMax(node *t);

    node *remove(int x, node *t);

    void inorder(node *t);

    node *find(node *t, int x);

public:
    BST_TREE_CLASS();

    ~BST_TREE_CLASS();

    void insert(int x);

    void remove(int x);

    void display();

    void search(int x);
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

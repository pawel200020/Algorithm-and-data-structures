#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Classes.h"
#include <queue>

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

BST_TREE_CLASS::Node *BST_TREE_CLASS::makeEmpty(BST_TREE_CLASS::Node *t) {
    if (t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::insert(int x, Node *t) {
    if (t == NULL) {
        t = new Node;
        t->data = x;
        t->left = t->right = NULL;
    } else if (x < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);
    return t;
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::findMin(BST_TREE_CLASS::Node *t) {
    if (t == NULL) { return NULL; }
    else if (t->left == NULL) { return t; }
    else { findMin(t->left); }
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::findMax(BST_TREE_CLASS::Node *t) {
    if (t == NULL) { return NULL; }
    else if (t->right == NULL) { return t; }
    else { findMin(t->right); }
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::remove(int x, Node *t) {
    Node *temp;
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

void BST_TREE_CLASS::inorder(Node *t) {
    if (t == NULL)
        return;
    inorder(t->left);
    printf("%d%c", t->data, " ");
    inorder(t->right);
}
void BST_TREE_CLASS::preorder(BST_TREE_CLASS::Node *t){
    if (t == NULL)
        return;

    printf("%d%c", t->data, " ");
    preorder(t->left);
    preorder(t->right);
}
void BST_TREE_CLASS::postorder(BST_TREE_CLASS::Node *t){
    if (t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%d%c", t->data, " ");

}

BST_TREE_CLASS::Node *BST_TREE_CLASS::find(Node *t, int x) {
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x);
    else if (x > t->data)
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

void BST_TREE_CLASS::remove(int x) {
    root = remove(x, root);
}

void BST_TREE_CLASS::display() {
    inorder(root);
    printf("\n");
}

void BST_TREE_CLASS::search(int x) {
    root = find(root, x);
}

RED_BLACK_TREE_CLASS::RED_BLACK_TREE_CLASS() { root = NULL; }

RED_BLACK_TREE_CLASS::Node::Node(int data) {
    this->data = data;
    left = right = parent = NULL;
    this->color = RED;
}

void RED_BLACK_TREE_CLASS::rotateLeft(Node *&root, Node *&x) {
    Node *y = x->right;

    x->right = y->left;

    if (x->right != NULL)
        x->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;

    else if (x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RED_BLACK_TREE_CLASS::rotateRight(Node *&root, Node *&y) {
    Node *x = y->left;
    y->left = x->right;
    if (y->left != NULL) {
        y->left->parent = y;
    }
    x->parent = y->parent;
    if (y->parent = NULL) {
        root = x;
    } else if (y = y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->left = y;
    y->parent = x;
}

void RED_BLACK_TREE_CLASS::fixViolation(Node *&root, Node *&x) {
    Node *parent_x = NULL;
    Node *grand_parent_x = NULL;

    while ((x != root) && (x->color != BLACK) &&
           (x->parent->color == RED)) {

        parent_x = x->parent;
        grand_parent_x = x->parent->parent;

        if (parent_x == grand_parent_x->left) {

            Node *uncle_x = grand_parent_x->right;

            if (uncle_x != NULL && uncle_x->color == RED) {
                grand_parent_x->color = RED;
                parent_x->color = BLACK;
                uncle_x->color = BLACK;
                x = grand_parent_x;
            } else {
                if (x == parent_x->right) {
                    rotateLeft(root, parent_x);
                    x = parent_x;
                    parent_x = x->parent;
                }
                rotateRight(root, grand_parent_x);
                std::swap(parent_x->color, grand_parent_x->color);
                x = parent_x;
            }
        } else {
            Node *uncle_x = grand_parent_x->left;

            if ((uncle_x != NULL) && (uncle_x->color == RED)) {
                grand_parent_x->color = RED;
                parent_x->color = BLACK;
                uncle_x->color = BLACK;
                x = grand_parent_x;
            } else {
                if (x == parent_x->left) {
                    rotateRight(root, parent_x);
                    x = parent_x;
                    parent_x = x->parent;
                }
                rotateLeft(root, grand_parent_x);
                std::swap(parent_x->color,
                          grand_parent_x->color);
                x = parent_x;
            }
        }
    }
    root->color = BLACK;

}

RED_BLACK_TREE_CLASS::Node *BSTInsert(RED_BLACK_TREE_CLASS::Node *root, RED_BLACK_TREE_CLASS::Node *pt) {
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return pt;

    /* Otherwise, recur down the tree */
    if (pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

void RED_BLACK_TREE_CLASS::insert(const int &data) {
    Node *pt = new Node(data);
    root = BSTInsert(root, pt);
    fixViolation(root, pt);
}

/////////////////////////////////////////////////
int AVL_TREE_CLASS::max(int a, int b) {
    return (a > b) ? a : b;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    return x;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::leftRotate(Node *y) {
    Node *x = y->right;
    Node *T2 = x->right;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    return y;
}

int AVL_TREE_CLASS::getBalance(AVL_TREE_CLASS::Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::insert(Node *node, int key) {
    if (node == NULL) return (newNode(key));
    if (key < node->key) node->left = insert(node->left, key);
    else if (key >= node->key) node->right = insert(node->right, key);
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::minValueNode(Node *node) {
    Node *current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::deleteNode(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {

            Node *temp = minValueNode(root->right);
            root->key = temp->key;

            root->right = deleteNode(root->right,temp->key);
        }
    }

    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
/*
void AVL_TREE_CLASS::preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }}

*/



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
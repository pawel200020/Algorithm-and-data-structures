#include "Trees.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//////////////////////TREE///////////////////////////////////////
bool TREE::Node::isOnLeft() { return this == parent->left; }

TREE::Node *TREE::Node::uncle() {
    if (parent == NULL or parent->parent == NULL)
        return NULL;
    if (parent->isOnLeft()) return parent->parent->right;
    else return parent->parent->left;
}

TREE::Node *TREE::Node::sibling() {
    if (parent == NULL)
        return NULL;
    if (isOnLeft()) return parent->right;
    else return parent->left;
}

void TREE::Node::moveDown(Node *nParent) {
    if (parent != NULL) {
        if (isOnLeft()) {
            parent->left = nParent;
        } else {
            parent->right = nParent;
        }
    }
    nParent->parent = parent;
    parent = nParent;
}

bool TREE::Node::hasRedChild() {
    return (left != NULL and left->color == RED) or (right != NULL and right->color == RED);
}

void TREE::inorder(Node *t) {
    if (t == NULL)
        return;
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

void TREE::preorder(Node *t) {
    if (t == NULL)
        return;

    printf("%d ", t->data);
    preorder(t->left);
    preorder(t->right);
}

void TREE::postorder(Node *t) {
    if (t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->data);

}

TREE::Node::Node() {}

/////////////////////BST trees/////////////////////////////////////////////////////////
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
    else { return findMin(t->left); }
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::findMax(BST_TREE_CLASS::Node *t) {
    if (t == NULL) { return NULL; }
    else if (t->right == NULL) { return t; }
    else { return findMin(t->right); }
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

void BST_TREE_CLASS::display(char option) {
    if (option == 'i') { inorder(root); }
    else if (option == 'r') { preorder(root); }
    else if (option == 'o') { postorder(root); }
    else { printf("wrong char!\n"); }
    printf("\n");
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::search(int x) {
    Node *temp = find(root, x);
    return temp;
}

////////////////Red Black trees////////////////////////////////
RED_BLACK_TREE_CLASS2::Node::Node(int data) {
    this->data = data;
    parent = left = right = NULL;
    color = RED;
}

void RED_BLACK_TREE_CLASS2::rightRotate(Node *x) {

    // new parent will be node's left child
    Node *nParent = x->left;

    // update root if current node is root
    if (x == root)
        root = nParent;

    x->moveDown(nParent);

    // connect x with new parent's right element
    x->left = nParent->right;
    // connect new parent's right element with node
    // if it is not null
    if (nParent->right != NULL)
        nParent->right->parent = x;

    // connect new parent with x
    nParent->right = x;
}

void RED_BLACK_TREE_CLASS2::leftRotate(Node *x) {

    // new parent will be node's right child
    Node *nParent = x->right;

    // update root if current node is root
    if (x == root)
        root = nParent;

    x->moveDown(nParent);

    // connect x with new parent's left element
    x->right = nParent->left;
    // connect new parent's left element with node
    // if it is not null
    if (nParent->left != NULL)
        nParent->left->parent = x;

    // connect new parent with x
    nParent->left = x;
}

void RED_BLACK_TREE_CLASS2::swapColors(Node *x1, Node *x2) {
    Color temp;
    temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
}

void RED_BLACK_TREE_CLASS2::swapValues(Node *u, Node *v) {
    int temp;
    temp = u->data;
    u->data = v->data;
    v->data = temp;
}

void RED_BLACK_TREE_CLASS2::fixRedRed(Node *x) {
    if (x == root) {
        x->color = BLACK;
        return;
    }

    Node *parent = x->parent, *grandparent = parent->parent,
            *uncle = x->uncle();

    if (parent->color != BLACK) {
        if (uncle != NULL && uncle->color == RED) {
            parent->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            fixRedRed(grandparent);
        } else {
            if (parent->isOnLeft()) {
                if (x->isOnLeft()) {
                    swapColors(parent, grandparent);
                } else {
                    leftRotate(parent);
                    swapColors(x, grandparent);
                }
                rightRotate(grandparent);
            } else {
                if (x->isOnLeft()) {
                    rightRotate(parent);
                    swapColors(x, grandparent);
                } else {
                    swapColors(parent, grandparent);
                }

                leftRotate(grandparent);
            }
        }
    }
}

RED_BLACK_TREE_CLASS2::Node *RED_BLACK_TREE_CLASS2::successor(Node *x) {
    Node *temp = x;
    while (temp->left != NULL) temp = temp->left;
    return temp;
}

RED_BLACK_TREE_CLASS2::Node *RED_BLACK_TREE_CLASS2::BSTreplace(Node *x) {
    if (x->left != NULL and x->right != NULL) return successor(x->right);
    if (x->left == NULL and x->right == NULL) return NULL;
    if (x->left != NULL) return x->left;
    else return x->right;
}

void RED_BLACK_TREE_CLASS2::deleteNode(Node *v) {
    Node *u = BSTreplace(v);

    bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
    Node *parent = v->parent;

    if (u == NULL) {
        if (v == root) { root = NULL; }
        else {
            if (uvBlack) { fixDoubleBlack(v); }
            else { if (v->sibling() != NULL) v->sibling()->color = RED; }
            if (v->isOnLeft()) { parent->left = NULL; }
            else { parent->right = NULL; }
        }
        delete v;
        return;
    }

    if (v->left == NULL or v->right == NULL) {
        if (v == root) {
            v->data = u->data;
            v->left = v->right = NULL;
            delete u;
        } else {
            if (v->isOnLeft()) {
                parent->left = u;
            } else {
                parent->right = u;
            }
            delete v;
            u->parent = parent;
            if (uvBlack) {
                fixDoubleBlack(u);
            } else {
                u->color = BLACK;
            }
        }
        return;
    }
    swapValues(u, v);
    deleteNode(u);
}

void RED_BLACK_TREE_CLASS2::fixDoubleBlack(Node *x) {
    if (x == root) return;

    Node *sibling = x->sibling();
    Node *parent = x->parent;
    if (sibling == NULL) {
        fixDoubleBlack(parent);
    } else {
        if (sibling->color == RED) {
            parent->color = RED;
            sibling->color = BLACK;
            if (sibling->isOnLeft()) { rightRotate(parent); }
            else { leftRotate(parent); }
            fixDoubleBlack(x);
        } else {
            if (sibling->hasRedChild()) {
                if (sibling->left != NULL and sibling->left->color == RED) {
                    if (sibling->isOnLeft()) {
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        rightRotate(parent);
                    } else {
                        sibling->left->color = parent->color;
                        rightRotate(sibling);
                        leftRotate(parent);
                    }
                } else {
                    if (sibling->isOnLeft()) {
                        sibling->right->color = parent->color;
                        leftRotate(sibling);
                        rightRotate(parent);
                    } else {
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        leftRotate(parent);
                    }
                }
                parent->color = BLACK;
            } else {
                sibling->color = RED;
                if (parent->color == BLACK)
                    fixDoubleBlack(parent);
                else
                    parent->color = BLACK;
            }
        }
    }
}

void RED_BLACK_TREE_CLASS2::insert(int n) {
    Node *newNode = new Node(n);
    if (root == NULL) {
        newNode->color = BLACK;
        root = newNode;
    } else {
        Node *temp = search(n);

        if (temp->data == n) {
            return;
        }
        newNode->parent = temp;

        if (n < temp->data)
            temp->left = newNode;
        else
            temp->right = newNode;

        fixRedRed(newNode);
    }
}

RED_BLACK_TREE_CLASS2::Node *RED_BLACK_TREE_CLASS2::getRoot() { return root; }

RED_BLACK_TREE_CLASS2::Node *RED_BLACK_TREE_CLASS2::search(int n) {
    Node *temp = root;
    while (temp != NULL) {
        if (n < temp->data) {
            if (temp->left == NULL)
                break;
            else
                temp = temp->left;
        } else if (n == temp->data) {
            break;
        } else {
            if (temp->right == NULL)
                break;
            else
                temp = temp->right;
        }
    }

    return temp;
}

void RED_BLACK_TREE_CLASS2::remove(int n) {
    if (root == NULL)
        // Tree is empty
        return;

    Node *v = search(n), *u;

    if (v->data != n) {
        printf("No node found to delete with value: %d\n", n);
        return;
    }

    deleteNode(v);
}

void RED_BLACK_TREE_CLASS2::display(char option) {
    if (option == 'i') { inorder(root); }
    else if (option == 'r') { preorder(root); }
    else if (option == 'o') { postorder(root); }
    else { printf("wrong char!\n"); }
    printf("\n");
}

RED_BLACK_TREE_CLASS2::RED_BLACK_TREE_CLASS2() {
    root = NULL;
}

//////////////////AVL trees////////////////////////////
AVL_TREE_CLASS::Node *AVL_TREE_CLASS::newNode(int key) {
    Node *node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

int AVL_TREE_CLASS::max(int a, int b) {
    return (a > b) ? a : b;
}

int AVL_TREE_CLASS::height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

int AVL_TREE_CLASS::getBalance(AVL_TREE_CLASS::Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::insertroot(Node *node, int key) {
    if (node == NULL) return (newNode(key));
    if (key < node->data) node->left = insertroot(node->left, key);
    else if (key >= node->data) node->right = insertroot(node->right, key);
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::minValueNoderoot(Node *node) {
    Node *current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::removeroot(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = removeroot(root->left, key);
    else if (key > root->data) root->right = removeroot(root->right, key);
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

            Node *temp = minValueNoderoot(root->right);
            root->data = temp->data;

            root->right = removeroot(root->right, temp->data);
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

AVL_TREE_CLASS::AVL_TREE_CLASS() {
    root = NULL;
}

void AVL_TREE_CLASS::display(char option) {
    if (option == 'i') { inorder(root); }
    else if (option == 'r') { preorder(root); }
    else if (option == 'o') { postorder(root); }
    else { printf("wrong char!\n"); }
    printf("\n");
}

void AVL_TREE_CLASS::insert(int a) {
    root = insertroot(root, a);
}

void AVL_TREE_CLASS::remove(int a) {
    root = removeroot(root, a);
}
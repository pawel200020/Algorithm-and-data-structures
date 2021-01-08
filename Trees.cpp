#include "Trees.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//////////////////////TREE///////////////////////////////////////
bool TREE::Node::isOnLeft() { return this == parent->left; }

TREE::Node *TREE::Node::uncle() {
    if (parent == nullptr or parent->parent == nullptr)
        return nullptr;
    if (parent->isOnLeft()) return parent->parent->right;
    else return parent->parent->left;
}

TREE::Node *TREE::Node::sibling() {
    if (parent == nullptr)
        return nullptr;
    if (isOnLeft()) return parent->right;
    else return parent->left;
}

void TREE::Node::moveDown(Node *nParent) {
    if (parent != nullptr) {
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
    return (left != nullptr and left->color == RED) or (right != nullptr and right->color == RED);
}

void TREE::inorder(Node *t) {
    if (t == nullptr)
        return;
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

void TREE::preorder(Node *t) {
    if (t == nullptr)
        return;

    printf("%d ", t->data);
    preorder(t->left);
    preorder(t->right);
}

void TREE::postorder(Node *t) {
    if (t == nullptr)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->data);

}

TREE::Node::Node() {}

void TREE::display(char option) {
    if (option == 'i') { inorder(root); }
    else if (option == 'r') { preorder(root); }
    else if (option == 'o') { postorder(root); }
    else { printf("wrong char!\n"); }
    printf("\n");
}

TREE::Node *TREE::makeEmpty(BST_TREE_CLASS::Node *t) {
    if (t == nullptr)
        return nullptr;
    else {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return nullptr;
    }

}

TREE::Node *TREE::search(int n) {
    Node *temp = root;
    while (temp != nullptr) {
        if (n < temp->data) {
            if (temp->left == nullptr)
                break;
            else
                temp = temp->left;
        } else if (n == temp->data) {
            break;
        } else {
            if (temp->right == nullptr)
                break;
            else
                temp = temp->right;
        }
    }

    return temp;
}

/////////////////////BST trees///////////////////////////////////

BST_TREE_CLASS::Node *BST_TREE_CLASS::insert(int x, Node *t) {
    if (t == nullptr) {
        t = new Node;
        t->data = x;
        t->left = t->right = nullptr;
    } else if (x < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);
    return t;
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::findMin(BST_TREE_CLASS::Node *t) {
    if (t == nullptr) { return nullptr; }
    else if (t->left == nullptr) { return t; }
    else { return findMin(t->left); }
}

BST_TREE_CLASS::Node *BST_TREE_CLASS::remove(int x, Node *t) {
    Node *temp;
    if (t == nullptr)
        return nullptr;
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
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }

    return t;
}

BST_TREE_CLASS::BST_TREE_CLASS() {
    root = nullptr;
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

////////////////Red Black trees////////////////////////////////
RED_BLACK_TREE_CLASS2::Node::Node(int data) {
    this->data = data;
    parent = left = right = nullptr;
    color = RED;
}

void RED_BLACK_TREE_CLASS2::rightRotate(Node *x) {

    Node *newParent = x->left;

    if (x == root) root = newParent;

    x->moveDown(newParent);

    x->left = newParent->right;
    if (newParent->right != nullptr)
        newParent->right->parent = x;

    newParent->right = x;
}

void RED_BLACK_TREE_CLASS2::leftRotate(Node *x) {

    Node *newParent = x->right;

    if (x == root) root = newParent;

    x->moveDown(newParent);
    x->right = newParent->left;
    if (newParent->left != nullptr)
        newParent->left->parent = x;

    newParent->left = x;
}

void RED_BLACK_TREE_CLASS2::swapColors(Node *x1, Node *x2) {
    Color temp;
    temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
}

void RED_BLACK_TREE_CLASS2::swapValues(Node *x1, Node *x2) {
    int temp;
    temp = x1->data;
    x1->data = x2->data;
    x2->data = temp;
}

void RED_BLACK_TREE_CLASS2::fixRedRed(Node *x) {
    if (x == root) {
        x->color = BLACK;
        return;
    }

    Node *parent = x->parent;
    Node *grandparent = parent->parent;
    Node *uncle = x->uncle();

    if (parent->color != BLACK) {
        if (uncle != nullptr && uncle->color == RED) {
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
    while (temp->left != nullptr) temp = temp->left;
    return temp;
}

RED_BLACK_TREE_CLASS2::Node *RED_BLACK_TREE_CLASS2::BSTreplace(Node *x) {
    if (x->left != nullptr and x->right != nullptr) return successor(x->right);
    if (x->left == nullptr and x->right == nullptr) return nullptr;
    if (x->left != nullptr) return x->left;
    else return x->right;
}

void RED_BLACK_TREE_CLASS2::deleteNode(Node *v) {
    Node *u = BSTreplace(v);

    bool uvBlack = ((u == nullptr or u->color == BLACK) and (v->color == BLACK));
    Node *parent = v->parent;

    if (u == nullptr) {
        if (v == root) { root = nullptr; }
        else {
            if (uvBlack) { fixDoubleBlack(v); }
            else { if (v->sibling() != nullptr) v->sibling()->color = RED; }
            if (v->isOnLeft()) { parent->left = nullptr; }
            else { parent->right = nullptr; }
        }
        delete v;
        return;
    }

    if (v->left == nullptr or v->right == nullptr) {
        if (v == root) {
            v->data = u->data;
            v->left = v->right = nullptr;
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
    if (sibling == nullptr) {
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
                if (sibling->left != nullptr and sibling->left->color == RED) {
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
    if (root == nullptr) {
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

void RED_BLACK_TREE_CLASS2::remove(int n) {
    if (root == nullptr)
        // Tree is empty
        return;

    Node *v = search(n), *u;

    if (v->data != n) {
        printf("No node found to delete with value: %d\n", n);
        return;
    }

    deleteNode(v);
}

RED_BLACK_TREE_CLASS2::RED_BLACK_TREE_CLASS2() {
    root = nullptr;
}

RED_BLACK_TREE_CLASS2::~RED_BLACK_TREE_CLASS2() {
    root = makeEmpty(root);
}

//////////////////AVL trees////////////////////////////
AVL_TREE_CLASS::Node *AVL_TREE_CLASS::newNode(int key) {
    Node *node = new Node();
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
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

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int AVL_TREE_CLASS::max(int a, int b) {
    return (a > b) ? a : b;
}

int AVL_TREE_CLASS::height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

int AVL_TREE_CLASS::getBalance(AVL_TREE_CLASS::Node *N) {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::insert(Node *node, int key) {
    if (node == nullptr) return (newNode(key));
    if (key < node->data) node->left = insert(node->left, key);
    else if (key >= node->data) node->right = insert(node->right, key);
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

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::minValueNode(Node *node) {
    Node *current = node;
    while (current->left != nullptr) current = current->left;
    return current;
}

AVL_TREE_CLASS::Node *AVL_TREE_CLASS::remove(Node *root, int key) {
    if (root == nullptr) return root;
    if (key < root->data) root->left = remove(root->left, key);
    else if (key > root->data) root->right = remove(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            free(temp);
        } else {

            Node *temp = minValueNode(root->right);
            root->data = temp->data;

            root->right = remove(root->right, temp->data);
        }
    }

    if (root == nullptr)
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
    root = nullptr;
}

AVL_TREE_CLASS::~AVL_TREE_CLASS() {
    root = makeEmpty(root);
}

void AVL_TREE_CLASS::insert(int a) {
    root = insert(root, a);
}

void AVL_TREE_CLASS::remove(int a) {
    root = remove(root, a);
}
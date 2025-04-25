#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* right;
    Node* left;

    Node(int val) {
        value = val;
        right = NULL;
        left = NULL;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    Node* insertInBst(Node* current, int val) {
        if (current == NULL) {
            return new Node(val); // Create a new node when inserting the first element
        }

        if (val > current->value) {
            current->right = insertInBst(current->right, val);
        } else {
            current->left = insertInBst(current->left, val);
        }

        return current; // Return the updated node
    }

    void insert(int val) {
        root = insertInBst(root, val);
    }

    void printTree(Node* current, int level = 0) {
        if (current != NULL) {
            printTree(current->right, level + 1);
            for (int i = 0; i < level; i++) {
                cout << "    ";
            }
            cout << current->value << endl;
            printTree(current->left, level + 1);
        }
    }

    void printTree() {
        printTree(root);
    }


};

int main() {
    BinarySearchTree b1;

    b1.insert(2);
    b1.insert(1);
    b1.insert(5);
    b1.insert(4);
    b1.insert(45);
    b1.insert(6);
    b1.insert(8);
    b1.insert(6);
    b1.insert(4);
    b1.insert(77);
    b1.insert(47);
    b1.insert(44);
    b1.insert(488);
    b1.insert(46);
    b1.insert(455);

    b1.printTree();

    return 0;
}

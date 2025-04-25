#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
        void bfs(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        queue<Node *> Q;
        Q.push(root);
        Q.push(NULL);

        while (!Q.empty())
        {
            Node *temp = Q.front();
            Q.pop();

            if (temp == NULL)
            {
                cout << endl;
                if (!Q.empty())
                {
                    Q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left != NULL)
                {
                    Q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    Q.push(temp->right);
                }
            }
        }
    }

    Node *buildTree(Node *root, vector<int> &data, int &i)
    {
        root = new Node(data[i++]);

        if (data[i] == -1)
        {
            return nullptr;
        }

        cout << "Enter the data for left = " << endl;
        root->left = buildTree(root->left, data, i);

        cout << "Enter the data for right = " << endl;
        root->right = buildTree(root->right, data, i);

        return root;
    }

    void inorder(Node *root)
    {

        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << "_";
        inorder(root->right);
    }
};

int main()
{
    BinaryTree tree;
    Node *root;
    int i = 0;
    vector<int> data = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    // Populate tree with initial values
    tree.buildTree(root, data, i);
    tree.inorder(root);
    return 0;
}
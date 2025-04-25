#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data of the root = " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left = " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right = " << endl;
    root->right = buildTree(root->right);

    return root;
}

void bfs(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        node *temp = Q.front();
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

void inorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << "_";
    inorder(root->right);
}

void preorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << "_";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data;


}

int main()
{

    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    bfs(root);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}
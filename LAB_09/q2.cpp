#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node *left;
    Node *right;
    int height;
};

Node* newNode(int key) 
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 0;
    return node;
}

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int height(Node* N) 
{
    if (N == nullptr)
    {
        return -1;
    }
    return N->height;
}

int getBalanceFactor(Node* N) 
{
    if (N == nullptr)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node* rightRotate(Node* y) 
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) 
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) 
{
    if (node == nullptr)
    {
        return newNode(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}


int main()
{
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++) 
    {
        root = insert(root, arr[i]);
    }
    
    root = insert(root, 55);
    
    inorder(root);
    cout << endl << endl;
    cout << "Root Key: " << root->key << endl;
    cout << "Final Tree Height: " << height(root) << endl;
    return 0;
}
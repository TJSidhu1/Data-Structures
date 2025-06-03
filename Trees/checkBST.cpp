#include <climits>

class Node{
    int value;
    Node* left;
    Node* right;

    Node(int val)
    {
        value = val;
    }
};

bool isBST(Node* root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return helper(root, min, max);
}

bool helper(Node* root, int min, int max)
{
    
}
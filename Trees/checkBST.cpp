#include <climits>

class Node{

    public:
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
    if(root == nullptr)
       return true;

    else if( root->value > min && root->value < max)   
    {
       return (helper(root->left, min, root->value) && helper(root->right, root->value, max));
    }

    else
        return false;
}
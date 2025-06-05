#include <climits>
#include <iostream>
using namespace std;

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


bool isBST(Node* root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return helper(root, min, max);
}

bool isMirror(Node* root)
{
    if(root == nullptr)
       return true;

    Node* left = root->left;
    Node* right = root->right;

    if(left == right)
       return true;

    return false;   


}

int main()
{
    Node* root = new Node(5);
    Node* left1 = new Node(3);
    Node* right1 = new Node(7);
    Node* right2 = new Node(4);
    Node* left2 = new Node(6);

    root->left = left1;
    root->right = right1;
    right1->left = left2;
    left1->right = right2;

    cout << "The given tree is Binary search tree (Yes : 1/ No : 0) : "<< isBST(root) << endl;


}
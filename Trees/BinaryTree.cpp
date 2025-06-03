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
             left = nullptr;
             right = nullptr;
           }
    
};

     void in_order(Node* root)
     {
        if(root == nullptr)
           return;


        in_order(root->left);
        cout<< root->value << " " ;
        in_order(root->right);
     } 
     
     void pre_order(Node *root)
     {
        if(root == nullptr)
           return;

        cout << root->value;
        pre_order(root->left);
        pre_order(root->right);   
     }

     void post_order(Node* root)
     {
        if(root == nullptr)
           return;

        post_order(root->left);
        post_order(root->right);
        cout << root->value;   
     }

int main()
{
    Node *root = new Node(1);
    Node *l1 = new Node(2);
    Node *l2 = new Node(3);
    root->left = l1;
    root->right = l2;
    in_order(root);

    return 0;
}
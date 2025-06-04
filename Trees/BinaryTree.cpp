#include <iostream>
#include <queue>
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

     void bfs(Node* root)
     {
       if(root == nullptr)
          return;

       queue<Node*> q1; 
       q1.push(root);
       
       while(! q1.empty())
       {
         cout << q1.front()->value << " ";
         
         if(q1.front()->left != nullptr)
            q1.push(q1.front()->left);

         if(q1.front()->right != nullptr)   
            q1.push(q1.front()->right);
            
         q1.pop();
       }
     }

int main()
{
   //  Node *root = new Node(1);
   //  Node *l1 = new Node(2);
   //  Node *l2 = new Node(3);
   //  root->left = l1;
   //  root->right = l2;
   Node* root = new Node(5);
    Node* left1 = new Node(3);
    Node* right1 = new Node(7);
    Node* right2 = new Node(4);
    Node* left2 = new Node(6);

    root->left = left1;
    root->right = right1;
    right1->left = left2;
    left1->right = right2;
    in_order(root);
    cout << endl;
    cout << "BFS traversal output: " ;
    bfs(root);

    return 0;
}
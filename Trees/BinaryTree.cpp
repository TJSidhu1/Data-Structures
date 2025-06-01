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

int main()
{
    Node *root = new Node(1);
    Node *l1 = new Node(2);
    Node *l2 = new Node(3);
    root->left = l1;
    root->right = l2;

    return 0;
}
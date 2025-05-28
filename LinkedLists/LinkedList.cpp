#include <iostream>
using namespace std;
class Node
{
    public:

    int value;
    Node* next;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }

};

void print_head(Node* head)
{
    cout << "Head Node:" << head->value << endl;
}

void display(Node *head)
    {

        while(head != nullptr)
        {
            cout << head->value << " " ;
            head = head->next;
        }
        cout << endl;
    }

void printTail(Node* head)
{
    if(head == nullptr)
    {
        cout << "Linked List is empty" << endl;
    }

    else
    {
        while(head->next != nullptr)
        {
            head = head->next;
        }
       cout << "Tail node: " << head->value << endl; 
    }
}    

int main()
{
    Node *head = new Node(1);
    Node *l1 = new Node(2);
    Node *l2 = new Node(3);
    head->next = l1;
    l1->next = l2;
    display(head);
    print_head(head);
    printTail(head);
    return 0;
}
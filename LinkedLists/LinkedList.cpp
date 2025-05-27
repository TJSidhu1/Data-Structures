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

void display(Node *head)
    {

        while(head != nullptr)
        {
            cout << head->value << " " ;
            head = head->next;
        }
    }

int main()
{
    Node *head = new Node(1);
    display(head);
    return 0;
}
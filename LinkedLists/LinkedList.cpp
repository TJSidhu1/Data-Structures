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

void print_middle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->value << endl;
}

Node* ReverseList(Node* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    Node* newHead = nullptr;
    Node* next = head;

    while(next != nullptr)
    {
        next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

Node* remove_node(Node* head,int val)
{
    if(head == nullptr)
       return nullptr;
}

bool detect_cycle(Node *head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *l1 = new Node(2);
    Node *l2 = new Node(3);
    // l2->next = head;       // added this for creating a cycle in the list
    head->next = l1;
    l1->next = l2;
    display(head);
    print_head(head);
    printTail(head);
    print_middle(head);
    remove_node(head,2);
    display(ReverseList(head));
   cout << detect_cycle(head) << endl;
    return 0;
}
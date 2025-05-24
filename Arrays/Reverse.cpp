#include <vector>
#include <iostream>
using namespace std;


void reverse(vector<int> &arr)
{
    int i= 0;
    int j= arr.size() - 1;
    int temp = 0;

    while(i<j)
    {
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
         i++;
         j--;
    }
}

void display(vector<int> arr)
{
    for(int i=0; i< arr.size(); i++)
    {
        cout << arr[i] ;
    }
}

int main()
{
    vector<int> v;
    v = {1,2,3,4,5};
    cout << "Initial Array : " ;
    display(v);
    cout << endl;
    reverse(v);
    cout << "Array after reversing: ";
    display(v);
    cout << endl;
    return 0;
}
#include <string>
#include <queue>
#include <iostream>
using namespace std;

class Book{
    public:
    string name;
    int duration;


    Book(string Name, int Duration)
    {
        name = Name;
        duration = Duration;
    }
};




class Library{


  public:  

    vector<Book> collection;
    string bookName;
    int maxDuration = 0;


    void push(Book B)
    { 
       collection.push_back(B);
       if(B.duration > maxDuration)
       {
         maxDuration = B.duration;
         bookName = B.name;
       }
    }

};

int main()
{
    Book B1("ABC", 10);
    Book B2("Book2", 15);
    Book B3("Book3" , 20);
    Book B4("Book4" , 18);

    Library L;
    L.push(B1);
    L.push(B2);
    L.push(B3);
    L.push(B4);
    cout << "Book name: " << L.bookName << "   Book Duration: " << L.maxDuration << endl;
    return 0;
}


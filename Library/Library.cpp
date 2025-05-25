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

struct Comparator {
    bool operator()(const Book& A, const Book& B) const {
        return A.duration < B.duration; // This creates a min-heap based on duration
    }
};


class Library{

    priority_queue<Book, vector<Book>, Comparator> pq;


    public:
    void push(Book B)
    {
       pq.push(B);
    }

    Book find_shortest()
    {
       Book b = pq.top();
       pq.pop(); 
       return b;
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
    Book b = L.find_shortest();
    cout << "Book name: " << b.name << "   Book Duration: " << b.duration << endl;
    return 0;
}


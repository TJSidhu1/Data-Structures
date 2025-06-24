/*💼 Scenario: Hospital Emergency Room
Each patient is represented as a struct with:

name (string)

severity (int) — higher number = more severe

arrivalTime (int) — smaller number = earlier arrival

🎯 Priority Rules:
Higher severity patients come first.

If severity is equal, earlier arrival comes first.
Write a code to show which patients are processed according to the rules above.*/
#include <iostream>
#include <queue>
using namespace std;

struct Patient
{
   string name;
   int severity;
   int arrivalTime;
};

struct comp
{
    bool operator()(const Patient A, const Patient B)
    {
        if(A.severity == B.severity)
         {
            return A.arrivalTime > B.arrivalTime;
          }
       return A.severity < B.severity;
     }
};

int main()
{
  Patient A = {"A", 10, 8};
  Patient B = {"B", 9, 9};
  Patient C = {"C", 7, 7};
  Patient D = {"D", 9, 8}; 
  priority_queue<Patient, vector<Patient>, comp> PatientOrder;
  PatientOrder.push(A);
  PatientOrder.push(B);
  PatientOrder.push(C);
  PatientOrder.push(D);

  cout << "The order in which the patients are processed and treated are as below:"<< endl;
  while(!PatientOrder.empty())
   {
       auto top = PatientOrder.top();
       cout << top.name << endl;
       PatientOrder.pop();
    }
  
  return 0;
}

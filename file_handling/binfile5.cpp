#include <iostream>
#include <fstream>
using namespace std;

class Student
{
  char name[20];
  int roll;
  float marks;

public:
  void getdata()
  {
    cin >> name >> roll >> marks;
  }
  void display()
  {
    cout << name << '\t' << roll << '\t' << marks << endl;
  }
};
int main()
{

  Student s[10];
  ofstream fout("student.dat", ios::binary);
  cout << "Enter no. of students: ";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    s[i].getdata();
    fout.write(reinterpret_cast<char *>(&s), sizeof(Student));
  }
  fout.close();

  ifstream fin("student.dat", ios::binary);
  Student temp[10];
  for (int i = 0; i < n; i++)
  {
    fin.read(reinterpret_cast<char *>(&temp), sizeof(Student));
    s[i].display();
  }
  fin.close();

}
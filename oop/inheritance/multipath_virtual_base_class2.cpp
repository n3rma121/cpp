
#include<iostream>
 
using namespace std;
 
class student{
    protected:
        int stud_id;
        string name;

    public:
        void get_std_data(){
            cout << "\nEnter student id: ";
            cin >> stud_id;
            cout << "\nEnter name: ";
            cin >> name;
        }

        void show_std_data(){
            cout << "\nStudent ID: "<< stud_id;
            cout << "\nName: " << name;
        }
};

class internalExam : virtual public student{
    protected:
        int marks1, marks2, marks3;

    public:
        void getdata(){
            cout << "\nEnter internal marks in three subjects: ";
            cin >> marks1 >> marks2 >> marks3;
        }

        void showdata(){
            cout << "\nInternal Marks in Subject 1: " << marks1;
            cout << "\nInternal Marks in Subject 2: " << marks2;
            cout << "\nInternal Marks in Subject 3: " << marks3;
        }

        int totalInternalMarks(){
            return (marks1 + marks2 + marks3);
        }
};

class externalExam : virtual public student{
  protected:
        int marks1, marks2, marks3;

    public:
        void getdata(){
            cout << "Enter external marks in three subjects: ";
            cin >> marks1 >> marks2 >> marks3;
        }

        void showdata(){
            cout << "\nExternal Marks in Subject 1: " << marks1;
            cout << "\nExternal Marks in Subject 2: " << marks2;
            cout << "\nExternal Marks in Subject 3: " << marks3;
        }

        int totalExternalMarks(){
            return (marks1 + marks2 + marks3);
        }
};

class result : public internalExam , public externalExam{
    public:
        void getdata(){
            internalExam::getdata();
            externalExam::getdata();
        }
        
        void showdata(){
            internalExam::showdata();
            externalExam::showdata();
        }
        
        int TotalMarks(){
            return (totalInternalMarks() + totalExternalMarks());
        }

};
int main()
{
    result r;
    cout << "Enter the data for student" << endl;
    r.get_std_data();
    cout << "\nEnter marks" << endl;
    r.getdata();
    cout << "Data for student is: " << endl;
    r.showdata();
    cout << "\nTotal Marks = " << r.TotalMarks();
    return 0;
}


/*
    In this program student is a virtual base class, only one copy of the properties
    are inhertited to the class RESULT even the proterties from student are inherited to
    the RESUTL from two paths INTERNALEXAM and EXTERNALEXAM. When calling the member
    GETDATA() through the object of class the RESULT the compiler does not warn 
    about the ambiguity. But if we remove the keyword VIRTUAL  from the base class in the derived
    class INTERNALEXAM and EXTERNALEXAM declaration, then the same statment r.get_std_data(); 
    generates error becuase of duplicate set of getdata();
*/
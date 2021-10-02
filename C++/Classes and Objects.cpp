#include <iostream>
using namespace std;
class employee
{
private: //Private section starts
int empid;
float esalary;
public: //Public section starts
void display(void); //Prototype Declaration
}; //End of class
void employee :: display() //Function Definition Outside the Class
{
empid = 001;
esalary = 10000;
cout<<"Employee Id is : "<<empid<<endl;
cout<<"Employee Salary is : "<<esalary<<endl;
}
int main()
{
employee e; //Object Declaration
e.display(); //Calling to public member function
return 0;
}

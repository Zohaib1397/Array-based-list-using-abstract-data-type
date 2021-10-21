#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	string name;
	string reg_no;
	float gpa;
	Student() {}
	void operator = (Student const& obj) {
		name = obj.name;
		reg_no = obj.reg_no;
		gpa = obj.gpa;
	}
	void setname(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}
	void setreg_no(string reg_no)
	{
		this->reg_no = reg_no;
	}
	string getreg_no()
	{
		return reg_no;
	}
	void setgpa(float gpa)
	{
		this->gpa = gpa;
	}
	float getgpa()
	{
		return gpa;
	}
};
class List
{
public:
	Student* list;
	int length;
	int size;
	List(int size)
	{
		this->size = size;
		list = new Student[size];
		length = 0;
	}
	List operator =(List const& obj)
	{

		list = new Student[size];
		*list = *obj.list;
	}
	void isfull()
	{

		Student* temp;
		temp = new Student[size + 10];
		for (int i = 0; i < length; i++)
		{
			temp[i] = list[i];
		}
		delete[]list;
		list = temp;
		temp = NULL;
	}
	void addatend(Student x)
	{
		if (size == length)
		{
			isfull();
		}
		list[length] = x;
		length++;
	}
	void insertinbetween(Student x, int position)
	{
		if (size == length)
		{
			isfull();
		}
		for (int i = length; i > position; i--)
		{
			list[i] = list[i - 1];
		}
		list[position] = x;
		length++;

	}
	void deletion()
	{
	}
	void display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << "The name of student is " << list[i].name << endl;
			cout << "Registration of student is " << list[i].reg_no << endl;
			cout << "GPA of student is " << list[i].gpa << "\n\n";
		}
	}
};
int main()
{
	List l(1);
	Student s;
	Student St;
	Student STU;
	s.setname("Moiz Ahmed");
	s.setreg_no("BSE203146");
	s.setgpa(3.84f);
	l.addatend(s);
	St.setname("Zohaib");
	St.setreg_no("BSE203017");
	St.setgpa(3.87f);
	l.addatend(St);
	STU.setname("Mohammad Zain");
	STU.setgpa(2.96f);
	STU.setreg_no("BSE203147");
	l.insertinbetween(STU, 1);
	l.display();

}

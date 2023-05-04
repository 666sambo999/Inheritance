#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name,first_name,age
class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name; 
	}
	unsigned int get_age()const
	{
		return age; 
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name; 
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
			// Constructor 
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "Constructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDectructor:\t" << this << endl; 
	}
	void info()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o." << endl; 
	}
};
#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality,group, rating, attendance
class Student:public Human
{
	std::string speciality; 
	std::string group;
	double rating; // успеваймость
	double attendance; //посещаймость 
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group; 
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	// Constructor
	Student (HUMAN_TAKE_PARAMETRS,STUDENT_TAKE_PARAMETRS):Human(HUMAN_GIVE_PARAMETRS)
	/*(const std::string& last_name, const std::string first_name, unsigned int age,
	const std::string& speciality, const std::string& group, double rating, double attendance)*/
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl; 
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl; 
	}
	void info()const
	{
		Human::info();
		cout << speciality << " " << group << " " << " rating:" << rating << ", attendance:" << attendance << endl;
	}
};
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
				// Constructor 
	Teacher (HUMAN_TAKE_PARAMETRS,TEACHER_TAKE_PARAMETRS):Human(HUMAN_GIVE_PARAMETRS)
	/*(const std::string& last_name, const std::string first_name, unsigned int age,
	const std::string& speciality, unsigned int experience)*/ 
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl; 
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl; 
	}
	// Методы 
	void info()const
	{
		Human::info();
		cout << speciality << ", experience:" << experience << " years\n";
	}
};

class Graduate:public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return  subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const std::string& subject)
		:Student (HUMAN_GIVE_PARAMETRS,STUDENT_GIVE_PARAMETRS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl; 
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl; 
	}
	
	void info()const
	{
		Student::info();
		cout << "subject: " << subject << endl; 
	}

};

void main()
{
	setlocale(LC_ALL, "");

	Human human("Тупенко", "Василий", 18);
	human.info();

	Student stud("Pincman", "Jessie", 25, "Chemistry", "WW220", 95, 99);
	stud.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	teacher.info();

	Graduate grad("Bloom", "Orlando", 24, "Criminalistic", "OBN", 90, 80, "Сatch the criminal");
	grad.info();

}
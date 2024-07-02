#ifndef STUDENTS_H
#define STUDENTS_H
#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>

class Student; 
int compare_by_name(const Student&, const Student&);
int compare_by_grade(const Student&, const Student&);
int compare_by_surname(const Student&, const Student&);
// namespace Comp
// {
//     int (**f) (int) = malloc(Constants::AmountOfFunctionsCompareStud*sizeof( int(*)(const Student&, const Stident&) )  )
// } // namespace Comp


//int (*functions_pointers[])() = {compare_by_name, compare_by_surname, compare_by_grade };

class Studentscomparator
{ 
    int (*function_of_compare)(const Student& , const Student&);
public:
    Studentscomparator(int (*const f)(const Student&, const Student&) ) : function_of_compare(f){}
    bool operator()(const Student& stud1, const Student& stud2)
    {
        return function_of_compare(stud1, stud2);
    }
};


class Student
{
private:
    std::string name {""}; 
    std::string surname {""}; 
    int grade {0}; 
    std::string profile {""};
    Studentscomparator comparator{nullptr};
public:
    
    Student(){}
    Student(const std::string& name, const std::string& surname,
     int grade, const std::string& profile, int(*const func)(const Student&, const Student&)) : name(name), surname(surname),
      grade(grade), profile(profile), comparator(func) {} 
    void changeName(const std::string& new_name)
    {
        name = new_name;
    }
    void changeSurname(const std::string& new_surname)
    {
        surname = new_surname;
    }
    void changeGrade(int new_grade)
    {
        grade = new_grade;
    }
    void changeProfile(const std::string& new_profile)
    {
        profile = new_profile;
    }
    std::string GetName() const
    {
        return name;
    }
    std::string GetSurname() const
    {
        return surname;
    }
    int GetGrade() const
    {
        return grade;
    }
    std::string GetProfile() const
    {
        return profile;
    }
    friend int compare_by_name(const Student& stud1, const Student& stud2); 
    friend int compare_by_grade(const Student& stud1, const Student& stud2);
    friend int compare_by_name(const Student& stud1, const Student& stud2);

    friend std::ostream& operator <<(std::ostream& out_stream, const Student& student )
    {
        out_stream << "Name: " << student.GetName() << ", Surname: "
         << student.GetSurname() << ", Grade: " << student.GetGrade() 
         << ", Profile: " << student.GetProfile(); 
        return out_stream;
    }
    bool operator==(const Student& student) const 
    {
        if(this->GetName()!= student.GetName()) return false; 
        if(this->GetSurname() != student.GetSurname()) return false; 
        if(this->GetGrade() != student.GetGrade()) return false; 
        if(this->GetProfile() != student.GetProfile()) return false; 
        return true;
    }
    bool operator !=(const Student& student) const
    {
        return !(*(this)==student); 
    }
    bool operator <(const Student& student) const
    {
        bool answer; 
        if (surname < student.surname) answer = true;
        else if (surname > student.surname) answer = false;
        else if (name < student.name) answer = true;
        else if (name > student.name) answer = false;
        else if (profile < student.profile) answer = true;
        else if (profile > student.profile) answer = false;
        else if (grade < student.grade) answer = true; 
        else if (grade > student.grade) answer = false;
        return answer;
    }
    bool operator >(const Student& student) const 
    {
        return !(*(this) < student);
    }
    
};
    int compare_by_name(const Student& stud1, const Student& stud2)
    {
        return {stud1.GetName() > stud2.GetName() ? 1 : 0}; 
    }

    int compare_by_grade(const Student& stud1, const Student& stud2)
    {
        return {stud1.GetGrade() > stud2.GetGrade() ? 1 : 0}; 
    }

    int compare_by_surname(const Student& stud1, const Student& stud2)
    {
        return {stud1.GetSurname() > stud2.GetSurname()? 1 : 0}; 
    }
#endif /* STUDENTS_H */
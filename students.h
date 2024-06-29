#ifndef STUDENTS_H
#define STUDENTS_H
#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>
class Student
{
private:
    std::string name {""}; 
    std::string surname {""}; 
    int grade {0}; 
    std::string profile {""};
public:
    
    Student(){}
    Student(const std::string& name, const std::string& surname,
     int grade, const std::string& profile) : name(name), surname(surname),
      grade(grade), profile(profile) {} 
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
#endif /* STUDENTS_H */
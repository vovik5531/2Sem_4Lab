#ifndef MENUFORSETS_H
#define MENUFORSETS_H
#include <iostream>
#include <limits>
#include <sstream>
#include "Set.h"
#include "students.h"

class MenuForSets
{
private:
    BinTree<Student>& tree; 
    Student student; 
    Student another_student;
public:
    
    explicit MenuForSets(BinTree<Student>& tree) : tree(tree) {}
    void run()
    {
        int choice;
        do{
            printMenuSets();
            choice = safeInputInteger("Выбирете действие:");
            processChoice(choice);

        }while(choice != 0);
    }
    private:
    void printMenuSets() const
    {
        std::cout << "\n         МЕНЮ      \n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Удалить студента\n";
        std::cout << "3. Проверить наличие студента\n";
        std::cout << "4. Вывести список студентов\n";
        std::cout << "5. Ввести нескольких студентов\n";
        std::cout << "6. Объединить с другим деревом\n";
        std::cout << "7. Удалить студентов из другого дерева\n";
        std::cout << "8. Сравнить с другим деревом\n";
        std::cout << "9. Проверить, является ли поддеревом\n";
        std::cout << "0. Выход\n";
    }
    void processChoice(int choice)
    {
        switch (choice)
        {
        case 1:
            addStudent(); 
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            checkStudent(); 
            break;
        case 4:
            printStudents();
            break;
        case 5:
            inputStudents(); 
            break;
        case 6:
            mergeWithAnotherTree();
            break;
        case 7:
            deleteStudentsFromAnotherTree();
            break;
        case 8: 
            compareWithAnotherTree();
            break; 
        case 9:
            checkIsSubTree(); 
            break; 
        
        default:
            break;
        }
    }
    void addStudent()
    {
        std::string new_name, new_surname, new_profile;
        int new_grade; 
        std::cout << "Введите имя: ";
        std::cin >> new_name;
        std::cout << "\n";
        std::cout << "Введите фамилию: ";
        std::cin >> new_surname;
        std::cout << "\n";
        new_grade = safeInputInteger("Введите класс: ");
        std::cout << "\n";
        std::cout << "Введите профиль: ";
        std::cin >> new_profile;
        student.changeName(new_name);
        student.changeSurname(new_surname);
        student.changeProfile(new_profile);
        student.changeGrade(new_grade);
        tree.insert(student);
        std::cout << "Студент добавлен!\n";
    }
    void removeStudent()
    {
        std::string name_to_delete, surname_to_delete;
        std::cout << "Введите имя: ";
        std::cin >> name_to_delete;
        std::cout << "Введите фамилию: ";
        std::cin >> surname_to_delete;
        student.changeName(name_to_delete);
        student.changeSurname(surname_to_delete);
        tree.remove(student);
        std::cout << "Студент удален!\n";
    }
    void checkStudent()
    {
        std::string name_to_check, surname_to_check;
        std::cout << "Введите имя: ";
        std::cin >> name_to_check;
        std::cout << "Введите фамилию: ";
        std::cin >> surname_to_check;
        student.changeName(name_to_check);
        student.changeSurname(surname_to_check);
        if (tree.contains(student))
        {
            std::cout <<std::endl << "Студент найден!\n";
        }
        else 
        {
            std::cout << std::endl << "Студент не найден!\n";
        }
    }
    void printStudents()
    {
        std::cout << "Список студентов:\n";
        tree.print();
    }
    void inputStudents()
    {
        int number_of_students;
        std::cout << "Введите число студентов: ";
        std::cin >> number_of_students; 
        for (int i=0; i< number_of_students; ++i)
        {
            std::string new_name, new_surname, new_profile;
            int new_grade; 
            std::cout << "Введите имя: ";
            std::cin >> new_name;
            std::cout << "Введите фамилию: ";
            std::cin >> new_surname;
            new_grade = safeInputInteger("Введите класс: ");
            std::cout << "Введите профиль: ";
            std::cin >> new_profile;
            student.changeName(new_name);
            student.changeSurname(new_surname);
            student.changeProfile(new_profile);
            student.changeGrade(new_grade);
            tree.insert(student);
            std::cout << "Студент добавлен!\n";
        }
        std::cout << "Студенты добавлены!\n";
    }
    void mergeWithAnotherTree() 
    {
        BinTree<Student> tree2;
        std::string new_name, new_surname, new_profile;
        int new_grade; 
        std::cout << "Введите имя: ";
        std::cin >> new_name;
        std::cout << "Введите фамилию: ";
        std::cin >> new_surname;
        new_grade = safeInputInteger("Введите класс: ");
        std::cout << "Введите профиль: ";
        std::cin >> new_profile;
        another_student.changeName(new_name);
        another_student.changeSurname(new_surname);
        another_student.changeProfile(new_profile);
        another_student.changeGrade(new_grade);
        tree2.insert(another_student);
        std::cout << "Студент добавлен!\n";

        tree = tree+tree2;
        std::cout<< "Деревья объединены!\n";   
    }
    void deleteStudentsFromAnotherTree()
    {
        BinTree<Student> another_tree;
        std::string new_name, new_surname, new_profile;
        int new_grade;  
        std::cout << "Введите имя: ";
        std::cin >> new_name;
        std::cout << "Введите фамилию: ";
        std::cin >> new_surname;
        new_grade = safeInputInteger("Введите класс: ");
        std::cout << "Введите профиль: ";
        std::cin >> new_profile;
        another_student.changeName(new_name);
        another_student.changeSurname(new_surname);
        another_student.changeProfile(new_profile);
        another_student.changeGrade(new_grade);
        another_tree.insert(another_student);
        tree = tree - another_tree; //удаляем из дерева another_tree с another_student
        std::cout << "Студент удален!\n";

    }
    void compareWithAnotherTree()
    {
        BinTree<Student> another_tree; 
        std::string new_name, new_surname, new_profile;
        [[maybe_unused]]int new_grade;
        std::cout << "Введите имя: ";
        std::cin >> new_name;
        std::cout << "Введите фамилию: ";
        std::cin >> new_surname;
        new_grade = safeInputInteger("Введите класс: ");
        std::cout << "Введите профиль: ";
        std::cin >> new_profile;
        tree.insert(another_student);
        std::cout << "Студент добавлен!\n";

        if(tree == another_tree) 
        {
            std::cout << "Деревья равны!\n";
        }
        else 
        {
            std::cout << "Деревья различны!\n";
        }
    }
    void checkIsSubTree()
    {
        BinTree<Student> another_tree; 
        std::string new_name, new_surname, new_profile;
        [[maybe_unused]]int new_grade;
        std::cout << "Введите имя: ";
        std::cin >> new_name;
        std::cout << "\n";
        std::cout << "Введите фамилию: ";
        std::cin >> new_surname;
        std::cout << "\n";
        new_grade = safeInputInteger("Введите класс: ");
        std::cout << "\n";
        std::cout << "Введите профиль: ";
        std::cin >> new_profile;
        another_tree.insert(another_student);
        
        if(tree.isSubTree(another_tree)) 
        {
            std::cout << "Другого дерево является поддеревом!\n";
        }
        else 
        {
            std::cout << "Другое дерево не поддерево первого!\n";
        }   
    }
    int safeInputInteger(const std::string& prompt)
    {
        int value;
        while(true)
        {
            std::cout<< prompt;
            std::cin>>value;
            if(std::cin.fail() || std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода! Введите число!\n";
                
            }
            else 
            {
                return value;
            }
        }
    }
};

#endif

//
// Created by crypt on 5/29/2016.
//

#ifndef CTCI_EMPLOYEE_H
#define CTCI_EMPLOYEE_H

#include <string>
#include <atomic>

class Employee {

    static atomic_int IdCounter;
private:
    string firstname;
    string lastname;
public:
    Employee(string firstname, string lastname);

    boolean isAvailable();

};

class Director : public Employee {


};

class Manager : public Employee {
    Director *director;

public:
    Director *getDirector();

    void setDirector(Director *director);

    void assignRespondent(Respondent *respondent);

    void removeRespondent(Respondent *respondent);
};

class Respondent : public Employee {
private:
    Manager *manager;
public:

public:

    Manager *getManager();

    void setManager(Manager *manager);
};

#endif //CTCI_EMPLOYEE_H

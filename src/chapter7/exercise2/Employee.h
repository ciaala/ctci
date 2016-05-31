//
// Created by crypt on 5/29/2016.
//

#ifndef CTCI_EMPLOYEE_H
#define CTCI_EMPLOYEE_H

#include <string>
#include <atomic>
#include "CallRank.h"

using namespace std;

class Employee;

class Respondent;

class Manager;

class Director;

class Employee {

    static atomic_int IdCounter;
private:
    string firstname;
    string lastname;
public:
    Employee(string firstname, string lastname);

    CallRank getRank();

    bool isAvailable();

};

class Director : public Employee {


public:
    Director(const string &firstname, const string &lastname) : Employee(firstname, lastname) { }
};

class Manager : public Employee {
    Director *director;

public:
    Manager(const string &firstname, const string &lastname) : Employee(firstname, lastname) { }

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

    Respondent(const string &firstname, const string &lastname) : Employee(firstname, lastname) { }

    Manager *getManager();

    void setManager(Manager *manager);
};

#endif //CTCI_EMPLOYEE_H

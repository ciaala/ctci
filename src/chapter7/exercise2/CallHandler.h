//
// Created by crypt on 5/29/2016.
//

#ifndef CTCI_CALLCENTER_H
#define CTCI_CALLCENTER_H

#include <vector>

#include "Employee.h"
#include "Caller.h"
#include "CallRank.h"

using namespace std;

template<typename E>
constexpr auto toUType(E enumerator);

class Call {
    Caller caller;
    CallRank rank;
public:
    Call(Caller caller);

    CallRank getRank();
};

class CallHandler {
private:
    vector<vector<Employee *>> employees;
public:
    CallHandler();

    void dispatchCall(Caller caller);
};


#endif //CTCI_CALLCENTER_H

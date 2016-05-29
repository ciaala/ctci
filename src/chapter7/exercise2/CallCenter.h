//
// Created by crypt on 5/29/2016.
//

#ifndef CTCI_CALLCENTER_H
#define CTCI_CALLCENTER_H

class Call {

};

class CallCenter {
    vector<Respondent *> respondents;
public:
    void dispatchCall(Call call);
};


#endif //CTCI_CALLCENTER_H

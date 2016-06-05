//
// Created by crypt on 6/5/2016.
//

#ifndef CTCI_ROTATINGSTACK_H
#define CTCI_ROTATINGSTACK_H


class RotatingStack {

private:
    int popIndex;
    int end;

    int (&array)[];
public:
    RotatingStack(int (&array)[]);

    int popPush(int value);

    void setCapacity(int capacity);
};


#endif //CTCI_ROTATINGSTACK_H

//
// Created by crypt on 5/29/2016.
//

#include "CallHandler.h"

template<typename E>
constexpr
auto toUType(E enumerator) {
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

void CallHandler::dispatchCall(Caller caller) {
    Call call(caller);
    size_t rank = toUType(call.getRank());

/*
    if ( this->employees.at(rank).size() > 0 ) {

    } ;
*/
}

Call::Call(Caller caller) : caller(caller) {

}

CallRank Call::getRank() {
    return this->rank;
}


CallHandler::CallHandler() : employees(toUType(CallRank::CALLRANK_NR_ITEMS)) {

}

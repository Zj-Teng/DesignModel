//
// Created by TeTng on 2023/10/31.
//

#include "iterator_model.h"

using namespace std;

Staff::Staff(const std::string &name, int age, const std::string &idcard) {
    name_ = name;
    id_card_ = idcard;
    age_ = age;
    next = nullptr;
}

Company::Company() {
    head_ = new Staff("", 0, "");
}

Company::~Company() {
    Staff *next = nullptr;
    while (head_ != nullptr) {
        next = head_->next;
        head_->next = nullptr;
        delete head_;
        head_ = next;
    }
    next = nullptr;
}

void Company::addStaff(const std::string &name, int age, const std::string &idcard) {
    Staff *p = head_;
    while (p->next != nullptr) p = p->next;

    p->next = new Staff(name, age, idcard);
}

Staff Company::first() {
    p_ = head_->next;

    return *p_;
}

Staff Company::next() {
    Staff s = *p_;
    p_ = p_->next;

    return s;
}

bool Company::isEnd() {
    if (p_ == nullptr) return true;

    return false;
}



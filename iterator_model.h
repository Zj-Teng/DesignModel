//
// Created by TeTng on 2023/10/31.
//

#ifndef DESIGN_MODEL_ITERATOR_MODEL_H
#define DESIGN_MODEL_ITERATOR_MODEL_H

#include "string"

class Staff {
public:
    std::string name_;
    std::string id_card_;
    int age_;
    Staff *next;

    explicit Staff(const std::string &name, int age, const std::string &idcard);
};

class Iterator {
public:
    virtual Staff first() = 0;

    virtual Staff next() = 0;

    virtual bool isEnd() = 0;
};

class Company : public Iterator {
public:
    Staff *head_ = nullptr;
    Staff *p_ = nullptr;

    explicit Company();

    ~Company();

    void addStaff(const std::string &name, int age, const std::string &idcard);

    Staff first() override;

    Staff next() override;

    bool isEnd() override;
};

#endif //DESIGN_MODEL_ITERATOR_MODEL_H

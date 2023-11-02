//
// Created by TeTng on 2023/10/29.
//

#ifndef DESIGN_MODEL_OBSERVER_MODEL_H
#define DESIGN_MODEL_OBSERVER_MODEL_H

#include "vector"

class Observer {
public:
    virtual void update() = 0;
};

class UserWallet {
public:
    void attach_observer(Observer *observer);

    void deposit(float p);

    void consume(float p);

    void notify();

    float getBalance();

    float balance_ = 0.;

    std::vector<Observer *> observer_vec_;
};

class UserMessageObserver : public Observer {
public:
    explicit UserMessageObserver(UserWallet *wallet);

    void update() override;

    UserWallet *wallet_ = nullptr;
};

#endif //DESIGN_MODEL_OBSERVER_MODEL_H

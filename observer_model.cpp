//
// Created by TeTng on 2023/10/29.
//

#include "observer_model.h"
#include "iostream"

using namespace std;

void UserMessageObserver::update() {
    cout << "UserMessageObserver::update()" << endl;
    if (wallet_->getBalance() <= 5.) {
        cout << "wallet_->getBalance() <= 5." << endl;
    }
}

UserMessageObserver::UserMessageObserver(UserWallet *wallet) {
    wallet_ = wallet;
    wallet->attach_observer(this);
}

void UserWallet::attach_observer(Observer *observer) {
    observer_vec_.push_back(observer);
}

void UserWallet::deposit(float p) {
    balance_ += p;
}

void UserWallet::consume(float p) {
    balance_ -= p;
    notify();
}

float UserWallet::getBalance() {
    return balance_;
}

void UserWallet::notify() {
    for (auto ob: observer_vec_) {
        ob->update();
    }
}

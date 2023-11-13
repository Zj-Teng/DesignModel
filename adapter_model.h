//
// Created by TeTng on 2023/11/8.
//

#ifndef DESIGN_MODEL_ADAPTER_MODEL_H
#define DESIGN_MODEL_ADAPTER_MODEL_H

#include "string"

class Profit {
public:
    virtual float getProfit();
};

class USDProfit {
public:
    float getUSDProfit(const std::string &app, const std::string &sec);
};

// 可以使用组合或者多继承的方式实现适配器
class USDAdapter : public Profit {
private:
    USDProfit usd_profit_;
public:
    float getProfit() override;
};

#endif //DESIGN_MODEL_ADAPTER_MODEL_H

//
// Created by TeTng on 2023/11/8.
//

#include "adapter_model.h"

float Profit::getProfit() {
    return 123.;
}

float USDProfit::getUSDProfit(const std::string &app, const std::string &sec) {
    return 321.;
}

float USDAdapter::getProfit() {
    float profit = usd_profit_.getUSDProfit("abc", "bcd");
    return profit;
}

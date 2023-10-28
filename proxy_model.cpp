//
// Created by TeTng on 2023/10/17.
//

#include "proxy_model.h"
#include "chrono"

using namespace std;

SystemInfo SysInfoGetterProxy::cache_;

SysInfoGetterProxy::SysInfoGetterProxy(SysInfoGetter *getter) {
    getter_ = getter;
}

SystemInfo SysInfoGetterProxy::get_info() {
    if (!cache_.valid_) {
        cache_ = getter_->get_info();

        return cache_;
    }

    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    long long currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();

    if (currentTime - cache_.createTime_ <= 2000) {
        return cache_;
    }
    else {
        cache_ = getter_->get_info();
        return cache_;
    }

    return getter_->get_info();
}

SystemInfo LinuxInfoGetter::get_info() {
    SystemInfo info;
    info.cpu_ = 0.23;
    info.mem_ = 0.55;
    info.valid_ = true;

    return info;
}

SystemInfo WindowsInfoGetter::get_info() {
    SystemInfo info;
    info.cpu_ = 0.23;
    info.mem_ = 0.55;
    info.valid_ = true;

    return info;
}

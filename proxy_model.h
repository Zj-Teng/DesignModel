//
// Created by TeTng on 2023/10/17.
//

#ifndef DESIGN_MODEL_PROXY_MODEL_H
#define DESIGN_MODEL_PROXY_MODEL_H

/* 代理模式实现
 *
 *
 * */

class SystemInfo {
public:
    SystemInfo() = default;
    ~SystemInfo() = default;

    float cpu_;
    float mem_;
    long long createTime_;
    bool valid_;
};

class SysInfoGetter {
public:
    virtual SystemInfo get_info() = 0;
};

class SysInfoGetterProxy: public SysInfoGetter {
private:
    static SystemInfo cache_;
    SysInfoGetter* getter_ = nullptr;

public:
    explicit SysInfoGetterProxy(SysInfoGetter* getter);

    SystemInfo get_info() override;
};

class LinuxInfoGetter: public SysInfoGetter {
public:
    SystemInfo get_info() override;
};

class WindowsInfoGetter: public SysInfoGetter {
public:
    SystemInfo get_info() override;
};

#endif //DESIGN_MODEL_PROXY_MODEL_H

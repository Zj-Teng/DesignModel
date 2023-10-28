//
// Created by TeTng on 2023/10/14.
//

#ifndef DESIGN_MODEL_INSTANCE_MODEL_H
#define DESIGN_MODEL_INSTANCE_MODEL_H

#include "string"
#include "memory"
#include "mutex"

/* 单例实现
* 1. 将默认构造函数设为私有，防止其他对象使用单例类的 new 运算符。
* 2. 新建一个静态构建方法作为构造函数。该函数会调用私有构造函数来创建对象，
* 并将其保存在一个静态成员变量中。此后所有对于该函数的调用都将返回这一缓存对象。
*/

class DBConfig {
public:
    static volatile DBConfig *config;

    static volatile DBConfig *getInstance();

    std::string getConn();

    std::string getUsername();

    std::string getPassword();

    // 禁用拷贝构造函数
    DBConfig(const DBConfig &config) = delete;

    // 禁用赋值构造函数
    DBConfig& operator=(const DBConfig &config) = delete;

private:
    DBConfig();
    std::string conn_;
    std::string username_;
    std::string password_;
    std::mutex mux_;
};

class SqlQuery {
public:
    SqlQuery(const std::string &conn, const std::string &username, const std::string &password);

    int query();

private:
    std::string m_conn;
    std::string m_username;
    std::string m_password;
};

#endif //DESIGN_MODEL_INSTANCE_MODEL_H

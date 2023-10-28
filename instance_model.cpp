//
// Created by TeTng on 2023/10/14.
//

#include "instance_model.h"
#include "fstream"
#include "mutex"

using namespace std;

// static变量必须初始化
// 懒汉式单例实现
volatile DBConfig *DBConfig::config = nullptr;

/* 如果config在申明时完成初始化则为饿汉式单例
 * DBConfig *DBConfig::config = new DBConfig();
 * 对应在getInstance()中则不需要再判断nullptr
 * */

volatile DBConfig *DBConfig::getInstance() {
    // 双嵌套模式，解决线程安全问题
    if (config == nullptr){
        unique_lock<mutex> lock(mutex);
        if (config == nullptr) {
            config = new DBConfig();
        }
    }
    /* new分为三个步骤
     * 1. 向OS申请内存
     * 2. 返回申请到的内存起始地址
     * 3. 调用对象的构造函数
     * 在多线程环境下，如果线程A执行了步骤1后config非空，与此同时如果线程B进入临界区
     * 则能直接访问到config，但里面的内容非法，导致问题。
     * */

    return config;
}

std::string DBConfig::getConn() {
    return conn_;
}

std::string DBConfig::getUsername() {
    return username_;
}

std::string DBConfig::getPassword() {
    return password_;
}

DBConfig::DBConfig() {
    std::fstream fs("./config.txt");
    char tempStr[1024];
    int index = 0;
    while (fs.getline(tempStr, 1024)) {
        if (index == 0) {
            conn_ = tempStr;
        } else if (index == 1) {
            username_ = tempStr;
        } else if (index == 2) {
            password_ = tempStr;
        }
        index++;
    }

    printf("Read config from file\n");
}

SqlQuery::SqlQuery(const std::string &conn, const std::string &username, const std::string &password) {
    m_conn = conn;
    m_username = username;
    m_password = password;
}

int SqlQuery::query() {
    // 假装这里有实现。
    return 0;
}

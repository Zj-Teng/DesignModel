//
// Created by TeTng on 2023/11/2.
//

#include "builder_model.h"

SystemConfig::SystemConfig(
        const std::string &MySQL_URL, const std::string &MySQL_USER, const std::string &MySQL_PW,
        const std::string &Redis_URL, const std::string &Redis_USER, const std::string &Redis_PW,
        const std::string &Kafka_URL, const std::string &Kafka_USER, const std::string &Kafka_PW) {
    MySQL_URL_ = MySQL_URL;
    MySQL_USER_ = MySQL_USER;
    MySQL_PW_ = MySQL_PW;

    Redis_URL_ = Redis_URL;
    Redis_USER_ = Redis_USER;
    Redis_PW_ = Redis_PW;

    Kafka_URL_ = Kafka_URL;
    Kafka_USER_ = Kafka_USER;
    Kafka_PW_ = Kafka_PW;
}

SystemConfig &SystemConfigBuilder::getSystemConfig() {
    return config;
}

void SystemConfigBuilder::setMySQL(
        const std::string &MySQL_URL, const std::string &MySQL_USER, const std::string &MySQL_PW) {
    config.MySQL_URL_ = MySQL_URL;
    config.MySQL_USER_ = MySQL_USER;
    config.MySQL_PW_ = MySQL_PW;
}

void SystemConfigBuilder::setRedis(
        const std::string &Redis_URL, const std::string &Redis_USER, const std::string &Redis_PW) {
    config.Redis_URL_ = Redis_URL;
    config.Redis_USER_ = Redis_USER;
    config.Redis_PW_ = Redis_PW;
}

void SystemConfigBuilder::setKafka(
        const std::string &Kafka_URL, const std::string &Kafka_USER, const std::string &Kafka_PW) {
    config.Kafka_URL_ = Kafka_URL;
    config.Kafka_USER_ = Kafka_USER;
    config.Kafka_PW_ = Kafka_PW;
}

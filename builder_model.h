//
// Created by TeTng on 2023/11/2.
//

#ifndef DESIGN_MODEL_BUILDER_MODEL_H
#define DESIGN_MODEL_BUILDER_MODEL_H

#include "string"

class SystemConfig {
public:
    SystemConfig() = default;

    SystemConfig(
            const std::string &MySQL_URL, const std::string &MySQL_USER, const std::string &MySQL_PW,
            const std::string &Redis_URL, const std::string &Redis_USER, const std::string &Redis_PW,
            const std::string &Kafka_URL, const std::string &Kafka_USER, const std::string &Kafka_PW
    );

    std::string MySQL_URL_;
    std::string MySQL_USER_;
    std::string MySQL_PW_;

    std::string Redis_URL_;
    std::string Redis_USER_;
    std::string Redis_PW_;

    std::string Kafka_URL_;
    std::string Kafka_USER_;
    std::string Kafka_PW_;
};

class SystemConfigBuilder {
public:
    SystemConfig config;

    SystemConfig &getSystemConfig();

    void setMySQL(const std::string &MySQL_URL, const std::string &MySQL_USER, const std::string &MySQL_PW);

    void setRedis(const std::string &Redis_URL, const std::string &Redis_USER, const std::string &Redis_PW);

    void setKafka(const std::string &Kafka_URL, const std::string &Kafka_USER, const std::string &Kafka_PW);
};

#endif //DESIGN_MODEL_BUILDER_MODEL_H

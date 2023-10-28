//
// Created by TeTng on 2023/10/15.
//

#ifndef DESIGN_MODEL_FACTORY_MODEL_H
#define DESIGN_MODEL_FACTORY_MODEL_H

#include "string"

enum MessageType {
    WX, QQ
};

class Message {
public:
    virtual void sendMsg(const std::string &msg) = 0;
};

class WXMsg : public Message {
private:
    std::string device_id_;
    std::string public_key_;
public:
    WXMsg() = default;

    ~WXMsg() = default;

    WXMsg(const std::string& device_id, const std::string& public_key);

    void sendMsg(const std::string &msg) override;
};

class QQMsg : public Message {
private:
    std::string device_id_;
    std::string public_key_;
public:
    QQMsg() = default;

    ~QQMsg() = default;

    QQMsg(const std::string &device_id, const std::string &public_key);

    void sendMsg(const std::string &msg) override;
};

/* 简单工厂方法实现
 * 可以视为对判断条件的简单封装，用来处理一部分简单逻辑。
 * */
class SimpleMessageFactory {
public:
    static Message *createMsg(MessageType msg_type, const std::string &device_id, const std::string &public_key);
};

/* 工厂方法实现
 * 对简单工厂进一步封装，可以排除类型的影响
 *
 * */
class MessageFactory {
public:
    virtual Message *createMsg(const std::string &device_id, const std::string &public_key) = 0;
};

class WXMsgFactory: public MessageFactory {
    Message *createMsg(const std::string &device_id, const std::string &public_key) override;
};

class QQMsgFactory: public MessageFactory {
    Message *createMsg(const std::string &device_id, const std::string &public_key) override;
};

/* 抽象工厂实现
 *
 * */

#endif //DESIGN_MODEL_FACTORY_MODEL_H

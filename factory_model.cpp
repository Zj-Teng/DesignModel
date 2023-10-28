//
// Created by TeTng on 2023/10/15.
//

#include "factory_model.h"
#include "iostream"

using namespace std;

WXMsg::WXMsg(const std::string &device_id, const std::string &public_key) {
    device_id_ = string(device_id);
    public_key_ = string(public_key);
}

void WXMsg::sendMsg(const std::string &msg) {
    if (msg.empty()) return;
    cout << "WX device: " << device_id_ << " send: " << msg << endl;
}

QQMsg::QQMsg(const std::string &device_id, const std::string &public_key) {
    device_id_ = string(device_id);
    public_key_ = string(public_key);
}

void QQMsg::sendMsg(const std::string &msg) {
    if (msg.empty()) return;
    cout << "QQ device: " << device_id_ << " send: " << msg << endl;
}

Message *SimpleMessageFactory::createMsg(
        MessageType msg_type, const std::string &device_id, const std::string &public_key
) {
    if (msg_type == WX) return new WXMsg(device_id, public_key);
    if (msg_type == QQ) return new QQMsg(device_id, public_key);

    return nullptr;
}

Message *WXMsgFactory::createMsg(const string &device_id, const string &public_key) {
    return new WXMsg(device_id, public_key);
}

Message *QQMsgFactory::createMsg(const string &device_id, const string &public_key) {
    return new QQMsg(device_id, public_key);
}

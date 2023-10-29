#include <iostream>
#include "instance_model.h"
#include "prototype_model.h"
#include "factory_model.h"
#include "proxy_model.h"
#include "decorator_model.h"
#include "thread"

using namespace std;

void run_instance();

void run_prototype();

void run_simple_factory();

void run_factory_method();

void run_proxy();

void run_decorator();

int main() {
//    run_instance();
//    run_prototype();
//    run_simple_factory();
//    run_factory_method();
//    run_proxy();
    run_decorator();

    return 0;
}

void run_instance() {
    for (int i = 0; i < 100; i++) {
        auto config = const_cast<DBConfig *>(DBConfig::getInstance());
        SqlQuery query(config->getConn(), config->getUsername(), config->getPassword());

        // 查询操作
        query.query();

        printf("Query : %d\n", i);
    }

    std::cout << "Instance model\n";
}

void run_prototype() {
    BitmapPlus bitmap1(128, 128);
    BitmapPlus bitmap2(256, 256);

    bitmap1 = bitmap2;
    cout << "w: " << bitmap1.getWidth() << " h: " << bitmap1.getWidth() << endl;
}

void run_simple_factory() {
    Message *msg = SimpleMessageFactory::createMsg(WX, "123", "456");
    msg->sendMsg("This is WX msg");

    delete msg;
}

void run_factory_method() {
    MessageFactory *mf = new WXMsgFactory();
    Message *msg = mf->createMsg("123", "456");
    msg->sendMsg("This is WX msg");

    delete mf;
    delete msg;
}

void run_proxy() {
    while (1) {
        LinuxInfoGetter lnx;
        WindowsInfoGetter wdos;

        SysInfoGetterProxy proxy(&lnx);
        SystemInfo info = proxy.get_info();
        cout << info.cpu_ << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void run_decorator() {
    FileStreamReader reader;
    DecryptStreamReader decrypt(&reader);
    ImageDecodeStreamReader decoder(&decrypt);

    decoder.open(R"(D:\CPP_Workplace\Design_Model\text.txt)");

    while (1) {
        uint8_t buffer[1024];
        int ret = reader.read(buffer, 1024);
        if (ret <= 0) break;

        for (int i = 0; i < ret; i ++) {
            cout << buffer[i];
        }
        cout << endl;
    }

    reader.close();
}

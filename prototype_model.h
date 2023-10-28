//
// Created by TeTng on 2023/10/14.
//

#ifndef DESIGN_MODEL_PROTOTYPE_MODEL_H
#define DESIGN_MODEL_PROTOTYPE_MODEL_H

#include <cstdint>

/* 原型模式实现
 * 在c++中拷贝构造函数和赋值构造函数可以直接的实现原型模式
 * 所有的类对克隆方法的实现都非常相似。该方法会创建一个当前类的对象，然后将原始对象所有的成员变量值复制到新建的类中。
 * */

class BitmapPlus {
public:
    BitmapPlus() = default;

    BitmapPlus(int w, int h);

    ~BitmapPlus();

    BitmapPlus(const BitmapPlus &bitmap);

    BitmapPlus &operator=(const BitmapPlus &bitmap);

    int getWidth() const;

    int getHeight() const;

    uint8_t *getData() const;

private:
    int width_ = 0;
    int height_ = 0;
    uint8_t *data_ = nullptr;
};


#endif //DESIGN_MODEL_PROTOTYPE_MODEL_H

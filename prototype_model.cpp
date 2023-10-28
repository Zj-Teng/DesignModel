//
// Created by TeTng on 2023/10/14.
//

#include "prototype_model.h"
#include "memory"
#include "malloc.h"

using namespace std;

BitmapPlus::BitmapPlus(int w, int h) {
    width_ = w;
    height_ = h;
    data_ = (uint8_t *) malloc(width_ * height_ * sizeof(uint8_t));
}

BitmapPlus::~BitmapPlus() {
    if (data_ != nullptr) {
        free(data_);
        data_ = nullptr;
    }
}

BitmapPlus::BitmapPlus(const BitmapPlus &bitmap) {
    *this = bitmap;
}

BitmapPlus &BitmapPlus::operator=(const BitmapPlus &bitmap) {
    if (data_ != nullptr) {
        free(data_);
        data_ = nullptr;
    }

    width_ = bitmap.getHeight();
    height_ = bitmap.getHeight();
    data_ = (uint8_t*)malloc(width_ * height_ * sizeof(uint8_t));
    memcpy(data_, bitmap.getData(), width_ * height_ * sizeof(uint8_t));

    return *this;
}

int BitmapPlus::getWidth() const {
    return width_;
}

int BitmapPlus::getHeight() const {
    return height_;
}

uint8_t *BitmapPlus::getData() const {
    return data_;
}

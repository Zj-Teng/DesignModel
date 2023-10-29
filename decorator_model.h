//
// Created by TeTng on 2023/10/28.
//

#ifndef DESIGN_MODEL_DECORATOR_MODEL_H
#define DESIGN_MODEL_DECORATOR_MODEL_H

#include "string"
#include <cstdint>
#include "vector"

class StreamReader {
public:
    virtual int open(const std::string &url) = 0;

    virtual int close() = 0;

    virtual int read(uint8_t *buffer, int offset) = 0;

    virtual ~StreamReader() = default;
};

/*
 * */
class FileStreamReader : public StreamReader {
private:
    FILE *file_ = nullptr;
public:
    int open(const std::string &url) override;

    int close() override;

    int read(uint8_t *buffer, int offset) override;
};

class HttpStreamReader : public StreamReader {
public:
    int open(const std::string &url) override;

    int close() override;

    int read(uint8_t *buffer, int offset) override;

    std::vector<uint8_t> cache_;
    int pos = 0;
};

class DecorateStreamReader : public StreamReader {
public:
    explicit DecorateStreamReader(StreamReader *reader);

    StreamReader *reader_ = nullptr;

    virtual ~DecorateStreamReader() = default;

    virtual int open(const std::string &url) = 0;

    virtual int close() override = 0;

    virtual int read(uint8_t *buffer, int offset) = 0;
};

/* 修饰器可以嵌套，从而在被修饰的函数（前/后）添加新的动作
 * */
class DecryptStreamReader : public DecorateStreamReader {
public:
    explicit DecryptStreamReader(StreamReader *reader);

    ~DecryptStreamReader() override = default;

    int open(const std::string &url) override;

    int close() override;

    int read(uint8_t *buffer, int offset) override;
};

class ImageDecodeStreamReader : public DecorateStreamReader {
public:
    explicit ImageDecodeStreamReader(StreamReader *reader);

    ~ImageDecodeStreamReader() override = default;

    int open(const std::string &url) override;

    int close() override;

    int read(uint8_t *buffer, int offset) override;
};

#endif //DESIGN_MODEL_DECORATOR_MODEL_H

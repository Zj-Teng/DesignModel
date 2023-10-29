//
// Created by TeTng on 2023/10/28.
//

#include "decorator_model.h"
#include "curl/curl.h"
#include "iostream"

using namespace std;

int FileStreamReader::open(const string &url) {
    file_ = fopen(url.c_str(), "rb");
    return 0;
}

int FileStreamReader::close() {
    if (file_ != nullptr) {
        fclose(file_);
        file_ = nullptr;
    }

    return 0;
}

int FileStreamReader::read(uint8_t *buffer, int offset) {
    return (int) fread(buffer, 1, offset, file_);
}

static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    size_t len = size * nmemb;
    auto *httpStreamReader = (HttpStreamReader *) userp;

    auto *buf = (uint8_t *) buffer;
    for (int i = 0; i < len; i++) {
        httpStreamReader->cache_.push_back(buf[i]);
    }

    return len;
}

int HttpStreamReader::open(const string &url) {
    CURL *curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    curl_easy_cleanup(curl);

    return 0;
}

int HttpStreamReader::close() {
    return 0;
}

int HttpStreamReader::read(uint8_t *buffer, int offset) {
    int cache_len = cache_.size() - pos;
    int len = min(cache_len, offset);

    for (int i = 0; i < len; i++) {
        buffer[i] = cache_[pos + i];
    }
    pos += len;

    return len;
}

DecorateStreamReader::DecorateStreamReader(StreamReader *reader) {
    reader_ = reader;
}

DecryptStreamReader::DecryptStreamReader(StreamReader *reader) : DecorateStreamReader(reader) {

}

int DecryptStreamReader::open(const string &url) {
    return reader_->open(url);
}

int DecryptStreamReader::close() {
    return reader_->close();
}

int DecryptStreamReader::read(uint8_t *buffer, int offset) {
    int ret = reader_->read(buffer, offset);
    cout << "DecryptStreamReader decrypt" << endl;

    return ret;
}

ImageDecodeStreamReader::ImageDecodeStreamReader(StreamReader *reader) : DecorateStreamReader(reader) {

}

int ImageDecodeStreamReader::open(const string &url) {
    return reader_->open(url);
}

int ImageDecodeStreamReader::close() {
    return reader_->close();
}

int ImageDecodeStreamReader::read(uint8_t *buffer, int offset) {
    int ret = reader_->read(buffer, offset);
    cout << "ImageDecodeStreamReader decoder image" << endl;

    return ret;
}

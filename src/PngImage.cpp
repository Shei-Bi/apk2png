#include "PngImage.h"
#include <memory>
PngImage::PngImage(int width, int height, int channels, unsigned char* data) {
    this->width = width;
    this->height = height;
    this->channels = channels;
    this->data = data;
}
PngImage* PngImage::create(int width, int height, int channels) {
    return new PngImage(width, height, channels, (unsigned char*)malloc(width * height * channels));
}
void PngImage::paste(PngImage* other, int x, int y) {
    for (int i = y;i < other->height;i++) {
        for (int j = x;j < other->width;j++) {
            for (int k = 0;k < other->channels;k++) {
                data[(i * width + j) * channels + k] = other->data[((i - y) * other->width + (j - x)) * other->channels + k];
            }
        }
    }
}
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
                getPixel(j, i)[k] = other->getPixel(j - x, i - y)[k];
            }
        }
    }
}
unsigned char* PngImage::getPixel(int x, int y) {
    return &data[(y * width + x) * channels];
}
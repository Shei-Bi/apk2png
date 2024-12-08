#pragma once
class PngImage
{
public:
    int width;
    int height;
    int channels;
    unsigned char* data;

    PngImage(int, int, int, unsigned char*);
    static PngImage* create(int, int, int);

    void paste(PngImage*, int, int);
    unsigned char* getPixel(int, int);
};

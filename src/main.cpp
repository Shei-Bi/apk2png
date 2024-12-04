#include <stdio.h>
#include "ResourceManager.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    auto result = PngImage::create(21 * 20, 33 * 20, 4);
    auto tnt_box = ResourceManager::getMovieClip("tnt_box");
    printf("%d\n", tnt_box->width);
    result->paste(tnt_box, 0, 0);
    stbi_write_png("result.png", result->width, result->height, result->channels, result->data, result->width * result->channels);
    return 0;
}
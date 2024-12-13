#include <stdio.h>
#include "ResourceManager.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
// #include "CSVNode.hpp"
#include "LogicDataTables.hpp"
enum DataType {
    LocationTheme = 47
};
int main() {
    LogicDataTables::initDataTable(CSVNode::fromFile("assets/location_themes.csv"), LocationTheme);
    // auto Default = TABLES[LocationTheme]->getDataByName("Default", NULL);
    auto result = PngImage::create(21 * 20, 33 * 20, 4);
    for (int i = 0;i < result->height;i++) {
        for (int j = 0;j < result->width;j++) {
            auto pixel = result->getPixel(j, i);
            pixel[0] = 249;
            pixel[1] = 166;
            pixel[2] = 117;
            pixel[3] = 255;
        }
    }
    auto tnt_box = ResourceManager::getMovieClip("town_spawn_hole");

    printf("%d\n", tnt_box->width);
    unsigned char* pixel = tnt_box->getPixel(19, 0);
    printf("r:%d g:%d b:%d a:%d\n", pixel[0], pixel[1], pixel[2], pixel[3]);
    result->paste(tnt_box, 0, 0);
    stbi_write_png("result.png", result->width, result->height, result->channels, result->data, result->width * result->channels);
    return 0;
}
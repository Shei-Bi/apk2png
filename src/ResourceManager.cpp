#pragma once
#include "ResourceManager.h"
#include <stdio.h>
#include <filesystem>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

PngImage* ResourceManager::getMovieClip(char* file, char* name) {
    return loadImage((char*)(std::filesystem::path("assets") / "level" / name).replace_extension("png").generic_string().c_str());
}
PngImage* ResourceManager::getMovieClip(char* name) {
    return ResourceManager::getMovieClip("", name);
}
PngImage* ResourceManager::loadImage(char* path) {
    int x, y, channels;
    printf("loading %s\n", path);

    unsigned char* data = stbi_load(path, &x, &y, &channels, 0);
    if (data == NULL) {
        printf("failed to load %s\n", path);
        abort();
    }
    return new PngImage(x, y, channels, data);
}

#pragma once
#include "PngImage.h"
class ResourceManager
{
public:
    // static std::filesystem::path rootPath;
    // static std::filesystem::path cachePath;
    // static std::vector<std::pair<char*, void*>> Resources;
    // static std::set<char*> ResourcesToLoad;
    // static void init();
    static PngImage* getMovieClip(char* name);
    static PngImage* getMovieClip(char* file, char* name);
    // static void addFile(char* file);
    // static sc::flash::SupercellSWF* getSupercellSWF(char* name, char* needby);
    // static void loadNextResource();
    // static bool resourceToLoad();
    static PngImage* loadImage(char* path);
};

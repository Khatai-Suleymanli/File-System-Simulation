#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <unordered_map>
#include "file.h"

class Directory {
public:
    Directory(const std::string& name);
    void addFile(const std::string& fileName, const std::string& content);
    void addSubdirectory(const std::string& dirName);
    File* getFile(const std::string& fileName);
    void deleteFile(const std::string& fileName);

private:
    std::string name;
    std::unordered_map<std::string, File> files;
    std::unordered_map<std::string, Directory> subdirectories;
};

#endif

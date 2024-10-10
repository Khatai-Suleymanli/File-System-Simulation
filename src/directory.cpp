#include "directory.h"
#include <iostream>

Directory::Directory(const std::string& name) : name(name) {}

void Directory::addFile(const std::string& fileName, const std::string& content) {
    files[fileName] = File(fileName, content);
}

void Directory::addSubdirectory(const std::string& dirName) {
    subdirectories[dirName] = Directory(dirName);
}

File* Directory::getFile(const std::string& fileName) {
    if (files.find(fileName) != files.end()) {
        return &files[fileName];
    }
    return nullptr;
}

void Directory::deleteFile(const std::string& fileName) {
    if (files.find(fileName) != files.end()) {
        files.erase(fileName);
    } else {
        std::cerr << "File not found: " << fileName << std::endl;
    }
}

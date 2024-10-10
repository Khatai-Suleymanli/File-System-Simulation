#include "file_system.h"
#include <iostream>

FileSystem::FileSystem() : root("/") {}

void FileSystem::createDirectory(const std::string& path) {
    Directory* dir = navigateToDirectory(path);
    if (dir) {
        std::cerr << "Directory already exists: " << path << std::endl;
    } else {
        root.addSubdirectory(path);
    }
}

void FileSystem::createFile(const std::string& path, const std::string& content) {
    Directory* dir = navigateToDirectory(path.substr(0, path.find_last_of('/')));
    if (dir) {
        dir->addFile(path.substr(path.find_last_of('/') + 1), content);
    } else {
        std::cerr << "Directory does not exist for file: " << path << std::endl;
    }
}

void FileSystem::readFile(const std::string& path) const {
    Directory* dir = navigateToDirectory(path.substr(0, path.find_last_of('/')));
    if (dir) {
        File* file = dir->getFile(path.substr(path.find_last_of('/') + 1));
        if (file) {
            std::cout << file->getContent() << std::endl;
        } else {
            std::cerr << "File not found: " << path << std::endl;
        }
    } else {
        std::cerr << "Directory not found for file: " << path << std::endl;
    }
}

void FileSystem::deleteFile(const std::string& path) {
    Directory* dir = navigateToDirectory(path.substr(0, path.find_last_of('/')));
    if (dir) {
        dir->deleteFile(path.substr(path.find_last_of('/') + 1));
    } else {
        std::cerr << "Directory not found for file: " << path << std::endl;
    }
}

Directory* FileSystem::navigateToDirectory(const std::string& path) {
    // Logic to navigate to a directory
    // You can implement a parsing algorithm to follow the directory tree based on the path
    return &root;
}

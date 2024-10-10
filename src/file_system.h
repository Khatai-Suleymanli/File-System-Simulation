#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include <unordered_map>
#include "directory.h"

class FileSystem {
public:
    FileSystem();
    void createDirectory(const std::string& path);
    void createFile(const std::string& path, const std::string& content);
    void readFile(const std::string& path) const;
    void deleteFile(const std::string& path);
    
private:
    Directory root;
    Directory* navigateToDirectory(const std::string& path);
};

#endif

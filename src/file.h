#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
    File(const std::string& name, const std::string& content);
    std::string getName() const;
    std::string getContent() const;

private:
    std::string name;
    std::string content;
};

#endif

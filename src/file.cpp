#include "file.h"

File::File(const std::string& name, const std::string& content)
    : name(name), content(content) {}

std::string File::getName() const {
    return name;
}

std::string File::getContent() const {
    return content;
}

#include "file_system.h"
#include <iostream>

int main() {
    FileSystem fs;

    fs.createDirectory("/docs");
    fs.createFile("/docs/notes.txt", "This is a note.");
    fs.readFile("/docs/notes.txt");

    fs.createFile("/docs/todo.txt", "1. Study C++\n2. Finish project\n");
    fs.readFile("/docs/todo.txt");

    fs.deleteFile("/docs/notes.txt");
    fs.readFile("/docs/notes.txt"); // Should print an error

    return 0;
}

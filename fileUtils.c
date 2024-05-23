#include "fileUtils.h"

char* FL_ReadFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    // Seek to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to hold the file content plus null terminator
    char* content = (char*)malloc(file_size + 1);
    if (content == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    if (file_size > 0)
    {
        // Read the file content into the allocated memory
        size_t readSize = fread(content, 1, file_size, file);

        if (readSize > 0) {
            content[readSize] = '\0';
        }
    }

    fclose(file);
    return content;
}
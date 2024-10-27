#ifndef MY_HEADERFILE_H
#define MY_HEADERFILE_H
#include <iostream>

std::string generateRandomText(int length);
std::string generateBytes(int size);
void combineFiles(const std::string& file1, const std::string& file2, const std::string& outputFile);
int parseSize(const std::string& sizeStr);
long getFileSize(const std::string& filename);

#endif

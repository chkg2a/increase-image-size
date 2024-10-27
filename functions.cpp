#include "headerFile.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <cstdio> 


long getFileSize(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary); // Open in binary mode
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1; // Return -1 if file cannot be opened
    }

    // Move the cursor to the end of the file
    file.seekg(0, std::ios::end);
    long size = file.tellg(); // Get the current position in the file (which is the size)
    file.close(); // Close the file
    return size; // Return the file size
}

std::string generateRandomText(int length) {
  const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
  std::string randomText;
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

  for (int i = 0; i < length; ++i) {
    randomText += characters[distribution(generator)];
  }

  return randomText;
}

std::string generateBytes(int size) {
  std::string fileName = generateRandomText(6);
  std::ofstream outputFile(fileName);

  if (!outputFile) {
    std::cerr << "Error creating file!" << std::endl;
  }

  std::string randomLine = generateRandomText(size);
  outputFile << randomLine << std::endl;

  outputFile.close();
  std::cout << "File created successfully!" << std::endl;
  return fileName;
}

void combineFiles(const std::string& file1, const std::string& file2, const std::string& outputFile) {
    std::ifstream inputFile1(file1);
    std::ifstream inputFile2(file2);
    std::ofstream output(outputFile);

    if (!inputFile1) {
        std::cerr << "Error opening file: " << file1 << std::endl;
        return;
    }

    if (!inputFile2) {
        std::cerr << "Error opening file: " << file2 << std::endl;
        return;
    }

    if (!output) {
        std::cerr << "Error creating output file: " << outputFile << std::endl;
        return;
    }

    // Read from the first file and write to the output file
    std::string line;
    while (std::getline(inputFile1, line)) {
        output << line << std::endl;
    }

    // Read from the second file and write to the output file
    while (std::getline(inputFile2, line)) {
        output << line << std::endl;
    }

    // Close the files
    inputFile1.close();
    inputFile2.close();
    output.close();
}

// Function to parse size string
int parseSize(const std::string& sizeStr) {
    if (sizeStr.empty()) return -1;

    char unit = std::toupper(sizeStr.back());
    std::string numberStr = sizeStr.substr(0, sizeStr.size() - 1);
    
    try {
        int number = std::stoi(numberStr);
        switch (unit) {
            case 'K': return number * 1024;      // KB to bytes
            case 'M': return number * 1024 * 1024; // MB to bytes
            case 'G': return number * 1024 * 1024 * 1024; // GB to bytes
            default: return number; // Return Byte value
        }
    } catch (...) {
        return -1 ; // Error in conversion
    }
}

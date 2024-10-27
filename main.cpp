#include "headerFile.h"

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3 && argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [-s] <size> <inputFileName>" << std::endl;
        return 1;
    }

    bool sizeFlag = false;
    int size;
    std::string inputFileName;

    // Parse command line arguments
    if (argc == 4 && std::string(argv[1]) == "-s") {
        sizeFlag = true;
        size = parseSize(argv[2]); // Convert size from string to int
        inputFileName = argv[3]; // Get input file name
    } else {
        size = parseSize(argv[1]); // Convert size from string to int
        inputFileName = argv[2]; // Get input file name
    }

    if (size <= 0) {
        std::cerr << "Invalid size specified." << std::endl;
        return 1;
    }

    // Get the size of the input file
    long inputFileSize = getFileSize(inputFileName);
    if (inputFileSize < 0) {
        std::cerr << "Error getting size of the input file." << std::endl;
        return 1;
    }

    // If -s is specified and input file size is less than desired size, adjust size
    if(sizeFlag){
      if (inputFileSize < size) {
          size -= inputFileSize; // Final size will be desired size minus input file size
      } else {
          size = 0; // No need to generate bytes if -s is not used or size is sufficient
      }
    }

    std::string dummyFileName = generateBytes(size);
    std::string outputFilename = "final-increased-image.jpg";

    combineFiles(inputFileName, dummyFileName, outputFilename);

    // Delete the dummy file
    if (std::remove(dummyFileName.c_str()) != 0) {
        std::cerr << "Error deleting the dummy file: " << dummyFileName << std::endl;
    } else {
        std::cout << "Dummy file deleted successfully: " << dummyFileName << std::endl;
    }

    std::cout << "Files combined successfully into " << outputFilename << std::endl;
    return 0;
}

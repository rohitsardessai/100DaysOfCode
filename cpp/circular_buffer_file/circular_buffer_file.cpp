#include <fstream>
#include <iostream>
#include <string>

class CircularBuffer
{
private:
    size_t readPos;
    size_t writePos;
    size_t bufferSize;
    std::ofstream outputFile;
    std::ifstream inputFile;
    std::string filename; // Store the filename separately

public:
    CircularBuffer(size_t maxLines, const std::string &filename)
        : bufferSize(maxLines), readPos(0), writePos(0), filename(filename)
    {
        outputFile.open(filename, std::ofstream::out | std::ofstream::app);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening the output file.\n";
        }

        inputFile.open(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening the input file.\n";
        }
    }

    ~CircularBuffer()
    {
        closeFile();
    }

    bool writeLine(const std::string &line)
    {
        writePos = (writePos + 1) % bufferSize;
        if (writePos == readPos) {
            readPos = (readPos + 1) % bufferSize;
        }

        outputFile.write(line.c_str(), line.size());
        outputFile.put('\n');
        outputFile.flush(); // Flush the data to the file without closing it. The flush() method forces the data in the output buffer to be written to the file immediately without closing the file.
        return true;
    }

    bool readLine(std::string &line)
    {
        if (readPos == writePos) {
            return false;
        }

        inputFile.seekg(0);
        for (size_t i = 0; i <= readPos; ++i) {
            std::getline(inputFile, line); // Read lines until reaching the desired line
        }
        readPos = (readPos + 1) % bufferSize; // Circular read
        return true;
    }

    void closeFile()
    {
        if (outputFile.is_open()) {
            outputFile.close();
        }
        if (inputFile.is_open()) {
            inputFile.close();
        }
    }
};

int main()
{
    const size_t maxLines = 15;
    CircularBuffer buffer(maxLines, "data.txt");

    for (int i = 1; i <= 20; ++i) {
        std::string line = "Line " + std::to_string(i);
        buffer.writeLine(line);
    }

    std::string line;
    while (buffer.readLine(line)) {
        std::cout << line << '\n';
    }

    return 0;
}

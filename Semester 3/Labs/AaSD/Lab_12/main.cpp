#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>

// Генерируем файл с рандомными числами.
void generateInputFile(const std::string& inputFileName, int totalNumbers) {
    std::ofstream inputFile(inputFileName);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    for (int i = 0; i < totalNumbers; ++i) {
        inputFile << dis(gen) << " ";
    }
}
// Разбиваем файл на чанки (части), помещая их в оперативную память, обрабатывая их.
void splitAndSortChunks(const std::string& inputFileName, int chunkSize) {
    std::ifstream inputFile(inputFileName);
    int chunkNumber = 1;

    while (!inputFile.eof()) {
        std::vector<int> chunk;
        chunk.reserve(chunkSize);

        for (int i = 0; i < chunkSize; ++i) {
            int number;
            if (inputFile >> number) {
                chunk.push_back(number);
            }
            else {
                break;
            }
        }

        std::sort(chunk.begin(), chunk.end());

        std::ofstream outputFile("chunk" + std::to_string(chunkNumber++) + ".txt");
        std::copy(chunk.begin(), chunk.end(), std::ostream_iterator<int>(outputFile, " "));
    }
}
// Слияние чанков и их запись в файл.
void mergeChunks(const std::string& outputFileName, int chunkSize, int totalChunks) {
    std::vector<std::ifstream> chunkFiles;
    chunkFiles.reserve(totalChunks);

    for (int i = 1; i <= totalChunks; ++i) {
        chunkFiles.emplace_back("chunk" + std::to_string(i) + ".txt");
    }

    std::vector<int> chunkBuffer(chunkSize);
    std::vector<bool> chunkEmpty(totalChunks, false);
    std::ofstream outputFile(outputFileName);

    while (true) {
        int minChunkIndex = -1;
        for (int i = 0; i < totalChunks; ++i) {
            if (!chunkEmpty[i]) {
                if (minChunkIndex == -1 || chunkBuffer[i] < chunkBuffer[minChunkIndex]) {
                    minChunkIndex = i;
                }
            }
        }

        if (minChunkIndex == -1) {

            break;
        }

        outputFile << chunkBuffer[minChunkIndex] << " ";

        if (chunkFiles[minChunkIndex] >> chunkBuffer[minChunkIndex]) {
            chunkEmpty[minChunkIndex] = false;
        }
        else {
            chunkEmpty[minChunkIndex] = true;
        }
    }

    for (auto& chunkFile : chunkFiles) {
        chunkFile.close();
    }
}
// Внешняя многофазная 
void multiPhaseSort(const std::string& inputFileName, const std::string& outputFileName, int chunkSize) {
    splitAndSortChunks(inputFileName, chunkSize);

    std::ifstream inputFile(inputFileName);
    int totalNumbers = std::distance(std::istream_iterator<int>(inputFile), std::istream_iterator<int>());
    int totalChunks = (totalNumbers + chunkSize - 1) / chunkSize;

    mergeChunks(outputFileName, chunkSize, totalChunks);
}

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";
    int chunkSize = 4;
    int totalNumbers = 15;

    generateInputFile(inputFileName, totalNumbers);

    multiPhaseSort(inputFileName, outputFileName, chunkSize);

    return 0;
}

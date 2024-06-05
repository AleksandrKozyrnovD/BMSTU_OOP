#ifndef BINARYREADER_H
#define BINARYREADER_H

#include "abstractreader.h"
#include <memory>
#include <fstream>


class BinaryReader : public AbstractReader
{
public:
    BinaryReader();
    explicit BinaryReader(const std::string& filename);
    ~BinaryReader() = default;

    void open() override;
    void close() override;
    double read() override;

    bool is_open() override;

private:
    std::string filename;
    // std::shared_ptr<std::ifstream> file;
    FILE *file = nullptr;
};

#endif // BINARYREADER_H

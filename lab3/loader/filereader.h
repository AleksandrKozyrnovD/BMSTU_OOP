#ifndef FILEREADER_H
#define FILEREADER_H

#include "abstractreader.h"
#include <memory>
#include <fstream>


class FileReader : public AbstractReader
{
public:
    FileReader();
    explicit FileReader(const std::string& filename);
    ~FileReader() = default;

    void open() override;
    void close() override;
    double read() override;

    bool is_open() override;

private:
    std::string filename;
    // std::shared_ptr<std::ifstream> file;
    FILE *file = nullptr;
};

#endif // FILEREADER_H

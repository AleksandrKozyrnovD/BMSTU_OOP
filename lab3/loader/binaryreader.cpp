#include "binaryreader.h"


BinaryReader::BinaryReader() {}

BinaryReader::BinaryReader(const std::string& filename)
{
    this->filename = filename;
}

void BinaryReader::open()
{
    if (this->is_open())
    {
        throw std::exception();
    }

    this->file = fopen(this->filename.c_str(), "rb");

    if (!this->is_open())
    {
        throw std::exception();
    }
}

void BinaryReader::close()
{
    if (!this->is_open())
    {
        throw std::exception();
    }

    fclose(this->file);
    this->file = nullptr;
}

bool BinaryReader::is_open()
{
    return this->file != nullptr;
}

double BinaryReader::read()
{
    if (!this->is_open())
    {
        throw std::exception();
    }

    double x;

    // fscanf(this->file, "%lf", &x);
    fread(&x, sizeof(double), 1, this->file);
    // *file >> x;

    return x;
}

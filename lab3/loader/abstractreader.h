#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

// #include <memory>
// #include <fstream>

class AbstractReader
{
public:
    AbstractReader();
    virtual ~AbstractReader() = default;

    virtual void open() = 0;
    virtual void close() = 0;
    virtual double read() = 0;

    virtual bool is_open() = 0;

// protected:
//     std::shared_ptr<std::ifstream> file;
};

#endif // ABSTRACTREADER_H

#ifndef MODEIO_H
#define MODEIO_H

#include "exceptions/ioexception.h"
#include "workers/modelbuilder.h"

#include <fstream>

class BaseIO
{
public:
    BaseIO() = default;
    virtual ~BaseIO() = default;

    virtual std::shared_ptr<Model> io_model(BaseBuilder& build) = 0;
    virtual void open_file() = 0;
    virtual void close_file() = 0;
};

class ModelIO : public BaseIO
{
public:
    explicit ModelIO(const std::string& file_name);
    ~ModelIO() = default;

    std::shared_ptr<Model> io_model(BaseBuilder &build) override;

    void open_file() override;
    void close_file() override;

private:
    std::string file_name;
    std::ifstream file;
};


#endif // MODEIO_H

#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "workers/modelio.h"

class IOManager
{
public:
    IOManager() = default;
    ~IOManager() = default;

    std::shared_ptr<Model> io_model(BaseIO& io, BaseBuilder& build)
    {
        io.open_file();
        std::shared_ptr<Model> model(io.io_model(build));
        io.close_file();

        return model;
    }
};

#endif // IOMANAGER_H

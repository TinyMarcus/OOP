#include "modelio.h"

ModelIO::ModelIO(const std::string& file_name) : file_name(file_name) {}

void ModelIO::open_file()
{
    this->file.open(this->file_name);

    if (!file)
    {
        throw OpenFileException();
    }
}

std::shared_ptr<Model> ModelIO::io_model(BaseBuilder &build)
{
    try {
        build.build_model();

        size_t edges_cnt, source, goal;

        file >> edges_cnt;

        for (int i = 0; i < edges_cnt; i++)
        {
            file >> source >> goal;
            build.build_edge(source, goal);
        }

        size_t nodes_cnt;
        double x, y, z;

        file >> nodes_cnt;

        for (int i = 0; i < nodes_cnt; i++)
        {
            file >> x >> y >> z;
            build.build_node(x, y, z);
        }
    } catch (const std::ifstream::failure& e) {
        throw ReadFileException();
    }

    return build.get_model();
}

void ModelIO::close_file()
{
    try {
        this->file.close();
    } catch (const std::ifstream::failure& e) {
        throw CloseFileException();
    }
}

#include "mesh.h"

/* Инициализация структуры с данными о количестве точек, с координатами точек, с индексами */
mesh init_mesh()
{
    mesh msh;
    msh.indicesCount = 0;
    msh.verticesCount = 0;
    msh.isLoaded = false;
    msh.vertices = nullptr;
    msh.indices = nullptr;

    return msh;
}

/* Копирование данных из одной структуры в другую */
void copy_mesh_attributes(mesh& dst, const mesh& src)
{
    dst.verticesCount = src.verticesCount;
    dst.indicesCount = src.indicesCount;
    dst.isLoaded = src.isLoaded;

    dst.vertices = new Vector4f[dst.verticesCount];
    dst.indices = new unsigned short[dst.indicesCount];

    for (int i = 0; i < dst.verticesCount; i++)
    {
        dst.vertices[i] = src.vertices[i];
        memcpy(&dst.vertices[i], &src.vertices[i], sizeof(Vector4f));
    }

    for (int i = 0; i < dst.indicesCount; i++)
    {
        dst.indices[i] = src.indices[i];
        memcpy(&dst.indices[i], &src.indices[i], sizeof(unsigned short));
    }
}

/* Копирование структуры (обертка) */
void copy_mesh(mesh& dst, const mesh& src)
{
    if (src.isLoaded && src.vertices && src.indices)
    {
        mesh dst = init_mesh();
        allocate_mesh_fields(dst, src.verticesCount, src.indicesCount);
    }

    copy_mesh_attributes(dst, src);
}

/* Выделение памяти под структуру */
error allocate_mesh_fields(mesh& msh, int verticesCount, int indicesCount)
{
    msh.verticesCount = verticesCount;
    msh.indicesCount = indicesCount;
    msh.vertices = new Vector4f[verticesCount];
    msh.indices = new unsigned short[indicesCount];
    msh.isLoaded = false;

    error res = error::OK;

    if (msh.indices != nullptr && msh.vertices != nullptr)
    {
        res = error::OK;
    }
    else
    {
        res = error::AllocationError;
    }

    return res;
}

/* Очистка памяти из-под структуры */
void delete_mesh(mesh& msh)
{
    msh.isLoaded = false;
    msh.verticesCount = 0;
    msh.indicesCount = 0;
    if (msh.vertices)
    {
        delete[] msh.vertices;
        msh.vertices = nullptr;
    }
    if (msh.indices)
    {
        delete[] msh.indices;
        msh.indices = nullptr;
    }
}

/* Чтение из файла количества вершин и количества индексов для отрисовки линий */
void read_indices(mesh& msh, unsigned short& idx0, unsigned short& idx1, error& er, int& ind, FILE* fsrc)
{
    if (fscanf(fsrc, "%hu %hu", &idx0, &idx1) != 2)
    {
        er = error::IncorrectFileData;
    }
    else
    {
        msh.indices[ind] = idx0;
        msh.indices[ind + 1] = idx1;
    }
}

/* Чтение из файла количества вершин и количества индексов для отрисовки линий */
error read_mesh_indices(mesh& msh, FILE* fsrc)
{
    error er = error::OK;

    for (int i = 0; i < msh.indicesCount && er == error::OK; i += 2)
    {
        unsigned short idx0, idx1;
        read_indices(msh, idx0, idx1, er, i, fsrc);
    }

    return er;
}

/* Чтение из файла координат вершин фигуры */
void read_vertices(mesh& msh, Vector4f& vertex, FILE* fsrc, error& er, int& ind)
{
    if (fscanf(fsrc, "%lf%lf%lf", &vertex.x, &vertex.y, &vertex.z) != 3)
    {
        er = IncorrectFileData;
    }
    else
    {
        vertex.w = 1.0;
        msh.vertices[ind] = vertex;
    }
}

/* Чтение из файла координат вершин фигуры */
error read_mesh_vertices(mesh& msh, FILE* fsrc)
{
    error er = error::OK;

    for (int i = 0; i < msh.verticesCount && er == error::OK; i++)
    {
        Vector4f vertex;
        read_vertices(msh, vertex, fsrc, er, i);
    }
    return er;
}

/* Чтение из файла количества вершин и индексов для отрисовки линий */
error read_mesh_parameters(int& verticesCount, int& indicesCount, FILE* fsrc)
{
    error er = error::OK;

    if (fscanf(fsrc, "%d%d", &verticesCount, &indicesCount) != 2)
    {
        er = error::IncorrectFileData;
    }
    else
    {
        if (verticesCount < 2 || indicesCount < 2 || indicesCount % 2 != 0)
            er = error::IncorrectFileData;
    }

    return er;
}

/* Чтение из файла (выделение памяти, чтение количества индексов, координат) */
error read_mesh(mesh& model, FILE* fsrc)
{
    error er = error::OK;

    er = read_mesh_parameters(model.verticesCount, model.indicesCount, fsrc);
    if (er != error::OK)
    {
        return er;
    }

    er = allocate_mesh_fields(model, model.verticesCount, model.indicesCount);
    if (er != error::OK)
    {
        return er;
    }

    er = read_mesh_vertices(model, fsrc);
    if (er == error::OK)
    {
        er = read_mesh_indices(model, fsrc);
    }

    if (er != error::OK)
    {
        delete_mesh(model);
    }
    else
    {
        model.isLoaded = true;
    }

    return er;
}

/* Чтение из файла (обертка) */
error load_mesh_from_file(mesh& model, const char* filepath)
{
    error er = error::OK;

    FILE* fsrc = fopen(filepath, "r");
    if (!fsrc)
    {
        return error::FileNotFound;
    }

    er = read_mesh(model, fsrc);
    fclose(fsrc);

    return er;
}

/* Сохранение в файл количества вершин, индексов */
void save_mesh_attributes_to_file(const mesh& msh, FILE* fdst)
{
    fprintf(fdst, "%d %d\n\n", msh.verticesCount, msh.indicesCount);

    for (int i = 0; i < msh.verticesCount; i++)
    {
        fprintf(fdst, "%f %f %f\n", msh.vertices[i].x, msh.vertices[i].y,
                msh.vertices[i].z);
    }

    fprintf(fdst, "%s", "\n");

    for (int i = 0; i < msh.indicesCount; i += 2)
    {
        fprintf(fdst, "%hu %hu\n", msh.indices[i], msh.indices[i + 1]);
    }

    fprintf(fdst, "%s", "\n");
}

/* Сохранение данных в файл (обертка) */
error save_mesh_to_file(const mesh& msh, const char* filepath)
{
    error result = OK;

    FILE* fdst = fopen(filepath, "w");
    if (!fdst)
    {
        return error::FileNotFound;
    }

    save_mesh_attributes_to_file(msh, fdst);
    fclose(fdst);

    return result;
}

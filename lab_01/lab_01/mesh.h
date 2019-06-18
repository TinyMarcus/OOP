#ifndef MESH_H
#define MESH_H

#include <iostream>
#include "maths.h"
#include "errors.h"
#include "controller.h"

struct mesh
{
    bool isLoaded;

    Vector4f* vertices;
    int verticesCount;
    unsigned short* indices;
    int indicesCount;
};

mesh init_mesh();

// Копирование
void copy_mesh_attributes(mesh& dst, const mesh& src);
void copy_mesh(mesh& dst, const mesh& src);

// Выделение памяти
error allocate_mesh_fields(mesh& msh, int verticesCount, int indicesCount);
void delete_mesh(mesh& msh);

// Загрузка данных из файла
void read_indices(mesh& msh, unsigned short& idx0, unsigned short& idx1, error& er, int& ind, FILE* fsrc);
error read_mesh_indices(mesh& msh, FILE* fsrc);
void read_vertices(mesh& msh, Vector4f& vertex, FILE* fsrc, error& er, int& ind);
error read_mesh_vertices(mesh& msh, FILE* fsrc);
error read_mesh_parameters(int& verticesCount, int& indicesCount, FILE* fsrc);
error read_mesh(mesh& model, FILE* fsrc);
error load_mesh_from_file(mesh& msh, const char* filepath);

// Сохранение в файл
void save_mesh_attributes_to_file(const mesh& msh, FILE* fdst);
error save_mesh_to_file(const mesh& msh, const char* filepath);

#endif // MESH_H

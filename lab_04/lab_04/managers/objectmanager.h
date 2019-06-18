#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "iterator/iterator.h"
#include "workers/objecttransformator.h"
#include "exceptions/transformerexception.h"

class ModelManager
{
public:
    ModelManager() = default;
    ~ModelManager() = default;

    void transform(BaseTransformator& trans, const ObjectIter& beg, const ObjectIter& end)
    {
        for (ObjectIter it = beg; it != end; it++)
        {
            if(!(*it))
            {
                throw ObjectTransformingException();
            }

            if ((*it)->is_visible())
            {
                trans.transform((*it));
            }
        }
    }
};

class CameraManager
{
public:
    CameraManager() = default;
    ~CameraManager() = default;

    void transform(BaseTransformator& trans, const ObjectIter& beg, const ObjectIter& end)
    {
        for (ObjectIter it = beg; it != end; it++)
        {
            if (!(*it))
            {
                throw ObjectTransformingException();
            }

            if (!(*it)->is_visible())
            {
                trans.transform((*it));
            }
        }
    }
};

#endif // OBJECTMANAGER_H
